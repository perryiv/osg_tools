
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for building a sphere.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_BUILDERS_SPHERE_CLASS_H_
#define _OSG_TOOLS_BUILDERS_SPHERE_CLASS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Forward.h"

#include "Usul/Properties/Map.h"


namespace OsgTools {
namespace Builders {


class OSG_TOOLS_EXPORT Sphere
{
public:

  typedef Usul::Properties::Map Options;

  static osg::Node *build ( const Options & );
  static osg::Node *build ( const Options::Values & );
};


} // namespace Builders
} // namespace OsgTools


#endif // _OSG_TOOLS_BUILDERS_SPHERE_CLASS_H_
