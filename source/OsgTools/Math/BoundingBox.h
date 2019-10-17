
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Bounding box math functions.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_BOUNDING_BOX_MATH_FUNCTIONS_H_
#define _OSG_TOOLS_BOUNDING_BOX_MATH_FUNCTIONS_H_

#include "OsgTools/Math/Vector3.h"

#include "osg/BoundingBox"


///////////////////////////////////////////////////////////////////////////////
//
//  Adapter functions that sees if the bounding box is finite.
//
///////////////////////////////////////////////////////////////////////////////

namespace Usul
{
  namespace Math
  {
    inline bool isFinite ( const osg::BoundingBoxd &bb )
    {
      return (
        ( true == Usul::Math::isFinite ( bb._min ) ) &&
        ( true == Usul::Math::isFinite ( bb._max ) )
      );
    }
    inline bool isFinite ( const osg::BoundingBoxf &bb )
    {
      return (
        ( true == Usul::Math::isFinite ( bb._min ) ) &&
        ( true == Usul::Math::isFinite ( bb._max ) )
      );
    }
  }
}


#endif // _OSG_TOOLS_BOUNDING_BOX_MATH_FUNCTIONS_H_
