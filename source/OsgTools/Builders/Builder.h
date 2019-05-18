
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

#include "OsgTools/Forward.h"

#include "Usul/Tools/NoCopying.h"
#include "Usul/Tools/Properties.h"


namespace OsgTools {
namespace Builders {


class Builder : public Usul::Tools::NoCopying
{
public:

  typedef Usul::Tools::Properties::MapType Options;

  ~Builder();

  virtual osg::Node *build() = 0;

protected:

  Builder();
  Builder ( const Options & );
};


typedef Builder::Options Options;


} // namespace Builders
} // namespace OsgTools


#endif // _OSG_TOOLS_BUILDERS_BASE_CLASS_H_
