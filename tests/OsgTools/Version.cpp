
////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Test the version.
//
////////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Version.h"

#include "catch2/catch.hpp"

#include <string>


////////////////////////////////////////////////////////////////////////////////
//
//  Test the version.
//
////////////////////////////////////////////////////////////////////////////////

TEST_CASE ( "Version should be correct" )
{
  REQUIRE ( OsgTools::Version::MAJOR == 3 );
  REQUIRE ( OsgTools::Version::MINOR == 0 );
  REQUIRE ( OsgTools::Version::PATCH == 0 );
  REQUIRE ( std::string ( OsgTools::Version::STRING ) == std::string ( "3.0.0" ) );
}
