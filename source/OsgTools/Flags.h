
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Constants that are bit flags.
//  http://forum.openscenegraph.org/viewtopic.php?t=5445
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_BIT_FLAGS_H_
#define _OSG_TOOLS_BIT_FLAGS_H_


namespace OsgTools
{
  namespace Flags
  {
    const unsigned int VISIBLE  = 0x00000001;
    const unsigned int PICKABLE = 0x00000002;

    // This is a work-around for the counterintuitive way OSG implements
    // NodeVisitor::validNodeMask().
    const unsigned int VISIBLE_AND_PICKABLE = 0x00000004;
  }
}


#endif // _OSG_TOOLS_BIT_FLAGS_H_
