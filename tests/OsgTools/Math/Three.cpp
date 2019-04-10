
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

#include "Usul/Math/Matrix44.h"
#include "Usul/Math/Three.h"
#include "Usul/Math/Line3.h"
#include "Usul/Math/Vector3.h"
#include "Usul/Strings/Format.h"

#include "osg/Matrixd"
#include "osg/Vec3d"
#include "osg/Vec4d"

#include "catch2/catch.hpp"


////////////////////////////////////////////////////////////////////////////////
//
//  Test the 3D math functions.
//
////////////////////////////////////////////////////////////////////////////////

TEST_CASE ( "3D template math functions" )
{
  typedef Usul::Math::Matrix44d Matrix;
  typedef Usul::Math::Vec3d Vec3;

  SECTION ( "Matrix and vector math" )
  {
    // This constructor fills the internal array in a column-major way.
    // Translation values 2, 3, and 4 are stored at indices 12, 13, and 14.
    const Matrix T (
      1,   0,   0,   2,
      0,   1,   0,   3,
      0,   0,   1,   4,
      0,   0,   0,   1
    );

    const Vec3 a = Matrix ( T.get() ) * Vec3 ( 0, 0, 0 );
    REQUIRE ( 2 == a[0] );
    REQUIRE ( 3 == a[1] );
    REQUIRE ( 4 == a[2] );

    // http://forum.openscenegraph.org/viewtopic.php?t=7556
    const osg::Vec3d b = osg::Vec3d ( 0, 0, 0 ) * osg::Matrixd ( T.get() );
    REQUIRE ( 2 == b[0] );
    REQUIRE ( 3 == b[1] );
    REQUIRE ( 4 == b[2] );

    REQUIRE ( Usul::Math::equal ( T, Usul::Math::convert ( osg::Matrixd ( T.get() ) ) ) );
    REQUIRE ( osg::Matrixd ( T.get() ) == Usul::Math::convert ( T ) );
  }

  SECTION ( "Un-projecting works" )
  {
    const osg::Vec4d viewport ( 0, 0, 1600, 1058 );
    const double x ( std::round ( viewport[2] * 0.5 ) );
    const double y ( std::round ( viewport[3] * 0.5 ) );
    const osg::Vec3d screen ( x, y, 0 );
    const osg::Matrixd viewMatrix;
    osg::Matrixd projMatrix (
      2.4678185965049204, 0, 0, 0,
      0, 3.7320508075688776, 0, 0,
      0, 0, -1.0002000200020005, -0.06487231313253677,
      0, 0, -1, 0
    );
    Usul::Math::transpose ( projMatrix );

    osg::Vec3d answer;
    const bool result = Usul::Math::unProject ( screen, viewMatrix, projMatrix, viewport, answer );

    REQUIRE ( true == result );

    const std::string expect ( Usul::Strings::formatVector3 ( osg::Vec3d ( 0, 0, -0.03243291126899654 ) ) );
    const std::string actual ( Usul::Strings::formatVector3 ( answer ) );

    REQUIRE ( expect == actual );
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
