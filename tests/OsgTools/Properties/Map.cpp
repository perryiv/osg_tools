
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Test the property function(s).
//
////////////////////////////////////////////////////////////////////////////////

#include "Usul/Properties/Map.h"
#include "Usul/Properties/Matrix44.h"
#include "Usul/Properties/Vector2.h"
#include "Usul/Properties/Vector3.h"
#include "Usul/Properties/Vector4.h"

#include "catch2/catch.hpp"

namespace Math = Usul::Math;
namespace Properties = Usul::Properties;


////////////////////////////////////////////////////////////////////////////////
//
//  Test the property function(s).
//
////////////////////////////////////////////////////////////////////////////////

TEST_CASE ( "Property functions for vectors and matrices" )
{
  typedef Properties::Map Map;

  SECTION ( "Can add and access vectors and matrices" )
  {
    Map a;

    a.insert ( "p1", Math::Vec2d ( 1.0,  2.0  ) );
    a.insert ( "p2", Math::Vec2f ( 1.0f, 2.0f ) );
    a.insert ( "p3", Math::Vec3d ( 1.0,  2.0,  3.0  ) );
    a.insert ( "p4", Math::Vec3f ( 1.0f, 2.0f, 3.0f ) );
    a.insert ( "p5", Math::Vec4d ( 1.0,  2.0,  3.0,  4.0  ) );
    a.insert ( "p6", Math::Vec4f ( 1.0f, 2.0f, 3.0f, 4.0f ) );

    // Asking for the properties using their actual type.
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec2d > ( a, "p1" ), Math::Vec2d ( 1.0,  2.0  ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec2f > ( a, "p2" ), Math::Vec2f ( 1.0f, 2.0f ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec3d > ( a, "p3" ), Math::Vec3d ( 1.0,  2.0,  3.0  ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec3f > ( a, "p4" ), Math::Vec3f ( 1.0f, 2.0f, 3.0f ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec4d > ( a, "p5" ), Math::Vec4d ( 1.0,  2.0,  3.0,  4.0  ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec4f > ( a, "p6" ), Math::Vec4f ( 1.0f, 2.0f, 3.0f, 4.0f ) ) );

    // Asking for the properties using the other type.
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec2f > ( a, "p1" ), Math::Vec2f ( 1.0f, 2.0f ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec2d > ( a, "p2" ), Math::Vec2d ( 1.0,  2.0  ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec3f > ( a, "p3" ), Math::Vec3f ( 1.0f, 2.0f, 3.0f ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec3d > ( a, "p4" ), Math::Vec3d ( 1.0,  2.0,  3.0  ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec4f > ( a, "p5" ), Math::Vec4f ( 1.0f, 2.0f, 3.0f, 4.0f ) ) );
    REQUIRE ( true == Math::equal ( Usul::Properties::require < Math::Vec4d > ( a, "p6" ), Math::Vec4d ( 1.0,  2.0,  3.0,  4.0  ) ) );
  }
}
