#include "WindowEventsContainer.h"
#include "Events/Event.h"

namespace Engine
{
	WindowEventsContainer::WindowEventsContainer() :
		mMouseEvent(std::make_shared<Event<int, int>>()),
		mResizeWindowsEvent(std::make_shared<Event<unsigned int, unsigned int>>())
	{

	}

	const WindowEventsContainer::KeyActionContainer& WindowEventsContainer::GetKeyActionContainer()
	{
		return mKeyActionContainer;
	}

	void WindowEventsContainer::SetKeyActionContainer(const WindowEventsContainer::KeyActionContainer& aKeyActionContainer)
	{
		mKeyActionContainer = aKeyActionContainer;
	}

	const WindowEventsContainer::KeyIdContainer& WindowEventsContainer::GetKeyIdContainer()
	{
		return mKeyIdContainer;
	}

	void WindowEventsContainer::SetKeyIdContainer(const WindowEventsContainer::KeyIdContainer& aKeyIdContainer)
	{
		mKeyIdContainer = aKeyIdContainer;
	}
}