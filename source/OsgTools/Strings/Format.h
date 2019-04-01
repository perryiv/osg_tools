
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

#ifndef _OSG_TOOLS_STRINGS_FORMAT_H_
#define _OSG_TOOLS_STRINGS_FORMAT_H_

#include "OsgTools/Forward.h"

#include "Usul/Strings/Format.h"


namespace OsgTools {
namespace Strings {


///////////////////////////////////////////////////////////////////////////////
//
//  Format the string.
//
///////////////////////////////////////////////////////////////////////////////

std::string format ( const osg::Matrixd &m );
std::string format ( const osg::Matrixf &m );
std::string format ( const osg::Vec4d &v );
std::string format ( const osg::Vec4f &v );
std::string format ( const osg::Vec3d &v );
std::string format ( const osg::Vec3f &v );


} // namespace Strings
} // namespace OsgTools


namespace Usul {
namespace Strings {


///////////////////////////////////////////////////////////////////////////////
//
//  For compatability with the Usul::Strings::format() functions.
//
///////////////////////////////////////////////////////////////////////////////

inline std::string format ( const osg::Matrixd &m )
{
  return OsgTools::Strings::format ( m );
}
inline std::string format ( const osg::Matrixf &m )
{
  return OsgTools::Strings::format ( m );
}
inline std::string format ( const osg::Vec4d &v )
{
  return OsgTools::Strings::format ( v );
}
inline std::string format ( const osg::Vec4f &v )
{
  return OsgTools::Strings::format ( v );
}
inline std::string format ( const osg::Vec3d &v )
{
  return OsgTools::Strings::format ( v );
}
inline std::string format ( const osg::Vec3f &v )
{
  return OsgTools::Strings::format ( v );
}


} // namespace Strings
} // namespace Usul


#endif // _OSG_TOOLS_STRINGS_FORMAT_H_
