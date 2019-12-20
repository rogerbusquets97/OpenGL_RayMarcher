#pragma once
#include <iostream>

#ifdef PLATFORM_WINDOWS
	#ifdef DYNAMIC_LINK
		#ifdef BUILD_DLL
			#define ENGINE_API __declspec(dllexport)
		#else 
			#define ENGINE_API __declspec(dllimport)
		#endif
	#else
	#define ENGINE_API
	#endif
#else
	#error Only Windows supported!
#endif

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)