#ifndef _EXPORT_MACRO
#define _EXPORT_MACRO


#ifdef _WINDOWS

#ifdef DLLEXPORT_CORE_MODULES_
#define DLLCORE_API  __declspec(dllexport)
#else
#define DLLCORE_API __declspec(dllimport)
#endif

#else
#define DLLCORE_API  
#endif

#endif