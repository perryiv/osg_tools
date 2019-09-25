
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Base class for all builders of primitive shapes.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_BUILDERS_PRIMITIVE_CLASS_H_
#define _OSG_TOOLS_BUILDERS_PRIMITIVE_CLASS_H_

#include "OsgTools/Builders/Builder.h"

#include "osg/Vec3d"
#include "osg/Vec3f"
#include "osg/Vec4d"
#include "osg/Vec4f"


namespace OsgTools {
namespace Builders {


class OSG_TOOLS_EXPORT Primitive : public Builder
{
public:

  typedef Builder BaseClass;
  typedef BaseClass::Options Options;

  ~Primitive();

  const osg::Vec4d &getColor() const { return _color; };
  void              setColor ( const osg::Vec4d & );
  void              setColor ( const osg::Vec4f & );
  void              setColor ( double r, double g, double b, double a );
  void              setColor ( float r, float g, float b, float a );

  const osg::Vec3d &getCenter() const { return _center; };
  void              setCenter ( const osg::Vec3d & );
  void              setCenter ( const osg::Vec3f & );
  void              setCenter ( double x, double y, double z );
  void              setCenter ( float x, float y, float z );

protected:

  Primitive();
  Primitive ( const Options & );
  Primitive ( const Options::Values & );

private:

  osg::Vec3d _center;
  osg::Vec4d _color;
};


} // namespace Builders
} // namespace OsgTools


#endif // _OSG_TOOLS_BUILDERS_PRIMITIVE_CLASS_H_
