#include "WindowEventsContainer.h"
#include "Events/Event.h"
#include <assert.h>

namespace Engine
{
	WindowEventsContainer::WindowEventsContainer() :
		mMouseEvent(std::make_shared<Event<int, int>>()),
		mResizeWindowsEvent(std::make_shared<Event<unsigned int, unsigned int>>()),
		mKeyEvent(std::make_shared<Event<KeyId, KeyAction>>())
	{

	}

	const WindowEventsContainer::KeyActionContainer& WindowEventsContainer::GetKeyActionContainer()
	{
		return mKeyActionContainer;
	}

	const KeyAction& WindowEventsContainer::GetKeyAction(int aKeyAction)
	{
		KeyActionContainer::const_iterator KeyActionIterator = mKeyActionContainer.find(aKeyAction);
		assert(KeyActionIterator != mKeyActionContainer.end(), "Key action %u not mapped", aKeyAction);
		return KeyActionIterator->second;
	}

	void WindowEventsContainer::SetKeyActionContainer(const WindowEventsContainer::KeyActionContainer& aKeyActionContainer)
	{
		mKeyActionContainer = aKeyActionContainer;
	}

	const WindowEventsContainer::KeyIdContainer& WindowEventsContainer::GetKeyIdContainer()
	{
		return mKeyIdContainer;
	}

	const KeyId& WindowEventsContainer::GetKeyId(int aKeyId)
	{
		KeyIdContainer::const_iterator KeyIdIterator = mKeyIdContainer.find(aKeyId);
		assert(KeyIdIterator != mKeyIdContainer.end(), "Key id %u not mapped", aKeyId);
		return KeyIdIterator->second;
	}

	void WindowEventsContainer::SetKeyIdContainer(const WindowEventsContainer::KeyIdContainer& aKeyIdContainer)
	{
		mKeyIdContainer = aKeyIdContainer;
	}
}