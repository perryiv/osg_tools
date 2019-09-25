
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Base class for all builders of primitive shapes.
//
///////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Builders/Primitive.h"

#include "Usul/Math/Random.h"
#include "Usul/Math/Vector3.h"

#include <cstdlib>


namespace OsgTools {
namespace Builders {


///////////////////////////////////////////////////////////////////////////////
//
//  Constructors.
//
///////////////////////////////////////////////////////////////////////////////

Primitive::Primitive() : BaseClass(),
  _center ( 0.0, 0.0, 0.0 ),
  _color  ( 0.5, 0.5, 0.5, 1.0 )
{
}
Primitive::Primitive ( const Options &options ) : BaseClass ( options ),
  _center ( Usul::Properties::get ( options, "center", osg::Vec3d ( 0.0, 0.0, 0.0 ) ) ),
  _color  ( Usul::Properties::get ( options, "color",  osg::Vec4d ( 0.5, 0.5, 0.5, 1.0 ) ) )
{
  if ( "random" == Usul::Properties::get ( options, "color", std::string ( "something" ) ) )
  {
    Usul::Math::Vec3d color;
    Usul::Math::random ( color, 0.2, 0.8 );
    this->setColor ( color[0], color[1], color[2], 1.0 );
  }
}
Primitive::Primitive ( const Options::Values &values ) : BaseClass ( values ),
  _center ( 0.0, 0.0, 0.0 ),
  _color  ( 0.5, 0.5, 0.5, 1.0 )
{
  const Options options ( values );
  _center = Usul::Properties::get ( options, "center", _center );
  _color  = Usul::Properties::get ( options, "color",  _color  );

  if ( "random" == Usul::Properties::get ( options, "color", std::string ( "something" ) ) )
  {
    Usul::Math::Vec3d color;
    Usul::Math::random ( color, 0.2, 0.8 );
    this->setColor ( color[0], color[1], color[2], 1.0 );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Destructor.
//
///////////////////////////////////////////////////////////////////////////////

Primitive::~Primitive()
{
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the center.
//
///////////////////////////////////////////////////////////////////////////////

void Primitive::setCenter ( const osg::Vec3d &center )
{
  _center.set ( center[0], center[1], center[2] );
}
void Primitive::setCenter ( const osg::Vec3f &center )
{
  _center.set ( center[0], center[1], center[2] );
}
void Primitive::setCenter ( double x, double y, double z )
{
  _center.set ( x, y, z );
}
void Primitive::setCenter ( float x, float y, float z )
{
  _center.set ( x, y, z );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the color.
//
///////////////////////////////////////////////////////////////////////////////

void Primitive::setColor ( const osg::Vec4d &color )
{
  _color.set ( color[0], color[1], color[2], color[3] );
}
void Primitive::setColor ( const osg::Vec4f &color )
{
  _color.set ( color[0], color[1], color[2], color[3] );
}
void Primitive::setColor ( double r, double g, double b, double a )
{
  _color.set ( r, g, b, a );
}
void Primitive::setColor ( float r, float g, float b, float a )
{
  _color.set ( r, g, b, a );
}


} // namespace Builders
} // namespace OsgTools
