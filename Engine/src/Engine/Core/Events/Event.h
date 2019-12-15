#ifndef ENGINE_EVENT
#define ENGINE_EVENT

#include <vector>
#include "Core.h"
#include "Events/EventHandler.h"

namespace Engine
{

	enum class eEventType
	{
		KeyPressed,
		WindowResize,
		MouseButtonPressed,
		None
	};


	class ENGINE_API Event
	{
	public:

		void AddHandler(const EventHandler& aHandler);
		void RemoveHandler(const EventHandler& aHandler);
		void operator()(MemoryBuffer& aData);
		Event& operator+=(const EventHandler& aHandler);
		Event& operator+=(const EventHandler::Func& aHandler);
		Event& operator-=(const EventHandler& aHandler);
	private:
		void Notify(MemoryBuffer& aData);
	private:
		std::vector<EventHandler*> mHandlers;
	};
}

#endif