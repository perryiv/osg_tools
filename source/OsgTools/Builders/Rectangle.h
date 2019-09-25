
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for building a rectangle.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_BUILDERS_RECTANGLE_CLASS_H_
#define _OSG_TOOLS_BUILDERS_RECTANGLE_CLASS_H_

#include "OsgTools/Builders/Primitive.h"


namespace OsgTools {
namespace Builders {


class OSG_TOOLS_EXPORT Rectangle : public Primitive
{
public:

  typedef Primitive BaseClass;
  typedef BaseClass::Options Options;

  Rectangle();
  Rectangle ( const Options & );
  Rectangle ( const Options::Values & );
  ~Rectangle();

  virtual osg::Node *build();
  static  osg::Node *build ( const Options & );
  static  osg::Node *build ( const Options::Values & );

  double getHeight() const { return _height; }
  void   setHeight ( double height );
  void   setHeight ( float height );

  double getWidth() const { return _width; }
  void   setWidth ( double width );
  void   setWidth ( float width );

private:

  double _height;
  double _width;
};


} // namespace Builders
} // namespace OsgTools


#endif // _OSG_TOOLS_BUILDERS_RECTANGLE_CLASS_H_
