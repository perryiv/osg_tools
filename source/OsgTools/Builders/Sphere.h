
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

#include "OsgTools/Builders/Primitive.h"


namespace OsgTools {
namespace Builders {


class Sphere : public Primitive
{
public:

  typedef Primitive BaseClass;
  typedef BaseClass::Options Options;

  Sphere();
  Sphere ( const Options & );
  ~Sphere();

  virtual osg::Node *build();
  static  osg::Node *build ( const Options & );

  double getRadius() const { return _radius; }
  void   setRadius ( double radius );
  void   setRadius ( float radius );

private:

  double _radius;
};


} // namespace Builders
} // namespace OsgTools


#endif // _OSG_TOOLS_BUILDERS_SPHERE_CLASS_H_
