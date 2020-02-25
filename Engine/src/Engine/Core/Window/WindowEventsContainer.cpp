#include "WindowEventsContainer.h"
#include "Events/Event.h"
#include <assert.h>

namespace Engine
{
	WindowEventsContainer::WindowEventsContainer() :
		mCursorMovedEvent(std::make_shared<Event<float, float>>()),
		mMouseButtonEvent(std::make_shared<Event<MouseButton, InputAction>>()),
		mResizeWindowsEvent(std::make_shared<Event<unsigned int, unsigned int>>()),
		mKeyEvent(std::make_shared<Event<KeyId, InputAction>>()),
		mDroppedFileEvent(std::make_shared<Event<const std::string&>>())
	{

	}

	const WindowEventsContainer::MouseButtonContainer& WindowEventsContainer::GetMouseButtonContainer()
	{
		return mMouseButtonContainer;
	}

	const MouseButton& WindowEventsContainer::GetMouseButton(int aInputAction)
	{
		MouseButtonContainer::const_iterator MousseButtonIterator = mMouseButtonContainer.find(aInputAction);
		assert(MousseButtonIterator != mMouseButtonContainer.end(), "Mouse button %u not mapped", aInputAction);
		return MousseButtonIterator->second;
	}

	void WindowEventsContainer::SetMouseButtonContainer(const WindowEventsContainer::MouseButtonContainer& aMouseButtonContainer)
	{
		mMouseButtonContainer = aMouseButtonContainer;
	}

	const WindowEventsContainer::InputActionContainer& WindowEventsContainer::GetInputActionContainer()
	{
		return mInputActionContainer;
	}

	const InputAction& WindowEventsContainer::GetInputAction(int aInputAction)
	{
		InputActionContainer::const_iterator InputActionIterator = mInputActionContainer.find(aInputAction);
		assert(InputActionIterator != mInputActionContainer.end(), "Input action %u not mapped", aInputAction);
		return InputActionIterator->second;
	}

	void WindowEventsContainer::SetInputActionContainer(const WindowEventsContainer::InputActionContainer& aInputActionContainer)
	{
		mInputActionContainer = aInputActionContainer;
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