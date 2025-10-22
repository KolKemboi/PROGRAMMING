import os
import json
import requests

API_URL = "https://ambientcg.com/api/v2/full_json"
CACHE_FILE = "cache/ambientcg/materials.json"


def fetch_ambientcg_data(force_refresh=False):
    os.makedirs(os.path.dirname(CACHE_FILE), exist_ok=True)

    if os.path.exists(CACHE_FILE) and not force_refresh:
        with open(CACHE_FILE, "r") as f:
            print("loaded")
            return json.load(f)
    print("Fetching data from AmbientCG API....")
    response = requests.get(API_URL)
    response.raise_for_status()
    data = response.json()

    print(type( data ))
    print(data.keys())
    # print(data.get( "foundAssets" ))
    assets = data.get("foundAssets")
    for asset in assets:
        print(type(asset))
        print(asset.keys())
        print(asset)
        break
    # for datum in data:
    #     print(datum)
    #     break
    # materials = [
    #     {
    #         "id": a["assetId"],
    #         "name":a["displayName"],
    #         "categories": a.get("categories", []),
    #         "preview": a.get("previewImage"),
    #         "downloads": a.get("downloadLocations", []),
    #     }
    #     for a in data.get("foundAssets", [])
    #     if a.get("assetType") == "Material"
    # ]
    # 
    # with open(CACHE_FILE, "w") as f:
    #     json.dump(materials, f, indent=2)
    #
    # print(f"Cached {len(materials)} materials to {CACHE_FILE}")
    #
    # return materials


if __name__ == "__main__":
    fetch_ambientcg_data(True)
    # materials = fetch_ambientcg_data()
    # print(f"found {len(materials)} materials")
    # for mat in materials[:10]:
    #     print(mat["name"], mat["preview"])

