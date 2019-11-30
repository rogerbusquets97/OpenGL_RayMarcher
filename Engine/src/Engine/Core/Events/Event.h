#pragma once
#include "../Core.h"
#include <vector>
#include <memory>
#include <functional>

namespace Engine
{
	class ENGINE_API EventHandler
	{
	public:
		using Func = std::function<void(EventData&)>;

		EventHandler() : id(0) {}
		EventHandler(const Func &aFunc) : mFunc(aFunc)
		{
			this->id = ++EventHandler::counter;
		}

		void operator()(EventData& aData)
		{
			this->mFunc(aData);
		}

		void operator=(const EventHandler &aFunc)
		{
			if (this->mFunc == nullptr)
			{
				this->mFunc = aFunc;
				this->id = ++EventHandler::counter;
			}
		}

		bool operator==(const EventHandler &aHandler)
		{
			return this->id == aHandler.id;
		}

		bool operator!=(nullptr_t)
		{
			return this->mFunc != nullptr;
		}

	public:
		int id;
		static int counter;
	private:
		Func mFunc;
	};

	class ENGINE_API Event
	{
	public:

		void AddHandler(const EventHandler& aHandler)
		{
			this->mHandlers.push_back(std::unique_ptr<EventHandler>(new EventHandler(aHandler)));
		}

		void RemoveHandler(const EventHandler& aHandler)
		{
			auto ToRemove = std::find(mHandlers.begin(), mHandlers.end(), aHandler);
			mHandlers.erase(ToRemove);
		}

		void operator()(EventData& aData)
		{
			this->Notify(aData);
		}

		Event& operator+=(const EventHandler aHandler)
		{
			this->AddHandler(aHandler);
			return *this;
		}

		Event& operator+=(const EventHandler::Func& aHandler)
		{
			this->AddHandler(EventHandler(aHandler));
			return *this;
		}

		Event& operator-=(const EventHandler& aHandler)
		{
			this->RemoveHandler(aHandler);
			return *this;
		}

	private:
		void Notify(EventData& aData)
		{
			for (auto& Handler : mHandlers)
			{
				if (Handler != nullptr && (Handler)->id != 0)
				{
					(*Handler)(aData);
				}
			}
		}
	private:
		std::vector<std::unique_ptr<EventHandler>> mHandlers;
	};
}