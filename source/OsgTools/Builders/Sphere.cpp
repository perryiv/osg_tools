
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Functions for building a sphere.
//
///////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Builders/Sphere.h"

#include "osg/Geode"
#include "osg/Group"
#include "osg/Material"
#include "osg/PolygonMode"
#include "osg/ref_ptr"
#include "osg/ShapeDrawable"


namespace OsgTools {
namespace Builders {


///////////////////////////////////////////////////////////////////////////////
//
//  Build a sphere.
//
///////////////////////////////////////////////////////////////////////////////

osg::Geode *sphere ( const osg::Vec3f &center, float radius )
{
  const float randMax = static_cast < float > ( RAND_MAX );
  const float r = static_cast < float > ( std::rand() ) / randMax;
  const float g = static_cast < float > ( std::rand() ) / randMax;
  const float b = static_cast < float > ( std::rand() ) / randMax;

  osg::ref_ptr < osg::Sphere > sphere ( new osg::Sphere ( center, radius ) );
  osg::ref_ptr < osg::ShapeDrawable > sd ( new osg::ShapeDrawable ( sphere ) );
  sd->setColor ( osg::Vec4 ( r, g, b, 1.0f ) );
  osg::ref_ptr < osg::Geode > geode ( new osg::Geode() );
  geode->addDrawable ( sd );

  return geode.release();
}


} // namespace Builders
} // namespace OsgTools
