
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Test the 3D math functions.
//
////////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Math/Matrix.h"

#include "Usul/Math/Three.h"
#include "Usul/Math/Line3.h"

#include "osg/Matrixd"
#include "osg/Matrixf"
#include "osg/Vec3d"
#include "osg/Vec3f"
#include "osg/Vec4d"
#include "osg/Vec4f"

#include "catch2/catch.hpp"


////////////////////////////////////////////////////////////////////////////////
//
//  Test the 3D math functions.
//
////////////////////////////////////////////////////////////////////////////////

TEST_CASE ( "3D template math functions" )
{
  SECTION ( "Un-projecting works" )
  {
    const osg::Vec3d screen ( 100, 100, 0 );
    const osg::Matrixd viewMatrix;
    const osg::Matrixd projMatrix;
    const osg::Vec4d viewport ( 0, 0, 1000, 1000 );
    osg::Vec3d answer;

    // Not testing real numbers yet, just making sure the template arguments work.
    const bool result = Usul::Math::unProject ( screen, viewMatrix, projMatrix, viewport, answer );

    REQUIRE ( true == result );
  }

  SECTION ( "Making a line works" )
  {
    const double x ( 100 );
    const double y ( 100 );
    const osg::Matrixd viewMatrix;
    const osg::Matrixd projMatrix;
    const osg::Vec4d viewport ( 0, 0, 1000, 1000 );
    Usul::Math::Line3d answer;

    // Not testing real numbers yet, just making sure the template arguments work.
    const bool result = Usul::Math::makeLine ( x, y, viewMatrix, projMatrix, viewport, answer );

    REQUIRE ( true == result );
  }
}
