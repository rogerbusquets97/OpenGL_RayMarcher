#include "WindowEventsContainer.h"
#include "Events/Event.h"

namespace Engine
{
	WindowEventsContainer::WindowEventsContainer() :
		mMouseEvent(std::make_shared<Event<int, int>>()),
		mResizeWindowsEvent(std::make_shared<Event<unsigned int, unsigned int>>())
	{

	}
}