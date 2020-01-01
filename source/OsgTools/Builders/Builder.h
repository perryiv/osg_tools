
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Base class for all builders.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_BUILDERS_BASE_CLASS_H_
#define _OSG_TOOLS_BUILDERS_BASE_CLASS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Forward.h"

#include "Usul/Properties/Map.h"
#include "Usul/Tools/NoCopying.h"


namespace OsgTools {
namespace Builders {


class OSG_TOOLS_EXPORT Builder : public Usul::Tools::NoCopying
{
public:

  typedef Usul::Properties::Map Options;

  ~Builder();

  virtual osg::Node *build() = 0;

protected:

  Builder();
  Builder ( const Options & );
  Builder ( const Options::Values & );
};


typedef Builder::Options Options;


} // namespace Builders
} // namespace OsgTools


#endif // _OSG_TOOLS_BUILDERS_BASE_CLASS_H_
