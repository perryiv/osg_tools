
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Visit a scene.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_VISITORS_GENERIC_VISITOR_CLASS_H_
#define _OSG_TOOLS_VISITORS_GENERIC_VISITOR_CLASS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Forward.h"

#include <functional>


namespace OsgTools {
namespace Visitors {


class OSG_TOOLS_EXPORT Visitor
{
public:

  typedef std::function < void ( const osg::Matrixd &, osg::Drawable * ) > DrawableCallback;
  typedef std::function < void ( const osg::Matrixd &, osg::Node * ) > NodeCallback;

  // Visit the nodes and drawables in the scene. The first NodeCallback is
  // called before traversing the children, and the second one is called after.
  static void visit ( osg::Node *, NodeCallback, NodeCallback, DrawableCallback );

protected:

  static void _visit ( const osg::Matrixd &, osg::Drawable *, DrawableCallback & );
  static void _visit ( const osg::Matrixd &, osg::Geode *, DrawableCallback & );
  static void _visit ( const osg::Matrixd &, osg::Group *, NodeCallback &, NodeCallback &, DrawableCallback & );
  static void _visit ( const osg::Matrixd &, osg::Node *, NodeCallback &, NodeCallback &, DrawableCallback & );
};


} // namespace Visitors
} // namespace OsgTools


#endif // _OSG_TOOLS_VISITORS_GENERIC_VISITOR_CLASS_H_
