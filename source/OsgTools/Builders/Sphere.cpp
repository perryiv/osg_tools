
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
//  Constructors.
//
///////////////////////////////////////////////////////////////////////////////

Sphere::Sphere() : BaseClass(),
  _radius ( 1.0 )
{
}
Sphere::Sphere ( const Options &options ) : BaseClass ( options ),
  _radius ( Usul::Properties::get ( options, "radius", 1.0 ) )
{
}
Sphere::Sphere ( const Options::Values &values ) : BaseClass ( values ),
  _radius ( 1.0 )
{
  const Options options ( values );
  _radius = Usul::Properties::get ( options, "radius", _radius );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Destructor.
//
///////////////////////////////////////////////////////////////////////////////

Sphere::~Sphere()
{
}


///////////////////////////////////////////////////////////////////////////////
//
//  Build a sphere.
//
///////////////////////////////////////////////////////////////////////////////

osg::Node *Sphere::build()
{
  const osg::Vec3d &center ( this->getCenter() );
  const float radius ( static_cast < float > ( this->getRadius() ) );
  const osg::Vec4f &color ( this->getColor() );

  osg::ref_ptr < osg::Sphere > sphere ( new osg::Sphere ( center, radius ) );
  osg::ref_ptr < osg::ShapeDrawable > shape ( new osg::ShapeDrawable ( sphere ) );
  shape->setColor ( color );
  osg::ref_ptr < osg::Geode > geode ( OSG_TOOLS_FACTORY_CREATE ( osg::Geode ) );
  geode->addDrawable ( shape );

  return geode.release();
}


///////////////////////////////////////////////////////////////////////////////
//
//  Build a sphere.
//
///////////////////////////////////////////////////////////////////////////////

osg::Node *Sphere::build ( const Options &options )
{
  Sphere builder ( options );
  return builder.build();
}
osg::Node *Sphere::build ( const Options::Values &values )
{
  return Sphere::build ( Options ( values ) );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the radius.
//
///////////////////////////////////////////////////////////////////////////////

void Sphere::setRadius ( double radius )
{
  _radius = radius;
}
void Sphere::setRadius ( float radius )
{
  _radius = radius;
}


} // namespace Builders
} // namespace OsgTools
