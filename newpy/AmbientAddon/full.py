import os
import json
import random
import requests

CACHE_FILE = "cache/ambientcg/materials.json"
DOWNLOAD_DIR = "downloads"
RESOLUTIONS = ["1K", "2K", "4K"]
FORMATS = ["JPG", "PNG"]


def load_materials():
    if not os.path.exists(CACHE_FILE):
        raise FileNotFoundError("⚠️ Material cache not found. Run fetch_ambientcg_data() first.")
    with open(CACHE_FILE, "r") as f:
        return json.load(f)


def find_valid_download(asset_id):
    """Try all common combinations to find a working ZIP URL."""
    base_url = "https://ambientcg.com/get?file="
    for res in RESOLUTIONS:
        for fmt in FORMATS:
            url = f"{base_url}{asset_id}_{res}-{fmt}.zip"
            head = requests.head(url)
            if head.status_code == 200:
                print(f"✅ Found: {url}")
                return url
            # AmbientCG sometimes redirects 302 to S3 – treat as valid
            if head.status_code in (301, 302):
                print(f"✅ Redirected (valid): {url}")
                return url
    return None


def download_zip(asset_id, url):
    os.makedirs(DOWNLOAD_DIR, exist_ok=True)
    filename = os.path.join(DOWNLOAD_DIR, f"{asset_id}.zip")

    if os.path.exists(filename):
        print(f"✅ Already downloaded: {filename}")
        return filename

    print(f"⬇️ Downloading {asset_id} from {url}")
    with requests.get(url, stream=True) as r:
        r.raise_for_status()
        with open(filename, "wb") as f:
            for chunk in r.iter_content(chunk_size=8192):
                f.write(chunk)

    print(f"✅ Saved to {filename}")
    return filename


def download_random_material():
    materials = load_materials()
    mat = random.choice(materials)
    asset_id = mat["id"].strip()
    print(f"🎨 Selected: {mat['name']} ({asset_id})")

    url = find_valid_download(asset_id)
    if not url:
        print(f"⚠️ No ZIP file found for {asset_id}")
        return

    download_zip(asset_id, url)


if __name__ == "__main__":
    download_random_material()
