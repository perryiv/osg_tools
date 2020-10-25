
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

#include "OsgTools/Group/ForEach.h"

#include "osg/Group"


namespace OsgTools {
namespace Group {


///////////////////////////////////////////////////////////////////////////////
//
//  Call the function for each child of the group.
//
///////////////////////////////////////////////////////////////////////////////

void ForEachImplementation::forEachChild ( osg::Node *node, Callback cb )
{
  if ( nullptr == cb )
  {
    return;
  }

  osg::Group *group = dynamic_cast < osg::Group * > ( node );

  if ( nullptr == group )
  {
    return;
  }

  const unsigned int numChildren = group->getNumChildren();
  for ( unsigned int i = 0; i < numChildren; ++i )
  {
    cb ( group->getChild ( i ) );
  }
}



} // namespace Group
} // namespace OsgTools
