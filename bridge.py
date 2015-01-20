__all__ = ['BPB']

import ctypes
import os
import sys

# The following is needed to prevent Panda from calling any Python functions.
os.environ['PANDA_INCOMPATIBLE_PYTHON'] = '1'

dir = os.path.dirname(__file__)
if not dir:
    dir = './'

if sys.platform == 'win32':
    cdll = ctypes.CDLL(os.path.join(dir, 'bpb.dll'))
else:
    cdll = ctypes.CDLL(os.path.join(dir, 'bpb.so'))

# Just for convenient scoping
class BPB(object):
    class BPB_context(ctypes.Structure):
        pass

    class BPB_object(ctypes.Structure):
        pass

    class BPB_object_data(ctypes.Structure):
        pass

    class BPB_renderer(ctypes.Structure):
        pass

    class BPB_renderer_desc(ctypes.Structure):
        pass

    # Enum values for new_renderer
    RT_window = 1
    RT_gl_viewport = 2
    RT_texture = 3

    initialize = cdll.BPB_initialize
    initialize.restype = ctypes.POINTER(BPB_context)
    initialize.argtypes = [ctypes.c_int]

    new_object = cdll.BPB_new_object
    new_object.restype = ctypes.POINTER(BPB_object)
    new_object.argtypes = [ctypes.POINTER(BPB_context)]

    object_update = cdll.BPB_object_update
    object_update.restype = None
    object_update.argtypes = [ctypes.POINTER(BPB_object), ctypes.c_void_p]

    new_renderer = cdll.BPB_new_renderer
    new_renderer.restype = ctypes.POINTER(BPB_renderer)
    new_renderer.argtypes = [ctypes.c_int, ctypes.c_int]

    renderer_start = cdll.BPB_renderer_start
    renderer_start.restype = None
    renderer_start.argtypes = [ctypes.POINTER(BPB_renderer),
                               ctypes.POINTER(BPB_renderer_desc)]

    renderer_finish = cdll.BPB_renderer_finish
    renderer_finish.restype = None
    renderer_finish.argtypes = [ctypes.POINTER(BPB_renderer)]

if __name__ == '__main__':
    print(BPB.initialize(0))
