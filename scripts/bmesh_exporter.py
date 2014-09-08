#!BPY

"""
Name: 'bMesh Exporter'
Blender: 271
Group: 'Export'
Tooltip: 'bMesh Exporter'
"""

# This example assumes we have a mesh object selected

import bpy


def write_bmesh(context, filepath, use_some_setting):
    data = {}
    data["mesh"]["vertices"] = []

    out = open(filepath, 'w', encoding='utf-8')
    sce = bpy.data.scenes.active
    ob = sce.objects.active
    mesh = ob.getData(mesh=1)
    for vert in mesh.verts:
        out.write( 'v %f %f %f\n' % (vert.co.x, vert.co.y, vert.co.z) )



    out.close()

    return {'FINISHED'}


# ExportHelper is a helper class, defines filename and
# invoke() function which calls the file selector.
from bpy_extras.io_utils import ExportHelper
from bpy.props import StringProperty, BoolProperty, EnumProperty
from bpy.types import Operator


class ExportSomeData(Operator, ExportHelper):
    """This appears in the tooltip of the operator and in the generated docs"""
    bl_idname = "export_test.some_data"  # important since its how bpy.ops.import_test.some_data is constructed
    bl_label = "Export bMesh"

    # ExportHelper mixin class uses this
    filename_ext = ".bmesh"

    filter_glob = StringProperty(
            default="*.bmesh",
            options={'HIDDEN'},
            )

    # List of operator properties, the attributes will be assigned
    # to the class instance from the operator settings before calling.
    use_setting = BoolProperty(
            name="Example Boolean",
            description="Example Tooltip",
            default=True,
            )

    type = EnumProperty(
            name="Example Enum",
            description="Choose between two items",
            items=(('OPT_A', "First Option", "Description one"),
                   ('OPT_B', "Second Option", "Description two")),
            default='OPT_A',
            )

    def execute(self, context):
        return write_bmesh(context, self.filepath, self.use_setting)


# Only needed if you want to add into a dynamic menu
def menu_func_export(self, context):
    self.layout.operator(ExportSomeData.bl_idname, text="bMesh Export Operator")


def register():
    bpy.utils.register_class(ExportSomeData)
    bpy.types.INFO_MT_file_export.append(menu_func_export)


def unregister():
    bpy.utils.unregister_class(ExportSomeData)
    bpy.types.INFO_MT_file_export.remove(menu_func_export)


if __name__ == "__main__":
    register()

    # test call
    bpy.ops.export_test.some_data('INVOKE_DEFAULT')
