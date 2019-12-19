#ifndef ENGINE_WINDOW_EVENTS_CONTAINER
#define ENGINE_WINDOW_EVENTS_CONTAINER

#include <Core.h>

namespace Engine
{
	template<typename ...Args>
	class Event;

	class ENGINE_API WindowEventsContainer
	{
	public:

		WindowEventsContainer();
		
		~WindowEventsContainer() {}


		std::shared_ptr<Event<int, int>>						mMouseEvent;
		std::shared_ptr<Event<unsigned int, unsigned int>>		mResizeWindowsEvent;

	};

}

#endif

