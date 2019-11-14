
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Vector3 math functions.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_VECTOR_3D_MATH_FUNCTIONS_H_
#define _OSG_TOOLS_VECTOR_3D_MATH_FUNCTIONS_H_

#include "Usul/Math/Vector3.h"

#include "osg/Vec3d"
#include "osg/Vec3f"

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
    inline bool isFinite ( const osg::Vec3d &v )
    {
      return (
        ( true == std::isfinite ( v[0] ) ) &&
        ( true == std::isfinite ( v[1] ) ) &&
        ( true == std::isfinite ( v[2] ) )
      );
    }
    inline bool isFinite ( const osg::Vec3f &v )
    {
      return (
        ( true == std::isfinite ( v[0] ) ) &&
        ( true == std::isfinite ( v[1] ) ) &&
        ( true == std::isfinite ( v[2] ) )
      );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions that perform a dot product.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline double dot ( const osg::Vec3d &a, const osg::Vec3d &b )
    {
      return ( a * b );
    }
    inline float dot ( const osg::Vec3f &a, const osg::Vec3f &b )
    {
      return ( a * b );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions that perform a cross product.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline osg::Vec3d cross ( const osg::Vec3d &a, const osg::Vec3d &b )
    {
      return ( a ^ b );
    }
    inline osg::Vec3f cross ( const osg::Vec3f &a, const osg::Vec3f &b )
    {
      return ( a ^ b );
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
    inline osg::Vec3d convert ( const Usul::Math::Vec3d &v )
    {
      return osg::Vec3d ( v[0], v[1], v[2] );
    }
    inline osg::Vec3f convert ( const Usul::Math::Vec3f &v )
    {
      return osg::Vec3f ( v[0], v[1], v[2] );
    }
    inline Usul::Math::Vec3d convert ( const osg::Vec3d &v )
    {
      return Usul::Math::Vec3d ( v[0], v[1], v[2] );
    }
    inline Usul::Math::Vec3f convert ( const osg::Vec3f &v )
    {
      return Usul::Math::Vec3f ( v[0], v[1], v[2] );
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
    inline void clamp ( osg::Vec3d &v, const double mn, const double mx )
    {
      v[0] = std::clamp ( v[0], mn, mx );
      v[1] = std::clamp ( v[1], mn, mx );
      v[2] = std::clamp ( v[2], mn, mx );
    }
    inline void clamp ( osg::Vec3f &v, const float mn, const float mx )
    {
      v[0] = std::clamp ( v[0], mn, mx );
      v[1] = std::clamp ( v[1], mn, mx );
      v[2] = std::clamp ( v[2], mn, mx );
    }
  }
}


#endif // _OSG_TOOLS_VECTOR_3D_MATH_FUNCTIONS_H_
