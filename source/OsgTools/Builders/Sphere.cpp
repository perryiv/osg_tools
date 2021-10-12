
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for building a sphere.
//
///////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Builders/Sphere.h"
#include "OsgTools/Factory/Factory.h"
#include "OsgTools/Properties/Vector3.h"
#include "OsgTools/Properties/Vector4.h"

#include "Usul/Algorithms/Sphere.h"
#include "Usul/Math/Random.h"
#include "Usul/Math/Vector3.h"

#include "osg/Geometry"
#include "osg/ref_ptr"
#include "osg/ShapeDrawable"

#include <vector>


namespace OsgTools {
namespace Builders {


///////////////////////////////////////////////////////////////////////////////
//
//  Get the color, or make one.
//
///////////////////////////////////////////////////////////////////////////////

namespace Details
{
  inline osg::Vec4f getColor ( const Sphere::Options &options )
  {
    if ( "random" == Usul::Properties::get ( options, "color", std::string ( "something" ) ) )
    {
      Usul::Math::Vec3f c;
      Usul::Math::random ( c, 0.2f, 0.8f );
      return osg::Vec4f ( c[0], c[1], c[2], 1.0f );
    }

    return Usul::Properties::get ( options, "color", osg::Vec4f ( 0.5f, 0.5f, 0.5f, 1.0f ) );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Build a sphere.
//
///////////////////////////////////////////////////////////////////////////////

osg::Node *Sphere::build ( const Options &options )
{
  // Get the input.
  const osg::Vec3f center = Usul::Properties::get ( options, "center", osg::Vec3f ( 0.0f, 0.0f, 0.0f ) );
  const float radius = Usul::Properties::get ( options, "radius", 1.0f );

  // Needed below.
  osg::ref_ptr < osg::Node > answer;

  // Are we supposed to make a subdivision sphere?
  if ( true == options.has ( "subdivisions" ) )
  {
    // Get the number of subdivisions.
    int subdivisions = Usul::Properties::require < int > ( options, "subdivisions" );

    // Make sure we are not asked to subdivide a negative number of times.
    subdivisions = ( ( subdivisions < 0 ) ? 0 : subdivisions );

    // Shortcut.
    const unsigned int depth = static_cast < unsigned int > ( subdivisions );

    // Make the containers.
    osg::ref_ptr < osg::Vec3Array > points = new osg::Vec3Array;
    osg::ref_ptr < osg::Vec3Array > normals = new osg::Vec3Array;
    std::vector < unsigned int > indices;

    // Make colors if we should.
    osg::ref_ptr < osg::Vec4Array > colors;
    osg::Vec4f color = Details::getColor ( options );
    if ( true == options.has ( "color" ) )
    {
      colors = new osg::Vec4Array;
    }

    // Reserve space in the containers.
    Usul::Algorithms::Sphere::reserve ( depth, [ &points, &normals, &colors, &indices ]
      ( unsigned int numPoints, unsigned int numIndices )
    {
      points->reserve ( numPoints );
      normals->reserve ( numPoints );
      indices.reserve ( numIndices );

      if ( true == colors.valid() )
      {
        colors->reserve ( numPoints );
      }
    } );

    // Fill the arrays.
    Usul::Algorithms::Sphere::generate < float > ( depth, [ &center, radius, &color, &points, &normals, &colors, &indices ] (
      float x1, float y1, float z1,
      float x2, float y2, float z2,
      float x3, float y3, float z3,
      const unsigned int i1,
      const unsigned int i2,
      const unsigned int i3 )
    {
      const osg::Vec3f v1 ( x1, y1, z1 );
      const osg::Vec3f v2 ( x2, y2, z2 );
      const osg::Vec3f v3 ( x3, y3, z3 );

      points->push_back ( center + ( v1 * radius ) );
      points->push_back ( center + ( v2 * radius ) );
      points->push_back ( center + ( v3 * radius ) );

      normals->push_back ( v1 );
      normals->push_back ( v2 );
      normals->push_back ( v3 );

      if ( true == colors.valid() )
      {
        colors->push_back ( color );
        colors->push_back ( color );
        colors->push_back ( color );
      }

      indices.push_back ( i1 );
      indices.push_back ( i2 );
      indices.push_back ( i3 );
    } );

    // Make the geometry. This is what we return.
    osg::ref_ptr < osg::Geometry > geom = OSG_TOOLS_FACTORY_CREATE ( osg::Geometry );
    answer = geom;

    // Add the points and normals.
    geom->setVertexArray ( points.get() );
    geom->setNormalArray ( normals.get() );

    // Add colors if we have them.
    if ( true == colors.valid() )
    {
      geom->setColorArray ( colors.get() );
      geom->setColorBinding ( osg::Geometry::BIND_PER_VERTEX );
    }

    // Add the primitive set.
    if ( false == indices.empty() )
    {
      geom->addPrimitiveSet ( new osg::DrawElementsUInt (
        osg::PrimitiveSet::TRIANGLES, static_cast < unsigned int > ( indices.size() ),
        &indices[0]
      ) );
    }
  }

  else
  {
    osg::ref_ptr < osg::Sphere > sphere = new osg::Sphere ( center, radius );
    osg::ref_ptr < osg::ShapeDrawable > shape = new osg::ShapeDrawable ( sphere );
    answer = shape;

    if ( true == options.has ( "color" ) )
    {
      shape->setColor ( Details::getColor ( options ) );
    }
  }

  return answer.release();
}
osg::Node *Sphere::build ( const Options::Values &values )
{
  return Sphere::build ( Options ( values ) );
}


} // namespace Builders
} // namespace OsgTools
