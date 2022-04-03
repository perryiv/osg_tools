
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2022, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for building a scene with simple shapes.
//
///////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Builders/Shapes.h"
#include "OsgTools/Builders/Sphere.h"

#include "osg/Group"
#include "osg/Material"
#include "osg/ref_ptr"
#include "osg/Vec3f"
#include "osg/ShapeDrawable"

USUL_DEFINE_MAKE_PROPERTY_FUNCTION_SHORTCUT // mp


namespace OsgTools {
namespace Builders {


///////////////////////////////////////////////////////////////////////////////
//
//  Build a cylinder.
//
///////////////////////////////////////////////////////////////////////////////

namespace { namespace Details
{
  inline osg::Drawable *buildCylinder ( const osg::Vec3f &center, float radius, float height )
  {
    const float randMax = static_cast < float > ( RAND_MAX );
    const float r = static_cast < float > ( std::rand() ) / randMax;
    const float g = static_cast < float > ( std::rand() ) / randMax;
    const float b = static_cast < float > ( std::rand() ) / randMax;

    osg::ref_ptr < osg::Cylinder > cylinder ( new osg::Cylinder ( center, radius, height ) );
    osg::ref_ptr < osg::ShapeDrawable > sd ( new osg::ShapeDrawable ( cylinder ) );
    sd->setColor ( osg::Vec4 ( r, g, b, 1.0f ) );

    return sd.release();
  }
} }


///////////////////////////////////////////////////////////////////////////////
//
//  Build a scene with simple shapes.
//
///////////////////////////////////////////////////////////////////////////////

osg::Node *Shapes::build ( const Options &options )
{
  // Get the input.
  const unsigned int num = Usul::Properties::get ( options, "num", 10u );
  const float size = Usul::Properties::get ( options, "size", 10.0f );

  // The group that holds everything.
  osg::ref_ptr < osg::Group > answer ( new osg::Group );

  osg::StateSet* stateSet = answer->getOrCreateStateSet();
  osg::Material* material = new osg::Material;
  material->setColorMode ( osg::Material::AMBIENT_AND_DIFFUSE );
  stateSet->setAttributeAndModes ( material, osg::StateAttribute::ON );

  // The center of each shape.
  osg::Vec3f center ( 0.0f, 0.0f, 0.0f );

  // Loop through the rows.
  for ( unsigned int i = 0; i < num; ++i )
  {
    osg::ref_ptr < osg::Group > gi ( new osg::Group );
    answer->addChild ( gi.get() );
    center[0] = 2.0f * size * static_cast < float > ( i );
    for ( unsigned int j = 0; j < num; ++j )
    {
      osg::ref_ptr < osg::Group > gj ( new osg::Group );
      gi->addChild ( gj.get() );
      center[1] = 2.0f * size * static_cast < float > ( j );
      for ( unsigned int k = 0; k < num; ++k )
      {
        center[2] = 2.0f * size * static_cast < float > ( k );

        if ( 0 == ( k % 2 ) )
        {
          gj->addChild ( OsgTools::Builders::Sphere::build ( {
            { "center", mp ( center ) },
            { "radius", mp ( 0.5f * 1.2f * size ) },
            { "color",  mp ( "random" ) }
          } ) );
        }
        else
        {
          gj->addChild ( Details::buildCylinder ( center, 0.5f * size, size ) );
        }
      }
    }
  }

  // Return the group.
  return answer.release();
}
osg::Node *Shapes::build ( const Options::Values &values )
{
  return Shapes::build ( Options ( values ) );
}


} // namespace Builders
} // namespace OsgTools
