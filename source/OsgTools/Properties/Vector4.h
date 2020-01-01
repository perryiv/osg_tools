
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

#ifndef _OSG_TOOLS_PROPERTIES_VECTOR_4_H_
#define _OSG_TOOLS_PROPERTIES_VECTOR_4_H_

#include "Usul/Properties/Map.h"
#include "Usul/Properties/Vector4.h"

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

template <> struct Getter < false, osg::Vec4d >
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
template <> struct Getter < false, osg::Vec4f >
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

template <> struct Require < false, osg::Vec4d >
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
template <> struct Require < false, osg::Vec4f >
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


#endif // _OSG_TOOLS_PROPERTIES_VECTOR_4_H_
