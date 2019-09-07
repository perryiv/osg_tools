
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Template specializations to make Usul's property map work with osg classes.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_PROPERTIES_MAP_H_
#define _OSG_TOOLS_PROPERTIES_MAP_H_

#include "Usul/Properties/Map.h"
#include "Usul/Properties/Matrix44.h"
#include "Usul/Properties/Vector2.h"
#include "Usul/Properties/Vector3.h"
#include "Usul/Properties/Vector4.h"

#include "osg/Matrixd"
#include "osg/Matrixf"
#include "osg/Vec2d"
#include "osg/Vec2f"
#include "osg/Vec3d"
#include "osg/Vec3f"
#include "osg/Vec4d"
#include "osg/Vec4f"

#include <type_traits>


namespace Usul {
namespace Properties {
namespace Details {


///////////////////////////////////////////////////////////////////////////////
//
//  Template helper class with specializations. Add more as needed.
//  https://www.learncpp.com/cpp-tutorial/13-8-partial-template-specialization-for-pointers/
//
///////////////////////////////////////////////////////////////////////////////

template <> struct Getter < osg::Vec2d >
{
  static osg::Vec2d get ( const Map &m, const std::string &name, const osg::Vec2d &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2d, osg::Vec2d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2f, osg::Vec2d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2d, osg::Vec2d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2f, osg::Vec2d );

    return defaultValue;
  }
};
template <> struct Getter < osg::Vec3d >
{
  static osg::Vec3d get ( const Map &m, const std::string &name, const osg::Vec3d &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3d, osg::Vec3d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3f, osg::Vec3d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3d, osg::Vec3d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3f, osg::Vec3d );

    return defaultValue;
  }
};
template <> struct Getter < osg::Vec4d >
{
  static osg::Vec4d get ( const Map &m, const std::string &name, const osg::Vec4d &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4d, osg::Vec4d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4f, osg::Vec4d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4d, osg::Vec4d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4f, osg::Vec4d );

    return defaultValue;
  }
};
template <> struct Getter < osg::Vec2f >
{
  static osg::Vec2f get ( const Map &m, const std::string &name, const osg::Vec2f &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2f, osg::Vec2f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2d, osg::Vec2f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2d, osg::Vec2f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2f, osg::Vec2f );

    return defaultValue;
  }
};
template <> struct Getter < osg::Vec3f >
{
  static osg::Vec3f get ( const Map &m, const std::string &name, const osg::Vec3f &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3f, osg::Vec3f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3d, osg::Vec3f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3d, osg::Vec3f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3f, osg::Vec3f );

    return defaultValue;
  }
};
template <> struct Getter < osg::Vec4f >
{
  static osg::Vec4f get ( const Map &m, const std::string &name, const osg::Vec4f &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4f, osg::Vec4f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4d, osg::Vec4f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4d, osg::Vec4f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4f, osg::Vec4f );

    return defaultValue;
  }
};


///////////////////////////////////////////////////////////////////////////////
//
//  Template helper class with specializations. Add more as needed.
//  https://www.learncpp.com/cpp-tutorial/13-8-partial-template-specialization-for-pointers/
//
///////////////////////////////////////////////////////////////////////////////

template <> struct Require < osg::Vec2d >
{
  static osg::Vec2d get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2d, osg::Vec2d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2f, osg::Vec2d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2d, osg::Vec2d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2f, osg::Vec2d );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};
template <> struct Require < osg::Vec3d >
{
  static osg::Vec3d get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3d, osg::Vec3d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3f, osg::Vec3d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3d, osg::Vec3d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3f, osg::Vec3d );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};
template <> struct Require < osg::Vec4d >
{
  static osg::Vec4d get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4d, osg::Vec4d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4f, osg::Vec4d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4d, osg::Vec4d );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4f, osg::Vec4d );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};
template <> struct Require < osg::Vec2f >
{
  static osg::Vec2f get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2f, osg::Vec2f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( osg::Vec2d, osg::Vec2f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2d, osg::Vec2f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_2 ( Usul::Math::Vec2f, osg::Vec2f );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};
template <> struct Require < osg::Vec3f >
{
  static osg::Vec3f get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3f, osg::Vec3f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( osg::Vec3d, osg::Vec3f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3d, osg::Vec3f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_3 ( Usul::Math::Vec3f, osg::Vec3f );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};
template <> struct Require < osg::Vec4f >
{
  static osg::Vec4f get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4f, osg::Vec4f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( osg::Vec4d, osg::Vec4f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4d, osg::Vec4f );
    USUL_PROPERTIES_MAP_CONVERT_VECTOR_4 ( Usul::Math::Vec4f, osg::Vec4f );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};


} // namespace Details
} // namespace Properties
} // namespace Usul


#endif // _OSG_TOOLS_PROPERTIES_MAP_H_
