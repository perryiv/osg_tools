
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

#ifndef _OSG_TOOLS_PROPERTIES_VECTOR_3_H_
#define _OSG_TOOLS_PROPERTIES_VECTOR_3_H_

#include "Usul/Properties/Map.h"
#include "Usul/Properties/Vector3.h"

#include "osg/Vec3d"
#include "osg/Vec3f"

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

template <> struct Getter < false, osg::Vec3d >
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
template <> struct Getter < false, osg::Vec3f >
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


///////////////////////////////////////////////////////////////////////////////
//
//  Template helper class with specializations. Add more as needed.
//  https://www.learncpp.com/cpp-tutorial/13-8-partial-template-specialization-for-pointers/
//
///////////////////////////////////////////////////////////////////////////////

template <> struct Require < false, osg::Vec3d >
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
template <> struct Require < false, osg::Vec3f >
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


} // namespace Details
} // namespace Properties
} // namespace Usul


#endif // _OSG_TOOLS_PROPERTIES_VECTOR_3_H_
