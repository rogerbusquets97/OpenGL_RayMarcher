#ifndef ENGINE_WINDOW_EVENTS_CONTAINER
#define ENGINE_WINDOW_EVENTS_CONTAINER

#include <Core.h>
#include <unordered_map>
#include "Inputs.h"

namespace Engine
{
	template<typename ...Args>
	class Event;

	class ENGINE_API WindowEventsContainer
	{
	public:

		typedef std::unordered_map<int, MouseButton>		MouseButtonContainer;
		typedef std::unordered_map<int, InputAction>		InputActionContainer;
		typedef std::unordered_map<int, KeyId>				KeyIdContainer;


		WindowEventsContainer();
		
		~WindowEventsContainer() {}

		const MouseButtonContainer& GetMouseButtonContainer();
		const MouseButton& GetMouseButton(int aMouseButton);
		void SetMouseButtonContainer(const MouseButtonContainer& aMouseButton);
		
		const InputActionContainer& GetInputActionContainer();
		const InputAction& GetInputAction(int aInputAction);
		void SetInputActionContainer(const InputActionContainer& aInputActionContainer);
		
		const KeyIdContainer& GetKeyIdContainer();
		const KeyId& GetKeyId(int aKeyId);
		void SetKeyIdContainer(const KeyIdContainer& aKeyIdContainer);


		std::shared_ptr<Event<float, float>>					mCursorMovedEvent;
		std::shared_ptr<Event<MouseButton, InputAction>>		mMouseButtonEvent;
		std::shared_ptr<Event<unsigned int, unsigned int>>		mResizeWindowsEvent;
		std::shared_ptr<Event<KeyId, InputAction>>				mKeyEvent;
		std::shared_ptr<Event<const std::string&>>				mDroppedFileEvent;

	private:

		MouseButtonContainer									mMouseButtonContainer;
		InputActionContainer									mInputActionContainer;
		KeyIdContainer											mKeyIdContainer;
	};

}

#endif

