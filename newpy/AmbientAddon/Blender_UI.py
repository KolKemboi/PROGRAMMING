bl_info = {
    "name": "AmbientCG Browser",
    "author": "Kol Kemboi",
    "version": (0, 2, 0),
    "blender": (4, 0, 0),
    "category": "Material",
    "description": "Browse and preview AmbientCG materials with wide icons",
}

import bpy
import os
import json

# Paths (edit these if needed)
CACHE_FILE = os.path.expanduser("~/Documents/programming/python/newpy/AmbientAddon/cache/ambientcg/materials.json")
TEXTURE_DIR = os.path.expanduser("~/Documents/programming/python/newpy/AmbientAddon/cache/textures")


# ---------------------------------------------------------------------
# Utilities
# ---------------------------------------------------------------------
def load_cached_materials():
    if not os.path.exists(CACHE_FILE):
        return []
    with open(CACHE_FILE, "r") as f:
        return json.load(f)


def get_thumbnail(id):
    """Find a .jpg thumbnail for given material id"""
    for ext in [".jpg", ".png", ".jpeg"]:
        path = os.path.join(TEXTURE_DIR, f"{id}{ext}")
        if os.path.exists(path):
            return path
    return None


# ---------------------------------------------------------------------
# Blender Data Structures
# ---------------------------------------------------------------------
class AMBIENTCG_MaterialItem(bpy.types.PropertyGroup):
    name: bpy.props.StringProperty()
    thumbnail_path: bpy.props.StringProperty()


# ---------------------------------------------------------------------
# Panel
# ---------------------------------------------------------------------
class AMBIENTCG_PT_browser(bpy.types.Panel):
    bl_label = "AmbientCG Browser"
    bl_idname = "AMBIENTCG_PT_browser"
    bl_space_type = "VIEW_3D"
    bl_region_type = "UI"
    bl_category = "AmbientCG"

    def draw(self, context):
        layout = self.layout
        scn = context.scene

        layout.use_property_split = False
        layout.use_property_decorate = False

        if not scn.ambientcg_materials:
            layout.label(text="No materials loaded.")
            layout.operator("ambientcg.reload_materials", icon="FILE_REFRESH")
            return

        col = layout.column(align=True)
        col.operator("ambientcg.reload_materials", icon="FILE_REFRESH", text="Reload Materials")

        # Draw material previews
        for mat in scn.ambientcg_materials:
            box = col.box()
            box.scale_y = 8.0  # taller
            thumb_path = mat.thumbnail_path
            if thumb_path and os.path.exists(thumb_path):
                try:
                    image = bpy.data.images.load(thumb_path, check_existing=True)
                    box.template_preview(image, show_buttons=False)
                except:
                    box.label(text="(Preview failed)")
            else:
                box.label(text="No thumbnail available")

            box.label(text=mat.name)


# ---------------------------------------------------------------------
# Operator to reload materials
# ---------------------------------------------------------------------
class AMBIENTCG_OT_reload(bpy.types.Operator):
    """Reload materials from cache"""
    bl_idname = "ambientcg.reload_materials"
    bl_label = "Reload AmbientCG Materials"

    def execute(self, context):
        scn = context.scene
        scn.ambientcg_materials.clear()
        materials = load_cached_materials()
        for m in materials[:30]:
            item = scn.ambientcg_materials.add()
            item.name = m["id"]
            item.thumbnail_path = get_thumbnail(m["id"]) or ""
        self.report({"INFO"}, f"Loaded {len(scn.ambientcg_materials)} materials.")
        return {"FINISHED"}


# ---------------------------------------------------------------------
# Registration
# ---------------------------------------------------------------------
classes = [
    AMBIENTCG_MaterialItem,
    AMBIENTCG_OT_reload,
    AMBIENTCG_PT_browser,
]


def register():
    for cls in classes:
        bpy.utils.register_class(cls)
    bpy.types.Scene.ambientcg_materials = bpy.props.CollectionProperty(type=AMBIENTCG_MaterialItem)
    bpy.types.Scene.ambientcg_index = bpy.props.IntProperty(default=0)

    # Load once
    bpy.ops.ambientcg.reload_materials()


def unregister():
    for cls in reversed(classes):
        bpy.utils.unregister_class(cls)
    del bpy.types.Scene.ambientcg_materials
    del bpy.types.Scene.ambientcg_index


if __name__ == "__main__":
    register()
