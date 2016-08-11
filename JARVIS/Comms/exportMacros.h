#pragma once


#ifdef _WINDOWS

#ifdef DLLEXPORT_COMMS_
#define COMMS_API  __declspec(dllexport)
#else
#define COMMS_API __declspec(dllimport)
#endif

#else
#define COMMS_API
#endif

