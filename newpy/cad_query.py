import cadquery as cq
# from cadquery import show_object
from cadquery import *

result = cq.Workplane("XY").box(10, 20, 5)
show(result)  # This launches a popup viewer
