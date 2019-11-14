
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

#include "osg/Vec4d"
#include "osg/Vec4f"

#include <algorithm>
#include <cmath>


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions that see if the vector is finite.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
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
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Convert the vector types.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
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
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Clamp the vectors to the given range.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline void clamp ( osg::Vec4d &v, const double mn, const double mx )
    {
      v[0] = std::clamp ( v[0], mn, mx );
      v[1] = std::clamp ( v[1], mn, mx );
      v[2] = std::clamp ( v[2], mn, mx );
      v[3] = std::clamp ( v[3], mn, mx );
    }
    inline void clamp ( osg::Vec4f &v, const float mn, const float mx )
    {
      v[0] = std::clamp ( v[0], mn, mx );
      v[1] = std::clamp ( v[1], mn, mx );
      v[2] = std::clamp ( v[2], mn, mx );
      v[3] = std::clamp ( v[3], mn, mx );
    }
  }
}


#endif // _OSG_TOOLS_VECTOR_4D_MATH_FUNCTIONS_H_
