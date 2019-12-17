#ifndef ENGINE_EVENT_TYPES
#define ENGINE_EVENT_TYPES

#include "Event.h"

namespace Engine
{


	typedef Event<int, int> tMouseEvent;
	typedef Event<unsigned int, unsigned int> tResizeWindowEvent;

}

#endif

