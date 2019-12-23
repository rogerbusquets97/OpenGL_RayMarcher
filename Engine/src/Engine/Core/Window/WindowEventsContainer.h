#ifndef ENGINE_WINDOW_EVENTS_CONTAINER
#define ENGINE_WINDOW_EVENTS_CONTAINER

#include <Core.h>
#include <unordered_map>
#include "Keys.h"

namespace Engine
{
	template<typename ...Args>
	class Event;

	class ENGINE_API WindowEventsContainer
	{
	public:

		typedef std::unordered_map<int, KeyAction>			KeyActionContainer;
		typedef std::unordered_map<int, KeyId>				KeyIdContainer;


		WindowEventsContainer();
		
		~WindowEventsContainer() {}

		const KeyActionContainer& GetKeyActionContainer();
		void SetKeyActionContainer(const KeyActionContainer& aKeyActionContainer);
		
		const KeyIdContainer& GetKeyIdContainer();
		void SetKeyIdContainer(const KeyIdContainer& aKeyIdContainer);


		std::shared_ptr<Event<int, int>>						mMouseEvent;
		std::shared_ptr<Event<unsigned int, unsigned int>>		mResizeWindowsEvent;
		std::shared_ptr<Event<KeyAction, KeyId>>				mKeyEvent;

	private:

		KeyActionContainer										mKeyActionContainer;
		KeyIdContainer											mKeyIdContainer;
	};

}

#endif

