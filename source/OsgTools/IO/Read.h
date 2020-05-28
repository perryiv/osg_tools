
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//	Read a file using OSG's plugins and call a progress callback.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_IO_READ_FUNCTIONS_H_
#define _OSG_TOOLS_IO_READ_FUNCTIONS_H_

#include "OsgTools/Export.h"
#include "OsgTools/Forward.h"

#include <functional>
#include <string>


namespace OsgTools {
namespace IO {


// Helper class to make exporting symbols easier on Windows.
struct OSG_TOOLS_EXPORT Reader
{
  typedef std::function < void ( std::uint64_t, std::uint64_t ) > ProgressFunction;
  static osgDB::ReaderWriter *findReader ( const std::string &file );
  static osg::Node *read ( const std::string &file, ProgressFunction fun );
};

// The progress function type.
// It should be the same as Usul::File::Buffer::ProgressFunction.
typedef Reader::ProgressFunction ProgressFunction;

// Find the appropriate reader.
// You probably don't need this function but it's here in case you do.
inline osgDB::ReaderWriter *findReader ( const std::string &file ) { return Reader::findReader ( file ); }

// Read the file.
inline osg::Node *read ( const std::string &file, ProgressFunction fun ) { return Reader::read ( file, fun ); }


} // namespace IO
} // namespace OsgTools


#endif // _OSG_TOOLS_IO_READ_FUNCTIONS_H_
