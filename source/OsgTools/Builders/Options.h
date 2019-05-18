
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Functions for getting the options.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_BUILDERS_OPTIONS_H_
#define _OSG_TOOLS_BUILDERS_OPTIONS_H_

#include "OsgTools/Forward.h"

#include "Usul/Math/Vector3.h"
#include "Usul/Math/Vector4.h"
#include "Usul/Tools/Properties.h"

#include "osg/Vec3d"
#include "osg/Vec3f"

#include <type_traits>


namespace OsgTools {
namespace Builders {


///////////////////////////////////////////////////////////////////////////////
//
//  Get the number.
//
///////////////////////////////////////////////////////////////////////////////

template < class NumberType, class MapType >
inline NumberType getNumber ( const MapType &options, const std::string &name, const NumberType &defaultValue )
{
  static_assert ( std::is_floating_point < NumberType >::value, "Not a floating point number" );
  if ( Usul::Tools::Properties::has < NumberType > ( options, name ) )
  {
    return Usul::Tools::Properties::require < NumberType > ( options, name );
  }
  if ( Usul::Tools::Properties::has < float > ( options, name ) )
  {
    return static_cast < NumberType > ( Usul::Tools::Properties::require < float > ( options, name ) );
  }
  if ( Usul::Tools::Properties::has < double > ( options, name ) )
  {
    return static_cast < NumberType > ( Usul::Tools::Properties::require < double > ( options, name ) );
  }
  if ( Usul::Tools::Properties::has < long double > ( options, name ) )
  {
    return static_cast < NumberType > ( Usul::Tools::Properties::require < long double > ( options, name ) );
  }
  return defaultValue;
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the 3D vector.
//
///////////////////////////////////////////////////////////////////////////////

template < class VecType, class MapType >
inline VecType getVec3 ( const MapType &options, const std::string &name, const VecType &defaultValue )
{
  typedef typename VecType::value_type ValueType;
  static_assert ( std::is_floating_point < ValueType >::value, "Not a floating point number" );
  if ( Usul::Tools::Properties::has < VecType > ( options, name ) )
  {
    return Usul::Tools::Properties::require < VecType > ( options, name );
  }
  if ( Usul::Tools::Properties::has < osg::Vec3d > ( options, name ) )
  {
    const osg::Vec3d v ( Usul::Tools::Properties::require < osg::Vec3d > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] )
    );
  }
  if ( Usul::Tools::Properties::has < osg::Vec3f > ( options, name ) )
  {
    const osg::Vec3f v ( Usul::Tools::Properties::require < osg::Vec3f > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] )
    );
  }
  if ( Usul::Tools::Properties::has < Usul::Math::Vec3d > ( options, name ) )
  {
    const Usul::Math::Vec3d v ( Usul::Tools::Properties::require < Usul::Math::Vec3d > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] )
    );
  }
  if ( Usul::Tools::Properties::has < Usul::Math::Vec3f > ( options, name ) )
  {
    const Usul::Math::Vec3f v ( Usul::Tools::Properties::require < Usul::Math::Vec3f > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] )
    );
  }
  return defaultValue;
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the 4D vector.
//
///////////////////////////////////////////////////////////////////////////////

template < class VecType, class MapType >
inline VecType getVec4 ( const MapType &options, const std::string &name, const VecType &defaultValue )
{
  typedef typename VecType::value_type ValueType;
  static_assert ( std::is_floating_point < ValueType >::value, "Not a floating point number" );
  if ( Usul::Tools::Properties::has < VecType > ( options, name ) )
  {
    return Usul::Tools::Properties::require < VecType > ( options, name );
  }
  if ( Usul::Tools::Properties::has < osg::Vec4d > ( options, name ) )
  {
    const osg::Vec4d v ( Usul::Tools::Properties::require < osg::Vec4d > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] ),
      static_cast < ValueType > ( v[3] )
    );
  }
  if ( Usul::Tools::Properties::has < osg::Vec4f > ( options, name ) )
  {
    const osg::Vec4f v ( Usul::Tools::Properties::require < osg::Vec4f > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] ),
      static_cast < ValueType > ( v[3] )
    );
  }
  if ( Usul::Tools::Properties::has < Usul::Math::Vec4d > ( options, name ) )
  {
    const Usul::Math::Vec4d v ( Usul::Tools::Properties::require < Usul::Math::Vec4d > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] ),
      static_cast < ValueType > ( v[3] )
    );
  }
  if ( Usul::Tools::Properties::has < Usul::Math::Vec4f > ( options, name ) )
  {
    const Usul::Math::Vec4f v ( Usul::Tools::Properties::require < Usul::Math::Vec4f > ( options, name ) );
    return VecType (
      static_cast < ValueType > ( v[0] ),
      static_cast < ValueType > ( v[1] ),
      static_cast < ValueType > ( v[2] ),
      static_cast < ValueType > ( v[3] )
    );
  }
  return defaultValue;
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the string.
//
///////////////////////////////////////////////////////////////////////////////

template < class StringType, class MapType >
inline StringType getString ( const MapType &options, const std::string &name, const StringType &defaultValue )
{
  if ( Usul::Tools::Properties::has < StringType > ( options, name ) )
  {
    return Usul::Tools::Properties::require < StringType > ( options, name );
  }
  if ( Usul::Tools::Properties::has < std::string > ( options, name ) )
  {
    return static_cast < StringType > ( Usul::Tools::Properties::require < std::string > ( options, name ) );
  }
  return defaultValue;
}


} // namespace Builders
} // namespace OsgTools


#endif // _OSG_TOOLS_BUILDERS_OPTIONS_H_
