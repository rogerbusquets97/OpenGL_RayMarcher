#pragma once
#include <vector>
#include <memory>
#include <functional>
#include <Core.h>
#include <Memory/MemoryBuffer.h>

namespace Engine
{
	enum EVENT_TYPE
	{
		KEY_PRESSED,
		WINDOW_RESIZE,
		MOUSE_BUTTON_PRESSED,
		NONE
	};

	class ENGINE_API EventHandler
	{
	public:
		using Func = std::function<void(MemoryBuffer&)>;

		EventHandler() : id(0) {}
		EventHandler(const Func &aFunc);
	

		void operator()(MemoryBuffer& aData);

		void operator=(const EventHandler &aFunc);

		bool operator==(const EventHandler &aHandler);

		bool operator!=(nullptr_t);

	public:
		int id;
		static int counter;
	private:
		std::function<void(MemoryBuffer&)> mFunc;
	};

	class ENGINE_API Event
	{
	public:

		void AddHandler(const EventHandler& aHandler);
		void RemoveHandler(const EventHandler& aHandler);
		void operator()(MemoryBuffer& aData);
		Event& operator+=(const EventHandler aHandler);
		Event& operator+=(const EventHandler::Func& aHandler);
		Event& operator-=(const EventHandler& aHandler);
	private:
		void Notify(MemoryBuffer& aData);
	private:
		std::vector<EventHandler*> mHandlers;
	};
}