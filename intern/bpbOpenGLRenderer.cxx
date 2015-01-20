// Filename: bpbOpenGLRenderer.cxx
// Created by:  rdb (20Jan15)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#include "bpbOpenGLRenderer.h"

#include "frameBufferProperties.h"
#include "graphicsEngine.h"
#include "graphicsPipeSelection.h"

PT(GraphicsPipe) BPBOpenGLRenderer::_pipe;

////////////////////////////////////////////////////////////////////
//     Function: BPBOpenGLRenderer::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
BPBOpenGLRenderer::
BPBOpenGLRenderer(int flags) {
  // Select the right pipe.
  if (_pipe == NULL) {
    GraphicsPipeSelection *sel = GraphicsPipeSelection::get_global_ptr();
    sel->print_pipe_types();
    _pipe = sel->make_module_pipe("pandagl");
  }
}

////////////////////////////////////////////////////////////////////
//     Function: BPBOpenGLRenderer::start
//       Access: Public
//  Description: Starts the render.  In foreground mode, this just
//               does initial set-up.  In background mode, it also
//               starts the render in a separate thread.
////////////////////////////////////////////////////////////////////
void BPBOpenGLRenderer::
start(const BPB_render_desc *desc) {
  // _scene set-up yadda yadda

  /*FramebufferProperties fbp;
  fbp.set_srgb_color((flags & BPB_RF_srgb) != 0);*/
}

////////////////////////////////////////////////////////////////////
//     Function: BPBOpenGLRenderer::finish
//       Access: Public
//  Description: Finishes the render.  In foreground mode, this does
//               the entire rendering.  In background mode, it waits
//               for the render to finish.
////////////////////////////////////////////////////////////////////
void BPBOpenGLRenderer::
finish() {

}
