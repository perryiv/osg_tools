
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Test the group functions.
//
////////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Group.h"

// Temporarily disable the warning we get when compiling with -Woverloaded-virtual or -Wall.
#ifdef __GNUC__
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Woverloaded-virtual"
#endif

#include "osg/Geode"

// Put things back where we found them.
#ifdef __GNUC__
# pragma GCC diagnostic pop
#endif

#include "osg/Group"
#include "osg/MatrixTransform"

#include "catch2/catch.hpp"


////////////////////////////////////////////////////////////////////////////////
//
//  Test the math functions.
//
////////////////////////////////////////////////////////////////////////////////

TEST_CASE ( "Working with groups" )
{
  typedef osg::ref_ptr<osg::Group> GroupPtr;
  typedef osg::ref_ptr<osg::Geode> GeodePtr;

  SECTION ( "Can remove all occurances of a child node from a group" )
  {
    // The group and child we keep track of.
    GroupPtr group ( new osg::Group() );
    GeodePtr child ( new osg::Geode() );

    // Add some nodes we don't care about.
    group->addChild ( new osg::Geode() );
    group->addChild ( new osg::Geode() );

    // Add the two nodes we later remove.
    group->addChild ( child );
    group->addChild ( child );

    // Add some more nodes we don't care about.
    group->addChild ( new osg::Geode() );
    group->addChild ( new osg::Geode() );

    // Should have this many children.
    REQUIRE ( 6 == group->getNumChildren() );

    // Remove the child from the group.
    // It has been added twice.
    OsgTools::Group::removeAllOccurances ( child, group );

    // Should have this many children now.
    const unsigned int numChildren = group->getNumChildren();
    REQUIRE ( 4 == numChildren );

    // All the children should be an osg::Geode now.
    for ( unsigned int i = 0; i < numChildren; ++i )
    {
      REQUIRE ( nullptr != dynamic_cast < osg::Geode * > ( group->getChild ( i ) ) );
    }
  }
}
