// Filename: bpbRenderer.h
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

#ifndef BPBRENDERER_H
#define BPBRENDERER_H

#include "bpb_api.h"

class GraphicsEngine;

////////////////////////////////////////////////////////////////////
//       Class : BPBRenderer
// Description : This is the base class for all of the renderer
//               classes.
////////////////////////////////////////////////////////////////////
struct BPBRenderer {
protected:
  BPBRenderer();
  virtual ~BPBRenderer() {};

public:
  virtual void start(const BPB_render_desc *desc)=0;
  virtual void finish()=0;

protected:
  PT(GraphicsEngine) _engine;
};

#endif

