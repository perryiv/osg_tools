
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

#ifndef _OSG_TOOLS_STATE_CLASS_H_
#define _OSG_TOOLS_STATE_CLASS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Forward.h"


namespace OsgTools {


struct OSG_TOOLS_EXPORT State
{
  // Get/set the lighting state
  static bool            getLighting  ( const osg::Node * );
  static bool            getLighting  ( const osg::StateSet * );
  static void            setLighting  ( osg::Node *, bool );
  static void            setLighting  ( osg::StateSet *, bool );

  // Set/Get the two sided lighting state.
  static bool            getTwoSidedLighting ( const osg::Node * );
  static bool            getTwoSidedLighting ( const osg::StateSet * );
  static void            setTwoSidedLighting ( osg::Node *, bool );
  static void            setTwoSidedLighting ( osg::StateSet *, bool );

  // Get/set the normalization state.
  static bool            getNormalize ( const osg::Node * );
  static bool            getNormalize ( const osg::StateSet * );
  static void            setNormalize ( osg::Node *, bool );
  static void            setNormalize ( osg::StateSet *, bool );

  // Get/set the polygon state.
  static bool            getPolygonsFilled ( const osg::Node *, bool );
  static void            setPolygonsFilled ( osg::Node *, bool );

  // Make polygons draw with lines.
  static bool            getPolygonsLines ( const osg::Node *, bool );
  static void            setPolygonsLines ( osg::Node *, bool );

  // Make polygons draw with points.
  static bool            getPolygonsPoints ( const osg::Node *, bool );
  static void            setPolygonsPoints ( osg::Node *, bool );

  // Make filled polygons draw with smooth shading.
  static bool            getPolygonsSmooth ( const osg::Node * );
  static void            setPolygonsSmooth ( osg::Node * );

  // Make filled polygons draw with flat shading.
  static bool            getPolygonsFlat ( const osg::Node * );
  static void            setPolygonsFlat ( osg::Node * );

  // Make filled polygons draw with flat shading.
  static bool            getPolygonsTextures ( const osg::StateSet * );
  static void            setPolygonsTextures ( osg::StateSet *, bool );

  // Get/set the polygon mode.
  static bool            getPolygonMode ( const osg::Node *, unsigned int face, unsigned int mode );
  static void            setPolygonMode ( osg::Node *,       unsigned int face, unsigned int mode );

  // Set/Get line width
  static float           getLineWidth ( const osg::StateSet * );
  static float           getLineWidth ( const osg::Node * );
  static void            setLineWidth ( osg::StateSet *, float width );
  static void            setLineWidth ( osg::Node *, float width );

  // Set/Get point size.
  static float           getPointSize ( const osg::StateSet * );
  static float           getPointSize ( const osg::Node * );
  static void            setPointSize ( osg::StateSet *, float size );
  static void            setPointSize ( osg::Node *, float size );

  // Set the states for hidden lines.
  static void            hiddenLines ( const osg::Vec4f &color, osg::StateSet *normal, osg::StateSet *hidden );

  // Materials.
  static osg::Material * getMaterialDefault();
  static osg::Material * getMaterialRandom();
  static void            removeMaterial ( osg::Node * );
  static void            removeMaterial ( osg::StateSet * );
  static void            setMaterial ( osg::Node *, osg::Material * );
  static void            setMaterial ( osg::StateSet *, osg::Material * );

  // Set the alpha value. Adds default material if needed.
  static void            setAlpha ( osg::Node *, float );
  static void            setAlpha ( osg::StateSet *, float );

  // Back face culling.
  static bool            getBackFaceCulling ( const osg::Node * );
  static bool            getBackFaceCulling ( const osg::StateSet * );
  static void            setBackFaceCulling ( osg::Node *, bool );
  static void            setBackFaceCulling ( osg::StateSet *, bool );

  // Get/set the pickable state.
  static bool            getPickable ( const osg::Node * );
  static void            setPickable ( osg::Node *, bool );

  // Get/set the visible state.
  static bool            getVisible ( const osg::Node * );
  static void            setVisible ( osg::Node *, bool );
};


} // namespace OsgTools


#endif // _OSG_TOOLS_STATE_CLASS_H_
