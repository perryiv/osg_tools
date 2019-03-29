
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

#include <sstream>


namespace OsgTools {
namespace Strings {


///////////////////////////////////////////////////////////////////////////////
//
//  Format the matrix.
//
///////////////////////////////////////////////////////////////////////////////

namespace Details
{
  template < class T > inline std::string formatMatrix ( const T &m )
  {
    std::ostringstream out;
    out << m(0,0) << ", " << m(0,1) << ", " << m(0,2) << ", " << m(0,3) << '\n';
    out << m(1,0) << ", " << m(1,1) << ", " << m(1,2) << ", " << m(1,3) << '\n';
    out << m(2,0) << ", " << m(2,1) << ", " << m(2,2) << ", " << m(2,3) << '\n';
    out << m(3,0) << ", " << m(3,1) << ", " << m(3,2) << ", " << m(3,3);
    return out.str();
  }
}
std::string format ( const osg::Matrixd &m )
{
  return Details::formatMatrix ( m );
}
std::string format ( const osg::Matrixf &m )
{
  return Details::formatMatrix ( m );
}


} // namespace OsgTools
} // namespace Usul
