// Filename: bpbMesh.cxx
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

#include "bpbMesh.h"

////////////////////////////////////////////////////////////////////
//     Function: BPBMesh::update
//       Access: Public, Virtual
//  Description: Called by the bridge when the corresponding Blender
//               object might have changed.
////////////////////////////////////////////////////////////////////
void BPBMesh::
update(DNA_ID *dna_id) {
  BPBObjectData::update(dna_id);
}

////////////////////////////////////////////////////////////////////
//     Function: BPBMesh::update_node
//       Access: Public, Virtual
//  Description: This is called by the base implementation of update()
//               for each object that references this data block.
//               This method should be overridden to make whatever
//               changes need to be done to the node.
////////////////////////////////////////////////////////////////////
void BPBMesh::
update_node(PandaNode *node, DNA_ID *dna_id) {
}
