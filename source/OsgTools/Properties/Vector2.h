
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

#ifndef _OSG_TOOLS_PROPERTIES_VECTOR_2_H_
#define _OSG_TOOLS_PROPERTIES_VECTOR_2_H_

#include "Usul/Properties/Map.h"
#include "Usul/Properties/Vector2.h"

#include "osg/Vec2d"
#include "osg/Vec2f"

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

template <> struct Getter < false, osg::Vec2d >
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
template <> struct Getter < false, osg::Vec2f >
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


///////////////////////////////////////////////////////////////////////////////
//
//  Template helper class with specializations. Add more as needed.
//  https://www.learncpp.com/cpp-tutorial/13-8-partial-template-specialization-for-pointers/
//
///////////////////////////////////////////////////////////////////////////////

template <> struct Require < false, osg::Vec2d >
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
template <> struct Require < false, osg::Vec2f >
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


} // namespace Details
} // namespace Properties
} // namespace Usul


#endif // _OSG_TOOLS_PROPERTIES_VECTOR_2_H_
