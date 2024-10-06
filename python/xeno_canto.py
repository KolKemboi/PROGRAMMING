import requests
import os
import urllib.request

api_url = "https://www.xeno-canto.org/api/2/recordings"

def show_species(bird_name):
    query_params = {"query": bird_name}
    response = requests.get(api_url, params=query_params)

    if response.status_code != 200:
        print("Error fetching data.")
        return None

    data = response.json()
    bird_recordings = data.get('recordings', [])

    if not bird_recordings:
        print(f"No recordings found for: {bird_name}")
        return None

    unique_species = {rec['en'] for rec in bird_recordings}
    species_list = list(unique_species)

    if not species_list:
        print("No species found.")
        return None

    print("Available bird species:")
    for idx, species in enumerate(species_list, start=1):
        print(f"{idx}. {species}")

    return species_list

def download_bird_audio(selected_species):
    query_params = {"query": selected_species}
    response = requests.get(api_url, params=query_params)

    if response.status_code != 200:
        print("Error fetching data.")
        return

    data = response.json()
    bird_recordings = data.get('recordings', [])

    if not bird_recordings:
        print(f"No recordings found for: {selected_species}")
        return

    folder_name = selected_species.replace(" ", "_")
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)

    print(f"Found {len(bird_recordings)} recordings. Downloading...")
    for idx, rec in enumerate(bird_recordings, start=1):
        if "file" in rec:
            audio_url = rec['file']
            if not audio_url.startswith("https://"):
                audio_url = f"https:{audio_url}"
            file_name = os.path.join(folder_name, f"{selected_species.replace(' ', '_')}_{idx}.mp3")

            try:
                print(f"Downloading {audio_url} as {file_name}...")
                urllib.request.urlretrieve(audio_url, file_name)
                print(f"Downloaded {file_name}")
            except Exception as e:
                print(f"Failed to download {audio_url}: {e}")
        else:
            print(f"No audio file found for recording {idx}")

    print(f"Download complete. Files saved in {folder_name} folder.")

if __name__ == "__main__":
    bird_search = input("Enter a bird species to search: ").strip()
    species_list = show_species(bird_search)

    if species_list:
        selection = int(input("Choose a bird species by entering its number: ").strip())
        if 1 <= selection <= len(species_list):
            chosen_species = species_list[selection - 1]
            download_bird_audio(chosen_species)
        else:
            print("Invalid choice. Please try again.")
