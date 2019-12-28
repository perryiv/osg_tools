
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Matrix math functions.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_MATRIX_MATH_FUNCTIONS_H_
#define _OSG_TOOLS_MATRIX_MATH_FUNCTIONS_H_

#include "Usul/Math/Matrix44.h"

#include "osg/Matrixd"
#include "osg/Matrixf"
#include "osg/Vec4d"
#include "osg/Vec4f"
#include "osg/Vec3d"
#include "osg/Vec3f"

#include <stdexcept>
#include <type_traits>


///////////////////////////////////////////////////////////////////////////////
//
//  Older versions of osg::Matrix do not have a transpose function.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    namespace Details
    {
      template < class M >
      inline void transposeMatrix ( const M &a, M &b )
      {
        b(0,0) = a(0,0);
        b(0,1) = a(1,0);
        b(0,2) = a(2,0);
        b(0,3) = a(3,0);
        b(1,0) = a(0,1);
        b(1,1) = a(1,1);
        b(1,2) = a(2,1);
        b(1,3) = a(3,1);
        b(2,0) = a(0,2);
        b(2,1) = a(1,2);
        b(2,2) = a(2,2);
        b(2,3) = a(3,2);
        b(3,0) = a(0,3);
        b(3,1) = a(1,3);
        b(3,2) = a(2,3);
        b(3,3) = a(3,3);
      }
    }
    inline void transpose ( const osg::Matrixd &a, osg::Matrixd &b )
    {
      Details::transposeMatrix ( a, b );
    }
    inline void transpose ( osg::Matrixd &m )
    {
      osg::Matrixd temp ( m );
      transpose ( temp, m );
    }
    inline void transpose ( const osg::Matrixf &a, osg::Matrixf &b )
    {
      Details::transposeMatrix ( a, b );
    }
    inline void transpose ( osg::Matrixf &m )
    {
      osg::Matrixf temp ( m );
      transpose ( temp, m );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions for use with Usul::Math::unProject and elsewhere.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline bool inverse ( const osg::Matrixd &a, osg::Matrixd &b )
    {
      return b.invert ( a );
    }
    inline bool inverse ( const osg::Matrixf &a, osg::Matrixf &b )
    {
      return b.invert ( a );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions for use with Usul::Math::unProject and elsewhere.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline void multiply ( const osg::Matrixd &m, const osg::Vec4d &a, osg::Vec4d &b )
    {
      b = a * m;
    }
    inline void multiply ( const osg::Matrixf &m, const osg::Vec4f &a, osg::Vec4f &b )
    {
      b = a * m;
    }
    inline void multiply ( const osg::Matrixd &m, const osg::Vec3d &a, osg::Vec3d &b )
    {
      b = a * m;
    }
    inline void multiply ( const osg::Matrixf &m, const osg::Vec3f &a, osg::Vec3f &b )
    {
      b = a * m;
    }
    inline osg::Vec4d multiply ( const osg::Matrixd &m, const osg::Vec4d &a )
    {
      return a * m;
    }
    inline osg::Vec4f multiply ( const osg::Matrixf &m, const osg::Vec4f &a )
    {
      return a * m;
    }
    inline osg::Vec3d multiply ( const osg::Matrixd &m, const osg::Vec3d &a )
    {
      return a * m;
    }
    inline osg::Vec3f multiply ( const osg::Matrixf &m, const osg::Vec3f &a )
    {
      return a * m;
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Convert the matrix types.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    namespace Details
    {
      template < class M1, class M2 >
      inline void convertMatrix44 ( const M1 &m1, M2 &m2 )
      {
        typedef typename M1::value_type T1;
        typedef typename M2::value_type T2;
        static_assert ( std::is_same < T1, T2 >::value, "Matrices do not have the same value type" );

        const T1 *from ( m1.ptr() );
        T1 *to ( m2.ptr() );

        to[ 0] = from[ 0];
        to[ 1] = from[ 1];
        to[ 2] = from[ 2];
        to[ 3] = from[ 3];
        to[ 4] = from[ 4];
        to[ 5] = from[ 5];
        to[ 6] = from[ 6];
        to[ 7] = from[ 7];
        to[ 8] = from[ 8];
        to[ 9] = from[ 9];
        to[10] = from[10];
        to[11] = from[11];
        to[12] = from[12];
        to[13] = from[13];
        to[14] = from[14];
        to[15] = from[15];
      }
    }

    inline void convert ( const Usul::Math::Matrix44d &from, osg::Matrixd &to )
    {
      Details::convertMatrix44 ( from, to );
    }
    inline osg::Matrixd convert ( const Usul::Math::Matrix44d &from )
    {
      osg::Matrixd to;
      convert ( from, to );
      return to;
    }

    inline void convert ( const Usul::Math::Matrix44f &from, osg::Matrixf &to )
    {
      Details::convertMatrix44 ( from, to );
    }
    inline osg::Matrixf convert ( const Usul::Math::Matrix44f &from )
    {
      osg::Matrixf to;
      convert ( from, to );
      return to;
    }

    inline void convert ( const osg::Matrixd &from, Usul::Math::Matrix44d &to )
    {
      Details::convertMatrix44 ( from, to );
    }
    inline Usul::Math::Matrix44d convert ( const osg::Matrixd &from )
    {
      Usul::Math::Matrix44d to;
      convert ( from, to );
      return to;
    }

    inline void convert ( const osg::Matrixf &from, Usul::Math::Matrix44f &to )
    {
      Details::convertMatrix44 ( from, to );
    }
    inline Usul::Math::Matrix44f convert ( const osg::Matrixf &from )
    {
      Usul::Math::Matrix44f to;
      convert ( from, to );
      return to;
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Rotate the matrix by the given angle about the given axis.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline bool rotate ( const osg::Matrixd &m, const osg::Vec3d &axis, const double &angle, osg::Matrixd &answer )
    {
      // Handle zero-length axis vectors.
      const double len = axis.length();
      if ( 0.0 == len )
      {
        return false;
      }

      // Shortcuts.
      double x = axis[0];
      double y = axis[1];
      double z = axis[2];

      // Normalize if we have to.
      if ( 1.0 != len )
      {
        const double invLen = 1.0 / len;
        x *= invLen;
        y *= invLen;
        z *= invLen;
      }

      // Make the rotation matrix.
      osg::Matrixd rotation;
      rotation.makeRotate ( angle, osg::Vec3d ( x, y, z ) );

      // The answer is the product of the two matrices.
      answer = rotation * m; // TODO: Make sure this is the correct order.

      // It worked.
      return true;
    }
    inline osg::Matrixd rotate ( const osg::Matrixd &m, const osg::Vec3d &axis, const double &angle )
    {
      osg::Matrixd answer;
      if ( false == rotate ( m, axis, angle, answer ) )
      {
        throw std::runtime_error ( "Could not rotate matrix" );
      }
      return answer;
    }
  }
}


#endif // _OSG_TOOLS_MATRIX_MATH_FUNCTIONS_H_
