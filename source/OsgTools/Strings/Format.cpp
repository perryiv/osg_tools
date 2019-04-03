
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  String formatting functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "OsgTools/Strings/Format.h"

#include "osg/Matrixd"
#include "osg/Matrixf"
#include "osg/Vec4d"
#include "osg/Vec4f"
#include "osg/Vec3d"
#include "osg/Vec3f"
#include "osg/Vec2d"
#include "osg/Vec2f"

#include <sstream>


namespace OsgTools {
namespace Strings {


///////////////////////////////////////////////////////////////////////////////
//
//  Format the matrix.
//
///////////////////////////////////////////////////////////////////////////////

std::string format ( const osg::Vec4d &v )
{
  return Usul::Strings::formatVec4 ( v );
}
std::string format ( const osg::Vec4f &v )
{
  return Usul::Strings::formatVec4 ( v );
}
std::string format ( const osg::Vec3d &v )
{
  return Usul::Strings::formatVec3 ( v );
}
std::string format ( const osg::Vec3f &v )
{
  return Usul::Strings::formatVec3 ( v );
}
std::string format ( const osg::Vec2d &v )
{
  return Usul::Strings::formatVec2 ( v );
}
std::string format ( const osg::Vec2f &v )
{
  return Usul::Strings::formatVec2 ( v );
}
std::string format ( const osg::Matrixd &m )
{
  return Usul::Strings::formatMatrix44 ( m );
}
std::string format ( const osg::Matrixf &m )
{
  return Usul::Strings::formatMatrix44 ( m );
}


} // namespace OsgTools
} // namespace Usul
