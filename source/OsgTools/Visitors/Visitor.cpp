
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

#include "OsgTools/Visitors/Visitor.h"

#include "osg/Drawable"
#include "osg/Geode"
#include "osg/Group"
#include "osg/Matrixd"
#include "osg/MatrixTransform"


namespace OsgTools {
namespace Visitors {


///////////////////////////////////////////////////////////////////////////////
//
//  Visit the nodes and drawables in the scene.
//
///////////////////////////////////////////////////////////////////////////////

void Visitor::visit ( osg::Node *node, NodeCallback ncb1, NodeCallback ncb2, DrawableCallback dcb )
{
  const osg::Matrixd m = osg::Matrixd::identity();
  Visitor::_visit ( m, node, ncb1, ncb2, dcb );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Visit the node.
//
///////////////////////////////////////////////////////////////////////////////

void Visitor::_visit ( const osg::Matrixd &m1, osg::Node *node, NodeCallback &ncb1, NodeCallback &ncb2, DrawableCallback &dcb )
{
  if ( nullptr == node )
  {
    return;
  }

  const osg::MatrixTransform *trans = dynamic_cast < osg::MatrixTransform * > ( node );
  const osg::Matrixd m2 = ( ( nullptr == trans ) ? m1 : ( trans->getMatrix() * m1 ) );

  if ( ncb1 )
  {
    ncb1 ( m2, node );
  }

  Visitor::_visit ( m2, dynamic_cast < osg::Geode * > ( node ), dcb );
  Visitor::_visit ( m2, dynamic_cast < osg::Group * > ( node ), ncb1, ncb2, dcb );

  if ( ncb2 )
  {
    ncb2 ( m2, node );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Visit the group.
//
///////////////////////////////////////////////////////////////////////////////

void Visitor::_visit ( const osg::Matrixd &m, osg::Group *group, NodeCallback &ncb1, NodeCallback &ncb2, DrawableCallback &dcb )
{
  if ( nullptr == group )
  {
    return;
  }

  unsigned int numChildren = group->getNumChildren();
  for ( unsigned int i = 0; i < numChildren; ++i )
  {
    osg::Node *child = group->getChild ( i );
    if ( nullptr != child )
    {
      Visitor::_visit ( m, child, ncb1, ncb2, dcb );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Visit the geode.
//
///////////////////////////////////////////////////////////////////////////////

void Visitor::_visit ( const osg::Matrixd &m, osg::Geode *geode, DrawableCallback &dcb )
{
  if ( nullptr == geode )
  {
    return;
  }

  unsigned int numDrawables = geode->getNumDrawables();
  for ( unsigned int i = 0; i < numDrawables; ++i )
  {
    osg::Drawable *child = geode->getDrawable ( i );
    if ( nullptr != child )
    {
      Visitor::_visit ( m, child, dcb );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Visit the drawable.
//
///////////////////////////////////////////////////////////////////////////////

void Visitor::_visit ( const osg::Matrixd &m, osg::Drawable *drawable, DrawableCallback &dcb )
{
  if ( nullptr == drawable )
  {
    return;
  }

  if ( dcb )
  {
    dcb ( m, drawable );
  }
}


} // namespace Visitors
} // namespace OsgTools
