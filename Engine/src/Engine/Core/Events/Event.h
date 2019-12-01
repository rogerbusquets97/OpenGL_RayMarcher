#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "../Core.h"

namespace Engine
{
	enum EVENT_TYPE
	{
		KEY_PRESSED,
		WINDOW_RESIZE,
		MOUSE_BUTTON_PRESSED,
		NONE
	};

	class ENGINE_API EventData
	{
		public: 
			EventData(EVENT_TYPE aType) : mType(aType) {}
			EVENT_TYPE GetType() { return mType; }
		private:
			EVENT_TYPE mType;
	};

	class ENGINE_API KeyPressedEvent : public EventData
	{
		public:

			KeyPressedEvent(int aKey, int aAction) : EventData(EVENT_TYPE::KEY_PRESSED), mKey(aKey), mAction(aAction)
			{
			}

			inline int GetKey() const { return mKey; }
			inline int GetAction() const { return mAction; }

		private:
			int mKey;
			int mAction;
	};

	class ENGINE_API MouseButtonPressedEvent : public EventData
	{
		public:
			
			MouseButtonPressedEvent(int aButton, int aAction, int aMouseX, int aMouseY) : EventData(EVENT_TYPE::MOUSE_BUTTON_PRESSED), mButton(aButton), mAction(aAction), mMouseX(aMouseX), mMouseY(aMouseY)
			{}

			inline int GetButton() const { return mButton; }
			inline int GetAction() const { return mAction; }
			inline int GetMouseX() const { return mMouseX; }
			inline int GetMouseY() const { return mMouseY; }
		private:
			int mButton;
			int mAction;
			int mMouseX, mMouseY;
	};

	class ENGINE_API EventHandler
	{
	public:
		using Func = std::function<void(EventData&)>;

		EventHandler() : id(0) {}
		EventHandler(const Func &aFunc);
	

		void operator()(EventData& aData);

		void operator=(const EventHandler &aFunc);

		bool operator==(const EventHandler &aHandler);

		bool operator!=(nullptr_t);

	public:
		int id;
		static int counter;
	private:
		std::function<void(EventData&)> mFunc;
	};

	class ENGINE_API Event
	{
	public:

		void AddHandler(const EventHandler& aHandler);
		void RemoveHandler(const EventHandler& aHandler);
		void operator()(EventData& aData);
		Event& operator+=(const EventHandler aHandler);
		Event& operator+=(const EventHandler::Func& aHandler);
		Event& operator-=(const EventHandler& aHandler);
	private:
		void Notify(EventData& aData);
	private:
		std::vector<EventHandler*> mHandlers;
	};
}