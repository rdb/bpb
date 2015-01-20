// Filename: bpbOpenGLRenderer.h
// Created by: rdb (20Jan15)
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

#ifndef BPBOPENGLRENDERER_H
#define BPBOPENGLRENDERER_H

#include "bpbRenderer.h"

#include "graphicsPipe.h"
#include "graphicsStateGuardian.h"

////////////////////////////////////////////////////////////////////
//       Class : BPBOpenGLRenderer
// Description : This renderer renders into an existing OpenGL
//               context.
////////////////////////////////////////////////////////////////////
struct BPBOpenGLRenderer : public BPBRenderer {
public:
  BPBOpenGLRenderer(int flags);

public:
  virtual void start(const BPB_render_desc *desc);
  virtual void finish();

protected:
  static PT(GraphicsPipe) _pipe;
  PT(GraphicsStateGuardian) _gsg;
};

#endif

