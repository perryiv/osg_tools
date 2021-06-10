
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Quaternion math functions.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_QUATERNION_MATH_FUNCTIONS_H_
#define _OSG_TOOLS_QUATERNION_MATH_FUNCTIONS_H_

#include "osg/Quat"

#include <cmath>


namespace Usul {
namespace Math {


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions that see if the vector is finite.
//
///////////////////////////////////////////////////////////////////////////////

inline bool isFinite ( const osg::Quat &q )
{
  return (
    ( true == std::isfinite ( q[0] ) ) &&
    ( true == std::isfinite ( q[1] ) ) &&
    ( true == std::isfinite ( q[2] ) ) &&
    ( true == std::isfinite ( q[3] ) )
  );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Normalize the quaternion. Lifted from gl-matrix.
//
///////////////////////////////////////////////////////////////////////////////

inline void normalize ( const osg::Quat &input, osg::Quat &answer )
{
  const double x = input[0];
  const double y = input[1];
  const double z = input[2];
  const double w = input[3];

  const double len = std::sqrt ( x * x + y * y + z * z + w * w );

  if ( 0.0 == len )
  {
    answer[0] = 0;
    answer[1] = 0;
    answer[2] = 0;
    answer[3] = 0;
    return;
  }

  const double invLen = 1.0 / len;

  answer[0] = x * invLen;
  answer[1] = y * invLen;
  answer[2] = z * invLen;
  answer[3] = w * invLen;
}


///////////////////////////////////////////////////////////////////////////////
//
//  Normalize the quaternion. Lifted from gl-matrix.
//
///////////////////////////////////////////////////////////////////////////////

inline osg::Quat normalize ( const osg::Quat &input )
{
  osg::Quat answer;
  normalize ( input, answer );
  return answer;
}


} // namespace Math
} // namespace Usul


#endif // _OSG_TOOLS_QUATERNION_MATH_FUNCTIONS_H_
