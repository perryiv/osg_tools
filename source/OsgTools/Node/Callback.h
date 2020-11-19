
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2020, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for a node callback.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_NODE_CALLBACK_CLASS_H_
#define _OSG_TOOLS_NODE_CALLBACK_CLASS_H_

#include "Usul/Tools/NoCopying.h"

#include "osg/NodeCallback"

#include <functional>


namespace OsgTools {
namespace Node {


class Callback : public osg::NodeCallback, public Usul::Tools::NoCopying
{
public:

  // Useful typedefs.
  typedef osg::NodeCallback BaseClass;
  typedef std::function < void ( osg::Node *node, osg::NodeVisitor * ) > Function;

  // Constructors.
  Callback() : BaseClass(), _fun()
  {
  }
  Callback ( Function fun ) : BaseClass(), _fun ( fun )
  {
  }

  // Overloaded operator function.
  virtual void operator() ( osg::Node *node, osg::NodeVisitor *visitor ) override
  {
    if ( _fun )
    {
      _fun ( node, visitor );
    }
  }

  // Access to the function.
  const Function &get() const { return _fun; }
  Function &      get()       { return _fun; }

protected:

  // Use reference counting.
  virtual ~Callback()
  {
  }

private:

  Function _fun;
};


} // namespace Node
} // namespace OsgTools


#endif // _OSG_TOOLS_NODE_CALLBACK_CLASS_H_
