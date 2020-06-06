
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L Miller IV and John K Grant
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Factory class.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_FACTORY_CLASS_H_
#define _OSG_TOOLS_FACTORY_CLASS_H_

#ifdef _DEBUG

#include "OsgTools/Forward.h"

#include "Usul/Strings/Format.h"

#endif

#include <string>
#include <type_traits>


namespace OsgTools {


///////////////////////////////////////////////////////////////////////////////
//
//  Factory class.
//
///////////////////////////////////////////////////////////////////////////////

template < class ObjectType > struct Factory
{
  #ifdef _DEBUG

  // Return a new object and set it's name.
  static ObjectType *create ( const std::string &name )
  {
    static_assert ( std::is_base_of < osg::Node, ObjectType > ::value,
      "Factory only supports osg::Node and derived classes" );
    ObjectType *obj = new ObjectType;
    obj->setName ( name );
    return obj;
  }

  #else

  // Return a new object.
  static ObjectType *create()
  {
    return new ObjectType;
  }

  #endif
};


} // namespace OsgTools


///////////////////////////////////////////////////////////////////////////////
//
//  Macro that automatically sets the name to the line number and file name.
//
///////////////////////////////////////////////////////////////////////////////

#ifdef _DEBUG

#define OSG_TOOLS_FACTORY_CREATE(object_type) \
  OsgTools::Factory < object_type > ::create ( Usul::Strings::format ( "Line: ", __LINE__, ", File: ", __FILE__ ) )

#else

#define OSG_TOOLS_FACTORY_CREATE(object_type) \
  OsgTools::Factory < object_type > ::create()

#endif


#endif // _OSG_TOOLS_FACTORY_CLASS_H_
