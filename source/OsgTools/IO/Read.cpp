
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2006, 2020 Perry Miller
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//
//  Functions for reading an OSG file.
//
/////////////////////////////////////////////////////////////////////////////

#include "OsgTools/IO/Read.h"

#include "Usul/File/Buffer.h"

#include "osg/ref_ptr"
#include "osg/Node"

#include "osgDB/FileNameUtils"
#include "osgDB/ReadFile"

#include <sstream>
#include <string>


namespace OsgTools {
namespace IO {


// Needed below.
typedef Usul::File::Buffer < char > FileBuffer;


///////////////////////////////////////////////////////////////////////////////
//
//  Find the appropriate reader.
//
///////////////////////////////////////////////////////////////////////////////

osgDB::ReaderWriter *Reader::findReader ( const std::string &file )
{
  // Get file extension.
  const std::string ext ( osgDB::getLowerCaseFileExtension ( file ) );

  // Look for the reader.
  osg::ref_ptr < osgDB::ReaderWriter > reader = osgDB::Registry::instance()->getReaderWriterForExtension ( ext );

  // Handle no reader.
  if ( false == reader.valid() )
  {
    throw std::runtime_error ( std::string ( "Error 1010869612: Could not find reader for file: " ) + file );
  }

  // Return the reader.
  return reader.release();
}


///////////////////////////////////////////////////////////////////////////////
//
//  Read the file.
//
///////////////////////////////////////////////////////////////////////////////

namespace Details
{
  inline osgDB::ReaderWriter::ReadResult read ( const std::string &file, osgDB::ReaderWriter &rw, ProgressFunction fun )
  {
    // Open the file buffer.
    FileBuffer buffer ( file );

    // Set the callback.
    buffer.setProgressFunction ( fun );

    // Use a local scope to make sure the stream is deleted first.
    // Note: This may not be needed.
    {
      // Make the input stream.
      std::istream in ( &buffer );

      // Read the node file.
      return rw.readNode ( in );
    }
  }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Read the file.
//
///////////////////////////////////////////////////////////////////////////////

osg::Node *Reader::read ( const std::string &file, ProgressFunction fun )
{
  // Should be true.
  static_assert ( std::is_same < ProgressFunction, FileBuffer::ProgressFunction > ::value, "Progress callback functions are not the same type" );

  // Find the reader plugin.
  osg::ref_ptr < osgDB::ReaderWriter > reader = Reader::findReader ( file );

  // Use the reader plugin to read the file.
  osgDB::ReaderWriter::ReadResult result = Details::read ( file, *reader, fun );

  // Handle when the plugin does not work with input streams.
  if ( osgDB::ReaderWriter::ReadResult::FILE_NOT_HANDLED == result.status() )
  {
    result = reader->readNode ( file );
  }

  // See if it worked.
  if ( true == result.success() && true == result.validNode() )
  {
    // Take ownership and return the node.
    return result.takeNode();
  }

  // If we get to here then it did not work.
  std::ostringstream out;
  out << "Error 1723158504: Failed to read file: " << file;
  if ( false == result.message().empty() )
  {
    out << ", " << result.message();
  }
  throw std::runtime_error ( out.str() );
}


} // namespace IO
} // namespace OsgTools
