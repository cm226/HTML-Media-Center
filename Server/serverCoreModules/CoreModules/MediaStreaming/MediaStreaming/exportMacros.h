#pragma once


#ifdef _WINDOWS

#ifdef DLLEXPORT_MEDIA_STREAMER
#define DLLMEDIA_STREAM_API  __declspec(dllexport)
#else
#define DLLMEDIA_STREAM_API __declspec(dllimport)
#endif

#else
#define DLLMEDIA_STREAM_API  
#endif
