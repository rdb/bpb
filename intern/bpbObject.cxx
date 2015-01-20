// Filename: bpbObject.cxx
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

#include "bpbObject.h"

////////////////////////////////////////////////////////////////////
//     Function: BPBObject::set_parent
//       Access: Public
//  Description: Changes the parent object of this object.
////////////////////////////////////////////////////////////////////
INLINE void BPBObject::
set_parent(BPBObject *parent) {
  _parent = parent;
}

////////////////////////////////////////////////////////////////////
//     Function: BPBObject::update
//       Access: Public, Virtual
//  Description: Called by the bridge when the corresponding Blender
//               object might have changed.
////////////////////////////////////////////////////////////////////
void BPBObject::
update(DNA_ID *dna_id) {
  BPBID::update(dna_id);
}
