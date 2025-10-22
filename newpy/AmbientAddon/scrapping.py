import os
import json
import requests
from urllib.parse import urlencode

BASE_URL = "https://ambientcg.com/api/v2/full_json"
CACHE_FILE = "cache/ambientcg/materials.json"


def fetch_ambientcg_data(force_refresh=False):
    """Fetch and cache the first page of materials for offline browsing."""
    os.makedirs(os.path.dirname(CACHE_FILE), exist_ok=True)

    if os.path.exists(CACHE_FILE) and not force_refresh:
        with open(CACHE_FILE, "r") as f:
            print("Loaded materials from cache")
            return json.load(f)

    print("Fetching first page from AmbientCG API...")
    response = requests.get(BASE_URL)
    response.raise_for_status()
    data = response.json()

    assets = data.get("foundAssets", [])
    materials = []
    for asset in assets:
        if asset.get("dataType") != "Material":
            continue

        preview = asset.get("previewImage", {})
        preview_url = (
            preview.get("512-JPG-FFFFFF")
            or preview.get("512-PNG")
            or preview.get("256-JPG-FFFFFF")
            or preview.get("64-JPG-FFFFFF")
        )

        materials.append({
            "id": asset.get("assetId"),
            "name": asset.get("displayName"),
            "category": asset.get("displayCategory"),
            "tags": asset.get("tags", []),
            "preview": preview_url,
            "shortLink": asset.get("shortLink"),
            "downloadCount": asset.get("downloadCount", 0),
        })

    with open(CACHE_FILE, "w") as f:
        json.dump(materials, f, indent=2)

    print(f"Cached {len(materials)} materials to {CACHE_FILE}")
    return materials


def search_ambientcg(query, limit=50):
    """Search AmbientCG live (no cache)."""
    print(f"Searching AmbientCG for '{query}'...")
    params = {
        "q": query,
        "limit": limit,
    }
    url = f"{BASE_URL}?{urlencode(params)}"

    response = requests.get(url)
    response.raise_for_status()
    data = response.json()
    assets = data.get("foundAssets", [])

    materials = []
    for asset in assets:
        if asset.get("dataType") != "Material":
            continue

        preview = asset.get("previewImage", {})
        preview_url = (
            preview.get("512-JPG-FFFFFF")
            or preview.get("512-PNG")
            or preview.get("256-JPG-FFFFFF")
            or preview.get("64-JPG-FFFFFF")
        )

        materials.append({
            "id": asset.get("assetId"),
            "name": asset.get("displayName"),
            "category": asset.get("displayCategory"),
            "tags": asset.get("tags", []),
            "preview": preview_url,
            "shortLink": asset.get("shortLink"),
            "downloadCount": asset.get("downloadCount", 0),
        })

    print(f"Found {len(materials)} materials for '{query}'")
    return materials


if __name__ == "__main__":
    # ✅ First load cache (only first page, unless forced)
    fetch_ambientcg_data(force_refresh=False)

    # 🔍 Then search live
    results = search_ambientcg("wood")
    for mat in results[:5]:
        print(f"{mat['name']} — {mat['preview']}")
