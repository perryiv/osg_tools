
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Math functions for sequences scalars and vectors.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_MATH_SEQUENCE_FUNCTIONS_H_
#define _OSG_TOOLS_MATH_SEQUENCE_FUNCTIONS_H_

#include "OsgTools/Math/Matrix44.h"
#include "OsgTools/Math/Vector3.h"

#include "osg/Matrixd"
#include "osg/Matrixf"
#include "osg/Vec3d"
#include "osg/Vec3f"

#include <vector>


namespace Usul {
namespace Math {


/////////////////////////////////////////////////////////////////////////////
//
//  Helper function to transform a sequence of vec3 elements.
//
/////////////////////////////////////////////////////////////////////////////

namespace Details
{
  template < class MatrixType, class Vec3Type >
  inline void transform ( const MatrixType &m, const std::vector < Vec3Type > &a, std::vector < Vec3Type > &b )
  {
    // Shortcuts.
    typedef std::vector < Vec3Type > Sequence;
    typedef typename Sequence::size_type Size;

    // Needed below.
    const Size num = a.size();

    // Resize if we have to.
    // This also handles the case when a and b are the same vector.
    if ( b.size() != num )
    {
      b.resize ( num );
    }

    // Loop through the sequence.
    for ( Size i = 0; i < num; ++i )
    {
      Usul::Math::multiply ( m, a[i], b[i] );
    }
  }
  template < class MatrixType, class Vec3Type >
  inline void transform ( const MatrixType &m, std::vector < Vec3Type > &a )
  {
    transform ( m, a, a );
  }
}


/////////////////////////////////////////////////////////////////////////////
//
//  Transform the sequence of vec3 elements.
//  Note: a and b can be the same vector.
//
/////////////////////////////////////////////////////////////////////////////

inline void transform ( const osg::Matrixd &m, const std::vector < osg::Vec3d > &a, std::vector < osg::Vec3d > &b )
{
  Details::transform ( m, a, b );
}
inline void transform ( const osg::Matrixd &m, std::vector < osg::Vec3d > &a )
{
  Details::transform ( m, a );
}
inline void transform ( const osg::Matrixf &m, const std::vector < osg::Vec3f > &a, std::vector < osg::Vec3f > &b )
{
  Details::transform ( m, a, b );
}
inline void transform ( const osg::Matrixf &m, std::vector < osg::Vec3f > &a )
{
  Details::transform ( m, a );
}


/////////////////////////////////////////////////////////////////////////////
//
//  Helper function to normalize a sequence of vec3 elements.
//
/////////////////////////////////////////////////////////////////////////////

namespace Details
{
  template < class Vec3Type >
  inline void normalize ( const std::vector < Vec3Type > &a, std::vector < Vec3Type > &b )
  {
    // Shortcuts.
    typedef std::vector < Vec3Type > Sequence;
    typedef typename Sequence::size_type Size;

    // Needed below.
    const Size num = a.size();

    // Resize if we have to.
    // This also handles the case when a and b are the same vector.
    if ( b.size() != num )
    {
      b.resize ( num );
    }

    // Loop through the sequence.
    for ( Size i = 0; i < num; ++i )
    {
      Usul::Math::normalize ( a[i], b[i] );
    }
  }
  template < class Vec3Type >
  inline void normalize ( std::vector < Vec3Type > &a )
  {
    Details::normalize ( a, a );
  }
}


/////////////////////////////////////////////////////////////////////////////
//
//  Normalize the sequence of vec3 elements.
//  Note: a and b can be the same vector.
//
/////////////////////////////////////////////////////////////////////////////

inline void normalize ( const std::vector < osg::Vec3d > &a, std::vector < osg::Vec3d > &b )
{
  Details::normalize ( a, b );
}
inline void normalize ( std::vector < osg::Vec3d > &a )
{
  Details::normalize ( a );
}
inline void normalize ( const std::vector < osg::Vec3f > &a, std::vector < osg::Vec3f > &b )
{
  Details::normalize ( a, b );
}
inline void normalize ( std::vector < osg::Vec3f > &a )
{
  Details::normalize ( a );
}


} // namespace Math
} // namespace Usul


#endif // _OSG_TOOLS_MATH_SEQUENCE_FUNCTIONS_H_
