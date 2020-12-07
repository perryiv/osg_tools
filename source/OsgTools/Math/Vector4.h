
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Vector4 math functions.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_VECTOR_4D_MATH_FUNCTIONS_H_
#define _OSG_TOOLS_VECTOR_4D_MATH_FUNCTIONS_H_

#include "Usul/Math/Vector4.h"
#include "Usul/Math/Base.h"

#include "osg/Vec4d"
#include "osg/Vec4f"

#include <algorithm>
#include <cmath>


namespace Usul {
namespace Math {


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions that see if the vector is finite.
//
///////////////////////////////////////////////////////////////////////////////

inline bool isFinite ( const osg::Vec4d &v )
{
  return (
    ( true == std::isfinite ( v[0] ) ) &&
    ( true == std::isfinite ( v[1] ) ) &&
    ( true == std::isfinite ( v[2] ) ) &&
    ( true == std::isfinite ( v[3] ) )
  );
}
inline bool isFinite ( const osg::Vec4f &v )
{
  return (
    ( true == std::isfinite ( v[0] ) ) &&
    ( true == std::isfinite ( v[1] ) ) &&
    ( true == std::isfinite ( v[2] ) ) &&
    ( true == std::isfinite ( v[3] ) )
  );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Convert the vector types.
//
///////////////////////////////////////////////////////////////////////////////

inline osg::Vec4d convert ( const Usul::Math::Vec4d &v )
{
  return osg::Vec4d ( v[0], v[1], v[2], v[3] );
}
inline osg::Vec4f convert ( const Usul::Math::Vec4f &v )
{
  return osg::Vec4f ( v[0], v[1], v[2], v[3] );
}
inline Usul::Math::Vec4d convert ( const osg::Vec4d &v )
{
  return Usul::Math::Vec4d ( v[0], v[1], v[2], v[3] );
}
inline Usul::Math::Vec4f convert ( const osg::Vec4f &v )
{
  return Usul::Math::Vec4f ( v[0], v[1], v[2], v[3] );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Clamp the vectors to the given range.
//
///////////////////////////////////////////////////////////////////////////////

inline void clamp ( osg::Vec4d &v, const double mn, const double mx )
{
  typedef osg::Vec3d::value_type value_type;
  v[0] = Usul::Math::clamp < value_type > ( v[0], mn, mx );
  v[1] = Usul::Math::clamp < value_type > ( v[1], mn, mx );
  v[2] = Usul::Math::clamp < value_type > ( v[2], mn, mx );
  v[3] = Usul::Math::clamp < value_type > ( v[3], mn, mx );
}
inline void clamp ( osg::Vec4f &v, const float mn, const float mx )
{
  typedef osg::Vec4f::value_type value_type;
  v[0] = Usul::Math::clamp < value_type > ( v[0], mn, mx );
  v[1] = Usul::Math::clamp < value_type > ( v[1], mn, mx );
  v[2] = Usul::Math::clamp < value_type > ( v[2], mn, mx );
  v[3] = Usul::Math::clamp < value_type > ( v[3], mn, mx );
}


} // namespace Math
} // namespace Usul


#endif // _OSG_TOOLS_VECTOR_4D_MATH_FUNCTIONS_H_
