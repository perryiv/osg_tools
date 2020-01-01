
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

#ifndef _OSG_TOOLS_PROPERTIES_4_BY_4_MATRIX_H_
#define _OSG_TOOLS_PROPERTIES_4_BY_4_MATRIX_H_

#include "Usul/Properties/Map.h"
#include "Usul/Properties/Matrix44.h"

#include "OsgTools/Traits/Matrix44.h"

#include "osg/Matrixd"
#include "osg/Matrixf"

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

template <> struct Getter < false, osg::Matrixd >
{
  static osg::Matrixd get ( const Map &m, const std::string &name, const osg::Matrixd &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixd, osg::Matrixd );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixf, osg::Matrixd );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44d, osg::Matrixd );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44f, osg::Matrixd );

    return defaultValue;
  }
};
template <> struct Getter < false, osg::Matrixf >
{
  static osg::Matrixf get ( const Map &m, const std::string &name, const osg::Matrixf &defaultValue )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      return defaultValue;
    }

    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixf, osg::Matrixf );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixd, osg::Matrixf );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44d, osg::Matrixf );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44f, osg::Matrixf );

    return defaultValue;
  }
};


///////////////////////////////////////////////////////////////////////////////
//
//  Template helper class with specializations. Add more as needed.
//  https://www.learncpp.com/cpp-tutorial/13-8-partial-template-specialization-for-pointers/
//
///////////////////////////////////////////////////////////////////////////////

template <> struct Require < false, osg::Matrixd >
{
  static osg::Matrixd get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixd, osg::Matrixd );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixf, osg::Matrixd );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44d, osg::Matrixd );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44f, osg::Matrixd );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};
template <> struct Require < false, osg::Matrixf >
{
  static osg::Matrixf get ( const Map &m, const std::string &name )
  {
    const Object *obj = m.object ( name );
    if ( nullptr == obj )
    {
      throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is not in the map" ) );
    }

    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixf, osg::Matrixf );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( osg::Matrixd, osg::Matrixf );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44d, osg::Matrixf );
    USUL_PROPERTIES_MAP_CONVERT_MATRIX_44 ( Usul::Math::Matrix44f, osg::Matrixf );

    throw std::runtime_error ( Usul::Strings::format ( "Property '", name, "' is an unknown type" ) );
  }
};


} // namespace Details
} // namespace Properties
} // namespace Usul


#endif // _OSG_TOOLS_PROPERTIES_4_BY_4_MATRIX_H_
