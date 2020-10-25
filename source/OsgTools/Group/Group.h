
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

#ifndef _OSG_TOOLS_GROUP_FUNCTIONS_H_
#define _OSG_TOOLS_GROUP_FUNCTIONS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Forward.h"


namespace OsgTools {
namespace Group {


struct OSG_TOOLS_EXPORT GroupImplementation
{
  static void    addAllChildren ( osg::Group *, osg::Group * );
  static void    removeAllChildren ( osg::Group * );
  static void    removeAllOccurances ( osg::Node *, osg::Group * );
};

// Add all children from the one group to the other.
inline void    addAllChildren ( osg::Group *from, osg::Group *to ) { GroupImplementation::addAllChildren ( from, to ); }

// Remove all the children from the node.
inline void    removeAllChildren ( osg::Group *group ) { GroupImplementation::removeAllChildren ( group ); }

// Remove all occurances of the given child from the group.
inline void    removeAllOccurances ( osg::Node *child, osg::Group *group ) { GroupImplementation::removeAllOccurances ( child, group ); }


} // namespace Group
} // namespace OsgTools


#endif // _OSG_TOOLS_GROUP_FUNCTIONS_H_
