#pragma once


#ifdef _WINDOWS

#ifdef DLLEXPORT_ERROR_LOGGER
#define ERROR_API  __declspec(dllexport)
#else
#define ERROR_API __declspec(dllimport)
#endif

#else
#define ERROR_API  
#endif
