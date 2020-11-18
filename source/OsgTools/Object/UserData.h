
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2020, Perry L Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Class for object user-data.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_OBJECT_USER_DATA_CLASS_H_
#define _OSG_TOOLS_OBJECT_USER_DATA_CLASS_H_

#include "OsgTools/Export.h"

#include "Usul/Tools/NoCopying.h"

#include "osg/Referenced"


namespace OsgTools {
namespace Object {


template < class T > class UserData : public osg::Referenced,
  public Usul::Tools::NoCopying
{
public:

  // Useful typedefs.
  typedef osg::Referenced BaseClass;

  // Constructors.
  UserData() : BaseClass(), _v()
  {
  }
  UserData ( const T &v ) : BaseClass(), _v ( v )
  {
  }

  // Access to the value.
  const T &get() const { return _v; }
  T &      get()       { return _v; }

protected:

  // Use reference counting.
  virtual ~UserData()
  {
  }

private:

  T _v;
};


} // namespace Object
} // namespace OsgTools


#endif // _OSG_TOOLS_OBJECT_USER_DATA_CLASS_H_
