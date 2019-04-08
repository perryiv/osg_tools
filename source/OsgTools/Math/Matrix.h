
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

#include <type_traits>


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions for use with Usul::Math::unProject
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline bool inverse ( const osg::Matrixd &a, osg::Matrixd &b )
    {
      return b.invert ( a );
    };
    inline bool inverse ( const osg::Matrixf &a, osg::Matrixf &b )
    {
      return b.invert ( a );
    };
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
    };
    inline osg::Matrixd convert ( const Usul::Math::Matrix44d &from )
    {
      osg::Matrixd to;
      convert ( from, to );
      return to;
    };

    inline void convert ( const Usul::Math::Matrix44f &from, osg::Matrixf &to )
    {
      Details::convertMatrix44 ( from, to );
    };
    inline osg::Matrixf convert ( const Usul::Math::Matrix44f &from )
    {
      osg::Matrixf to;
      convert ( from, to );
      return to;
    };

    inline void convert ( const osg::Matrixd &from, Usul::Math::Matrix44d &to )
    {
      Details::convertMatrix44 ( from, to );
    };
    inline Usul::Math::Matrix44d convert ( const osg::Matrixd &from )
    {
      Usul::Math::Matrix44d to;
      convert ( from, to );
      return to;
    };

    inline void convert ( const osg::Matrixf &from, Usul::Math::Matrix44f &to )
    {
      Details::convertMatrix44 ( from, to );
    };
    inline Usul::Math::Matrix44f convert ( const osg::Matrixf &from )
    {
      Usul::Math::Matrix44f to;
      convert ( from, to );
      return to;
    };
  }
}


#endif // _OSG_TOOLS_MATRIX_MATH_FUNCTIONS_H_
