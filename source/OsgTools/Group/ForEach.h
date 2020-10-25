
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2020, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for working with an osg::Group.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_GROUP_FOR_EACH_FUNCTIONS_H_
#define _OSG_TOOLS_GROUP_FOR_EACH_FUNCTIONS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Forward.h"

#include <functional>


namespace OsgTools {
namespace Group {


struct OSG_TOOLS_EXPORT ForEachImplementation
{
  typedef std::function < void ( osg::Node * ) > Callback;
  static void    forEachChild ( osg::Node *, Callback );
};

// The function called for each node.
typedef ForEachImplementation::Callback Callback;

// Call the function for each child of the group.
inline void forEachChild ( osg::Node *node, Callback cb ) { ForEachImplementation::forEachChild ( node, cb ); }

// Call the function for each child of the group that is the specified type.
template < class ChildType >
inline void forEachChildOfType ( osg::Node *scene, std::function < void ( ChildType * ) > cb )
{
  if ( nullptr == cb )
  {
    return;
  }

  forEachChild ( scene, [ &cb ] ( osg::Node *node )
  {
    ChildType *child = dynamic_cast < ChildType * > ( node );
    if ( nullptr != child )
    {
      cb ( child );
    }
  } );
}

} // namespace Group
} // namespace OsgTools


#endif // _OSG_TOOLS_GROUP_FOR_EACH_FUNCTIONS_H_
