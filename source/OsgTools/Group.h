
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for working with an osg::Group.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_GROUP_CLASS_H_
#define _OSG_TOOLS_GROUP_CLASS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Declarations.h"


namespace OsgTools {


struct OSG_TOOLS_EXPORT Group
{
  // Add all children from the one group to the other.
  static void           addAllChildren ( osg::Group *from, osg::Group *to );

  // Remove all the children from the node.
  static void           removeAllChildren ( osg::Group *group );

  // Remove all occurances of the given child from the group.
  static void           removeAllOccurances ( osg::Node *child, osg::Group *group );
};


} // namespace OsgTools


#endif // _OSG_TOOLS_GROUP_CLASS_H_
