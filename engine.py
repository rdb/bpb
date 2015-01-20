import bpy
import ctypes

from .bridge import BPB

class Panda3DEngine(bpy.types.RenderEngine):
    bl_idname = 'PANDA3D'
    bl_label = 'Panda3D'
    bl_use_preview = False

    def __init__(self, *args, **kwargs):
        bpy.types.RenderEngine.__init__(self, *args, **kwargs)

        self.bpb_context = BPB.initialize(ctypes.c_int(0))
        self.bpb_renderer = BPB.new_renderer(BPB.RT_gl_viewport, 0)

    def update(self, data, scene):
        """ Blender calls this before render() to let us
        export the scene before actually rendering it. """

        print('update:', self, data, scene)

        for object in scene.objects:
            obj = BPB.new_object(self.bpb_context)
            BPB.object_update(obj, object.as_pointer())

    def render(self, scene):
        """ Render the scene previously exported by update(). """
        print('render:', self, scene)

        BPB.renderer_start(self.bpb_renderer, None)
        BPB.renderer_finish(self.bpb_renderer)

    def preview_update(self, context, id):
        print('preview_update:', self, context, id)

    def preview_render(self):
        print('preview_render:', self)

    def view_update(self, context):
        """ Called by Blender when the scene rendered by the
        viewport has changed. """

        print('view_update:', self, context)

    def view_draw(self, context):
        """ Called by Blender when the viewport should be redrawn. """

        print('view_draw:', self, context)
