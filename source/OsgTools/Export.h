
///////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2019, Perry L. Miller IV
//  All rights reserved.
//  MIT License: https://opensource.org/licenses/mit-license.html
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//  Defines what OSG_TOOLS_EXPORT means.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _OSG_TOOLS_DLL_EXPORT_H_
#define _OSG_TOOLS_DLL_EXPORT_H_

#ifdef _WIN32
# ifdef COMPILING_OSG_TOOLS
#   define OSG_TOOLS_EXPORT __declspec ( dllexport ) // We are compiling this library so the classes are exported.
# else
#   define OSG_TOOLS_EXPORT __declspec ( dllimport ) // The classes will be imported into the client's code.
# endif
#else // Not _WIN32
# define OSG_TOOLS_EXPORT
#endif

#endif // _OSG_TOOLS_DLL_EXPORT_H_
