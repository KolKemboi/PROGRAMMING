import os
import json
import random
import requests

CACHE_FILE = "cache/ambientcg/materials.json"
DOWNLOAD_DIR = "cache/textures"

def load_material():
    if not os.path.exists(CACHE_FILE):
        raise FileNotFoundError("Material Cache not found")
    with open(CACHE_FILE, "r") as f:
        return json.load(f)

def download_preview(material):
    os.makedirs(DOWNLOAD_DIR, exist_ok=True)
    url = material["preview"]
    # print(url)
    filename = os.path.join(DOWNLOAD_DIR, f"{material['id']}.jpg")
    print(filename)

    if os.path.exists(filename):
        print(f"file already downloaded {filename}")
        return filename
    print(f"downloading preview for {material['name']}...")
    response = requests.get(url)
    response.raise_for_status()

    with open(filename, "wb") as f:
        f.write(response.content)

    print(f"Saved to {filename}")
    return filename

def download_random_material():
    materials = load_material()
    material = random.choice(materials)
    download_preview(material)

if __name__ == "__main__":
    download_random_material()
    
