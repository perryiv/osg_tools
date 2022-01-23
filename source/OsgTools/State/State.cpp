///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV and John K Grant
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for working with the state.
//
///////////////////////////////////////////////////////////////////////////////

#include "OsgTools/State/State.h"
#include "OsgTools/Flags.h"

#include "Usul/Bits/Bits.h"
#include "Usul/Math/Random.h"

#include "osg/Node"
#include "osg/StateSet"
#include "osg/PolygonMode"
#include "osg/PolygonOffset"
#include "osg/ShadeModel"
#include "osg/LightModel"
#include "osg/LineWidth"
#include "osg/Point"
#include "osg/Material"

#include <stdexcept>
#include <iostream>

namespace OsgTools {


///////////////////////////////////////////////////////////////////////////////
//
//  Typedefs
//
///////////////////////////////////////////////////////////////////////////////

typedef osg::StateAttribute::GLModeValue GLModeValue;


///////////////////////////////////////////////////////////////////////////////
//
//  Get the lighting state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getLighting ( const osg::StateSet *ss )
{
  // Handle bad input
  if ( nullptr == ss )
  {
    return false;
  }

  // Query the mode.
  return ( osg::StateAttribute::ON == ss->getMode ( GL_LIGHTING ) );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the lighting state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setLighting ( osg::StateSet *ss, bool state )
{
  // Handle bad input
  if ( nullptr == ss )
  {
    return;
  }

  // Apply the mode settings
  ss->setMode ( GL_LIGHTING, ( ( state ) ? osg::StateAttribute::ON : osg::StateAttribute::OFF ) );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the lighting state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getLighting ( const osg::Node *node )
{
  return State::getLighting ( ( node ) ? node->getStateSet() : nullptr );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the lighting state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setLighting ( osg::Node *node, bool state )
{
  State::setLighting ( ( node ) ? node->getOrCreateStateSet() : nullptr, state );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the normalization state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getNormalize ( const osg::StateSet *ss )
{
  // Handle bad input.
  if ( nullptr == ss )
  {
    return false;
  }

  // Query the mode.
  return ( osg::StateAttribute::ON == ss->getMode ( GL_NORMALIZE ) );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the normalization state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setNormalize ( osg::StateSet *ss, bool on )
{
  // Handle bad input.
  if ( nullptr == ss )
  {
    return;
  }

  // Set the mode.
  ss->setMode ( GL_NORMALIZE, static_cast < GLModeValue > ( ( on ) ? osg::StateAttribute::ON : osg::StateAttribute::OFF ) );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the normalization state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getNormalize ( const osg::Node *node )
{
  return State::getNormalize ( ( node ) ? node->getStateSet() : nullptr );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the normalization state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setNormalize ( osg::Node *node, bool state )
{
  State::setNormalize ( ( node ) ? node->getOrCreateStateSet() : nullptr, state );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Helper function for polygon-mode.
//
///////////////////////////////////////////////////////////////////////////////

namespace Helper
{
  void setPolygonMode ( osg::Node *node, bool twoSided, osg::PolygonMode::Mode mode )
  {
    // Handle bad input.
    if ( nullptr == node )
    {
      return;
    }

    // Get the state set, or make one.
    osg::ref_ptr < osg::StateSet > ss ( node->getOrCreateStateSet() );

    // Make a polygon-mode.
    osg::ref_ptr < osg::PolygonMode > pm ( new osg::PolygonMode );

    // Set the face.
    osg::PolygonMode::Face face ( ( twoSided ) ?
                                  osg::PolygonMode::FRONT_AND_BACK :
                                  osg::PolygonMode::FRONT );

    // Set the mode.
    pm->setMode ( face, mode );

    // Set the state. Make it override any other similar states.
    ss->setAttributeAndModes ( pm.get(),
                               osg::StateAttribute::OVERRIDE |
                               osg::StateAttribute::ON );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Helper function for quering the polygon mode.
//
///////////////////////////////////////////////////////////////////////////////

namespace Helper
{
  bool hasPolygonMode ( const osg::Node *node, bool twoSided, osg::PolygonMode::Mode mode )
  {
    // Handle bad input.
    if ( nullptr == node )
    {
      return false;
    }

    // Get the state set.
    const osg::StateSet *ss = node->getStateSet();
    if ( nullptr == ss )
    {
      return false;
    }

    // Get the polygon-mode attribute, if any.
    const osg::StateAttribute *sa = ss->getAttribute ( osg::StateAttribute::POLYGONMODE );
    if ( nullptr == sa )
    {
      return false;
    }

    // Should be true.
    const osg::PolygonMode *pm = dynamic_cast < const osg::PolygonMode * > ( sa );
    if ( nullptr == pm )
    {
      return false;
    }

    // Set the face.
    osg::PolygonMode::Face face ( ( twoSided ) ?
                                  osg::PolygonMode::FRONT_AND_BACK :
                                  osg::PolygonMode::FRONT );

    // Is the mode the same?
    return ( pm->getMode ( face ) == mode );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Helper function for setting the shading models.
//
///////////////////////////////////////////////////////////////////////////////

namespace Helper
{
  void setShadeModel ( osg::Node *node, osg::ShadeModel::Mode mode )
  {
    // Handle bad input.
    if ( nullptr == node )
    {
      return;
    }

    // Get the state set, or make one.
    osg::ref_ptr < osg::StateSet > ss ( node->getOrCreateStateSet() );

    // Make a shade-model.
    osg::ref_ptr < osg::ShadeModel > sm ( new osg::ShadeModel );

    // Set the mode.
    sm->setMode ( mode );

    // Set the state. Make it override any other similar states.
    ss->setAttributeAndModes ( sm.get(),
                               osg::StateAttribute::OVERRIDE |
                               osg::StateAttribute::ON );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Helper function for quering the shading models.
//
///////////////////////////////////////////////////////////////////////////////

namespace Helper
{
  bool hasShadeModel ( const osg::Node *node, osg::ShadeModel::Mode mode )
  {
    // Handle bad input.
    if ( nullptr == node )
    {
      return false;
    }

    // Get the state set.
    const osg::StateSet *ss = node->getStateSet();
    if ( nullptr == ss )
    {
      return false;
    }

    // Get the shading attribute, if any.
    const osg::StateAttribute *sa = ss->getAttribute ( osg::StateAttribute::SHADEMODEL );
    if ( nullptr == sa )
    {
      return false;
    }

    // Should be true.
    const osg::ShadeModel *sm = dynamic_cast < const osg::ShadeModel * > ( sa );
    if ( nullptr == sm )
    {
      return false;
    }

    // See if th emode is the same.
    return ( sm->getMode() == mode );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the polygon mode.
//  This is similar to Helper::hasPolygonMode but not exactly the same.
//
///////////////////////////////////////////////////////////////////////////////

unsigned int State::getPolygonMode ( const osg::Node *node, unsigned int face )
{
  if ( nullptr == node )
  {
    return 0;
  }

  const osg::StateSet *ss = node->getStateSet();
  if ( nullptr == ss )
  {
    return 0;
  }

  const osg::StateAttribute *sa = ss->getAttribute ( osg::StateAttribute::POLYGONMODE );
  if ( nullptr == sa )
  {
    return 0;
  }

  const osg::PolygonMode *pm = dynamic_cast < const osg::PolygonMode * > ( sa );
  if ( nullptr == pm )
  {
    return 0;
  }

  return pm->getMode ( static_cast < osg::PolygonMode::Face > ( face ) );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the polygon mode.
//  This is similar to Helper::setPolygonMode but not exactly the same.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPolygonMode ( osg::Node *node, unsigned int face, unsigned int mode )
{
  // Handle bad input.
  if ( nullptr == node )
  {
    return;
  }

  // Get the state set, or make one.
  osg::ref_ptr < osg::StateSet > ss ( node->getOrCreateStateSet() );

  // Make a polygon-mode.
  osg::ref_ptr < osg::PolygonMode > pm ( new osg::PolygonMode );

  // Set the mode.
  pm->setMode (
    static_cast < osg::PolygonMode::Face > ( face ),
    static_cast < osg::PolygonMode::Mode > ( mode )
  );

  // Set the state. Make it override any other similar states.
  ss->setAttributeAndModes (
    pm.get(),
    osg::StateAttribute::OVERRIDE |
    osg::StateAttribute::ON
  );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Make polygons draw filled.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPolygonsFilled ( osg::Node *node, bool twoSided )
{
  Helper::setPolygonMode ( node, twoSided, osg::PolygonMode::FILL );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the polygon state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getPolygonsFilled ( const osg::Node *node, bool twoSided )
{
  return Helper::hasPolygonMode ( node, twoSided, osg::PolygonMode::FILL );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Make polygons draw with lines.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPolygonsLines ( osg::Node *node, bool twoSided )
{
  Helper::setPolygonMode ( node, twoSided, osg::PolygonMode::LINE );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the polygon state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getPolygonsLines ( const osg::Node *node, bool twoSided )
{
  return Helper::hasPolygonMode ( node, twoSided, osg::PolygonMode::LINE );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Make polygons draw with points.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPolygonsPoints ( osg::Node *node, bool twoSided )
{
  Helper::setPolygonMode ( node, twoSided, osg::PolygonMode::POINT );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the polygon state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getPolygonsPoints ( const osg::Node *node, bool twoSided )
{
  return Helper::hasPolygonMode ( node, twoSided, osg::PolygonMode::POINT );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Make filled polygons draw with smooth shading.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPolygonsSmooth ( osg::Node *node )
{
  Helper::setShadeModel ( node, osg::ShadeModel::SMOOTH );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the polygon shading model.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getPolygonsSmooth ( const osg::Node *node )
{
  return Helper::hasShadeModel ( node, osg::ShadeModel::SMOOTH );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Make filled polygons draw with flat shading.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPolygonsFlat ( osg::Node *node )
{
  Helper::setShadeModel ( node, osg::ShadeModel::FLAT );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the polygon shading model.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getPolygonsFlat ( const osg::Node *node )
{
  return Helper::hasShadeModel ( node, osg::ShadeModel::FLAT );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the Texture state
//
///////////////////////////////////////////////////////////////////////////////

void State::setPolygonsTextures ( osg::StateSet *ss, bool on )
{
  if ( nullptr == ss )
  {
    return;
  }

  if ( on ) // Turn on textures.
  {
    ss->setTextureMode ( 0, GL_TEXTURE_2D, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );
  }

  else
  {
    ss->setTextureMode( 0, GL_TEXTURE_2D, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the Texture state
//
///////////////////////////////////////////////////////////////////////////////

bool State::getPolygonsTextures ( const osg::StateSet *ss )
{
  // Handle no state set.
  if ( nullptr == ss )
  {
    return false;
  }

  const GLModeValue mode = ss->getTextureMode ( 0, GL_TEXTURE_2D );

  if ( mode == ( osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE ) )
  {
    return false;
  }

  else
  {
    return true;
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the two sided lighting state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getTwoSidedLighting ( const osg::StateSet *ss )
{
  // Handle no state set.
  if ( nullptr == ss )
  {
    return false;
  }

  // Get the light-model attribute, if any.
  const osg::StateAttribute *sa = ss->getAttribute ( osg::StateAttribute::LIGHTMODEL );
  if ( nullptr == sa )
  {
    return false;
  }

  // Should be true.
  const osg::LightModel *lm = dynamic_cast < const osg::LightModel * > ( sa );
  if ( nullptr == lm )
  {
    return false;
  }

  // Is two sided light on?
  return ( lm->getTwoSided() );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the two sided lighting state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setTwoSidedLighting ( osg::StateSet *ss, bool state )
{
  // Handle no state set.
  if ( nullptr == ss )
  {
    return;
  }

  // Initialize.
  osg::ref_ptr < osg::LightModel > lm;

  // Get the light-model attribute, if any.
  osg::StateAttribute *sa = ss->getAttribute ( osg::StateAttribute::LIGHTMODEL );
  if ( nullptr == sa )
  {
    lm = new osg::LightModel;
  }
  else
  {
    lm = dynamic_cast < osg::LightModel * > ( sa );
  }

  lm->setTwoSided ( state );

  // Set the state. Make it override any other similar states.
  ss->setAttributeAndModes ( lm.get(), osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the two sided lighting state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getTwoSidedLighting ( const osg::Node *node )
{
  return State::getTwoSidedLighting ( ( node ) ? node->getStateSet() : nullptr );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the two sided lighting state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setTwoSidedLighting ( osg::Node *node, bool state )
{
  State::setTwoSidedLighting ( ( node ) ? node->getOrCreateStateSet() : nullptr, state );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set line width.
//
///////////////////////////////////////////////////////////////////////////////

void State::setLineWidth ( osg::StateSet *ss, float width )
{
  // Handle no state set.
  if ( nullptr == ss )
  {
    return;
  }

  osg::ref_ptr < osg::LineWidth > lw ( new osg::LineWidth() );
  lw->setWidth ( width );

  // Set the state. Make it override any other similar states.
  ss->setAttributeAndModes ( lw.get(), osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set line width.
//
///////////////////////////////////////////////////////////////////////////////

void State::setLineWidth ( osg::Node *node, float width )
{
  State::setLineWidth ( ( ( node ) ? node->getStateSet() : nullptr ), width );
}


///////////////////////////////////////////////////////////////////////////////
//
//   Get line width.
//
///////////////////////////////////////////////////////////////////////////////

float State::getLineWidth ( const osg::StateSet *ss )
{
  // Handle no state set.
  if ( nullptr == ss )
  {
    return 1.0f;
  }

  // Get the attribute, if any.
  const osg::StateAttribute *sa = ss->getAttribute ( osg::StateAttribute::LINEWIDTH );
  if ( nullptr == sa )
  {
    return 1.0f;
  }

  // Should be true.
  const osg::LineWidth *lw = dynamic_cast < const osg::LineWidth * > ( sa );
  if ( nullptr == lw )
  {
    return 1.0f;
  }

  // Get the line width
  return ( lw->getWidth() );
}


///////////////////////////////////////////////////////////////////////////////
//
//   Get line width.
//
///////////////////////////////////////////////////////////////////////////////

float State::getLineWidth ( const osg::Node *node )
{
  return State::getLineWidth ( node ? node->getStateSet() : nullptr );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set point size.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPointSize ( osg::StateSet *ss, float size )
{
  // Handle no state set.
  if ( nullptr == ss )
  {
    return;
  }

  osg::ref_ptr < osg::Point > pt ( new osg::Point );
  pt->setSize ( size );

  // Set the state. Make it override any other similar states.
  ss->setAttributeAndModes ( pt.get(), osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set point size.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPointSize ( osg::Node *node, float size )
{
  State::setPointSize ( ( ( node ) ? node->getOrCreateStateSet() : nullptr ), size );
}


///////////////////////////////////////////////////////////////////////////////
//
//   Get point size.
//
///////////////////////////////////////////////////////////////////////////////

float State::getPointSize ( const osg::StateSet *ss )
{
  // Handle no state set.
  if ( nullptr == ss )
  {
    return 1.0f;
  }

  // Get the shade-model attribute, if any.
  const osg::StateAttribute *sa = ss->getAttribute ( osg::StateAttribute::POINT );
  if ( nullptr == sa )
  {
    return 1.0f;
  }

  // Should be true.
  const osg::Point *pt = dynamic_cast < const osg::Point * > ( sa );
  if ( nullptr == pt )
  {
    return 1.0f;
  }

  // Get the line width
  return ( pt->getSize() );
}


///////////////////////////////////////////////////////////////////////////////
//
//   Get point size.
//
///////////////////////////////////////////////////////////////////////////////

float State::getPointSize ( const osg::Node *node )
{
  return State::getPointSize ( node ? node->getStateSet() : nullptr );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Make the state for hidden lines.
//
///////////////////////////////////////////////////////////////////////////////

void State::hiddenLines ( const osg::Vec4f &color, osg::StateSet *normal, osg::StateSet *hidden )
{
  // Handle bad input.
  if ( ( nullptr == normal ) && ( nullptr == hidden ) )
  {
    return;
  }

  // Set the polygon-mode.
  osg::ref_ptr < osg::PolygonMode > mode ( new osg::PolygonMode );
  mode->setMode ( osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE );
  hidden->setAttributeAndModes ( mode.get(), osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );

  // Set the polygon-offset. See osgscribe example.
  osg::ref_ptr < osg::PolygonOffset > offset ( new osg::PolygonOffset );
  offset->setFactor ( -1.0f );
  offset->setUnits  ( -1.0f );
  hidden->setAttributeAndModes ( offset.get(), osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );

  // Material same as background and no lighting.
  osg::ref_ptr < osg::Material > material ( new osg::Material );
  material->setAmbient ( osg::Material::FRONT_AND_BACK, color );
  material->setDiffuse ( osg::Material::FRONT_AND_BACK, color );
  normal->setAttributeAndModes ( material.get(), osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );
  normal->setMode ( GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get a random material.
//
///////////////////////////////////////////////////////////////////////////////

osg::Material *State::getMaterialRandom()
{
  const float mn = 0.2f;
  const float mx = 1.0f;
  const float r = Usul::Math::random ( mn, mx );
  const float g = Usul::Math::random ( mn, mx );
  const float b = Usul::Math::random ( mn, mx );

  const osg::Vec4 diffuse ( r, g, b, 1.0f );
  const osg::Vec4 ambient ( diffuse );

  osg::ref_ptr < osg::Material > mat ( new osg::Material );

  mat->setAmbient   ( osg::Material::FRONT_AND_BACK, ambient );
  mat->setDiffuse   ( osg::Material::FRONT_AND_BACK, diffuse );
  mat->setEmission  ( osg::Material::FRONT_AND_BACK, osg::Vec4 ( 0.0f, 0.0f, 0.0f, 1.0f ) );
  mat->setSpecular  ( osg::Material::FRONT_AND_BACK, osg::Vec4 ( 0.2f, 0.2f, 0.2f, 1.0f ) );
  mat->setShininess ( osg::Material::FRONT_AND_BACK, 100 );

  return mat.release();
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get a default material.
//
///////////////////////////////////////////////////////////////////////////////

osg::Material *State::getMaterialDefault()
{
  osg::ref_ptr < osg::Material > mat ( new osg::Material );

  mat->setAmbient   ( osg::Material::FRONT_AND_BACK, osg::Vec4 ( 1.0f, 1.0f, 1.0f, 1.0f ) );
  mat->setDiffuse   ( osg::Material::FRONT_AND_BACK, osg::Vec4 ( 1.0f, 1.0f, 1.0f, 1.0f ) );
  mat->setEmission  ( osg::Material::FRONT_AND_BACK, osg::Vec4 ( 0.0f, 0.0f, 0.0f, 1.0f ) );
  mat->setSpecular  ( osg::Material::FRONT_AND_BACK, osg::Vec4 ( 0.2f, 0.2f, 0.2f, 1.0f ) );
  mat->setShininess ( osg::Material::FRONT_AND_BACK, 100 );

  return mat.release();
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the material.
//
///////////////////////////////////////////////////////////////////////////////

void State::setMaterial ( osg::Node *node, osg::Material *mat )
{
  // Handle bad input.
  if ( ( nullptr == node ) || ( nullptr == mat ) )
  {
    return;
  }

  OsgTools::State::setMaterial ( node->getOrCreateStateSet(), mat );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the material.
//
///////////////////////////////////////////////////////////////////////////////

void State::setMaterial ( osg::StateSet *ss, osg::Material *mat )
{
  // Handle bad input.
  if ( ( nullptr == ss ) || ( nullptr == mat ) )
  {
    return;
  }

  ss->setAttributeAndModes ( mat, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the alpha. Add default material if needed.
//
///////////////////////////////////////////////////////////////////////////////

void State::setAlpha ( osg::Node *node, float alpha, bool createMaterialIfNeeded )
{
  // Handle bad input.
  if ( nullptr == node )
  {
    return;
  }

  osg::ref_ptr < osg::StateSet > ss ( node->getOrCreateStateSet() );
  OsgTools::State::setAlpha ( ss.get(), alpha, createMaterialIfNeeded );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the alpha. Add default material if needed.
//
///////////////////////////////////////////////////////////////////////////////

void State::setAlpha ( osg::StateSet *ss, float alpha, bool createMaterialIfNeeded )
{
  // Handle bad input.
  if ( nullptr == ss )
  {
    return;
  }

  // Get the material attribute.
  osg::ref_ptr < osg::Material > mat ( dynamic_cast < osg::Material * > ( ss->getAttribute ( osg::StateAttribute::MATERIAL ) ) );

  // Set a default material if there isn't one.
  if ( false == mat.valid() )
  {
    // Are we supposed to skip this?
    if ( false == createMaterialIfNeeded )
    {
      return;
    }

    // If we get to here then make a default material.
    OsgTools::State::setMaterial ( ss, OsgTools::State::getMaterialDefault() );
    mat = dynamic_cast < osg::Material * > ( ss->getAttribute ( osg::StateAttribute::MATERIAL ) );
  }

  // Check.
  if ( false == mat.valid() )
  {
    return;
  }

  // Set these other properties if it's not completely opaque.
  if ( alpha < 1 )
  {
    ss->setMode ( GL_BLEND, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON );
    ss->setRenderingHint ( osg::StateSet::TRANSPARENT_BIN );
  }

  // Set the alpha.
  mat->setAlpha ( osg::Material::FRONT_AND_BACK, alpha );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the back face culling state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getBackFaceCulling ( const osg::StateSet *ss )
{
  // Handle bad input
  if ( nullptr == ss )
  {
    return false;
  }

  // Query the mode.
  return Usul::Bits::has ( ss->getMode ( GL_CULL_FACE ), static_cast < GLModeValue > ( osg::StateAttribute::ON ) );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the back face culling state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setBackFaceCulling ( osg::StateSet *ss, bool state )
{
  // Handle bad input
  if ( nullptr == ss )
  {
    return;
  }

  // Apply the mode settings
  ss->setMode ( GL_CULL_FACE, static_cast < GLModeValue > ( ( state ) ? osg::StateAttribute::ON : osg::StateAttribute::OFF ) | osg::StateAttribute::OVERRIDE );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the back face culling state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getBackFaceCulling ( const osg::Node *node )
{
  return State::getBackFaceCulling ( ( node ) ? node->getStateSet() : nullptr );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the back face culling state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setBackFaceCulling ( osg::Node *node, bool state )
{
  State::setBackFaceCulling ( ( node ) ? node->getOrCreateStateSet() : nullptr, state );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Remove the material, if there is any.
//
///////////////////////////////////////////////////////////////////////////////

void State::removeMaterial ( osg::Node *node )
{
  if ( nullptr != node )
  {
    OsgTools::State::removeMaterial ( node->getStateSet() );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Remove the material, if there is any.
//
///////////////////////////////////////////////////////////////////////////////

void State::removeMaterial ( osg::StateSet *ss )
{
  // Handle bad input
  if ( nullptr == ss )
  {
    return;
  }

  // Remove the material.
  ss->removeAttribute ( osg::StateAttribute::MATERIAL );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Update the flags.
//
//  This is a work-around for the counterintuitive way OSG implements
//  NodeVisitor::validNodeMask().
//
///////////////////////////////////////////////////////////////////////////////

namespace Details
{
  void updateFlags ( osg::Node *node )
  {
    if ( nullptr != node )
    {
      const bool state = (
        ( true == Usul::Bits::has ( node->getNodeMask(), OsgTools::Flags::VISIBLE ) ) &&
        ( true == Usul::Bits::has ( node->getNodeMask(), OsgTools::Flags::PICKABLE ) )
      );
      node->setNodeMask ( Usul::Bits::set ( node->getNodeMask(), OsgTools::Flags::VISIBLE_AND_PICKABLE, state ) );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the visible state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getVisible ( const osg::Node *node )
{
  return ( node ? Usul::Bits::has ( node->getNodeMask(), OsgTools::Flags::VISIBLE ) : false );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the visible state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setVisible ( osg::Node *node, bool state )
{
  if ( nullptr != node )
  {
    // http://forum.openscenegraph.org/viewtopic.php?t=5445
    node->setNodeMask ( Usul::Bits::set ( node->getNodeMask(), OsgTools::Flags::VISIBLE, state ) );
    Details::updateFlags ( node );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get the pickable state.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getPickable ( const osg::Node *node )
{
  return ( node ? Usul::Bits::has ( node->getNodeMask(), OsgTools::Flags::PICKABLE ) : false );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Set the pickable state.
//
///////////////////////////////////////////////////////////////////////////////

void State::setPickable ( osg::Node *node, bool state )
{
  if ( nullptr != node )
  {
    // http://forum.openscenegraph.org/viewtopic.php?t=5445
    node->setNodeMask ( Usul::Bits::set ( node->getNodeMask(), OsgTools::Flags::PICKABLE, state ) );
    Details::updateFlags ( node );
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Prevent the given node from contributing to the bounds.
//
///////////////////////////////////////////////////////////////////////////////

namespace Details
{
  struct LocalComputeBoundingSphereCallback : public osg::Node::ComputeBoundingSphereCallback
  {
    typedef osg::Node::ComputeBoundingSphereCallback BaseClass;

    LocalComputeBoundingSphereCallback() : BaseClass()
    {
    }

    virtual osg::BoundingSphere computeBound ( const osg::Node & ) const override
    {
      // The invalid bounding sphere gets rejected.
      return osg::BoundingSphere();
    }
  };
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get whether or not the node contributes to the bounds.
//
///////////////////////////////////////////////////////////////////////////////

bool State::getContributeToBounds ( const osg::Node *node )
{
  // Shortcuts.
  typedef osg::Node::ComputeBoundingSphereCallback BaseCB;
  typedef OsgTools::Details::LocalComputeBoundingSphereCallback LocalCB;

  // Handle invalid node.
  if ( nullptr == node )
  {
    return false;
  }

  // Get the existing callback, if any.
  const BaseCB *cb = node->getComputeBoundingSphereCallback();

  // Is it ours?
  const LocalCB *lcb = dynamic_cast < const LocalCB * > ( cb );

  // We are contributing to the bounds if the callback is not ours.
  return ( nullptr != lcb );
}


///////////////////////////////////////////////////////////////////////////////
//
//  Get whether or not the node contributes to the bounds.
//
///////////////////////////////////////////////////////////////////////////////

void State::setContributeToBounds ( osg::Node *node, bool state )
{
  // Shortcuts.
  typedef osg::Node::ComputeBoundingSphereCallback BaseCB;
  typedef OsgTools::Details::LocalComputeBoundingSphereCallback LocalCB;

  // Handle invalid node.
  if ( nullptr == node )
  {
    return;
  }

  // Get the existing callback, if any.
  BaseCB *cb = node->getComputeBoundingSphereCallback();

  // Is it ours?
  const LocalCB *lcb = dynamic_cast < const LocalCB * > ( cb );

  // If there is already a callback, and it is not ours, then do nothing.
  // Otherwise, we may replace an important callback set by the application.
  if ( ( nullptr != cb ) && ( nullptr == lcb ) )
  {
    return;
  }

  // If we get to here then make the node re-compute its bounds.
  node->dirtyBound();

  // If we are supposed to contribute then just make sure there is no callback.
  if ( true == state )
  {
    node->setComputeBoundingSphereCallback ( nullptr );
    return;
  }

  // If we get to here then set the callback.
  node->setComputeBoundingSphereCallback ( new LocalCB );
}


} // namespace OsgTools
