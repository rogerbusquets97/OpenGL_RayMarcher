#include "Event.h"

namespace Engine
{
	int EventHandler::counter;

	EventHandler::EventHandler(const Func & aFunc)
	{
		this->id = ++EventHandler::counter;
	}
	void EventHandler::operator()(EventData & aData)
	{
		this->mFunc(aData);
	}
	void EventHandler::operator=(const EventHandler & aFunc)
	{
		if (this->mFunc == nullptr)
		{
			this->mFunc = aFunc;
			this->id = ++EventHandler::counter;
		}
	}
	bool EventHandler::operator==(const EventHandler & aHandler)
	{
		return this->id == aHandler.id;
	}
	bool EventHandler::operator!=(nullptr_t)
	{
		return this->mFunc != nullptr;
	}
	void Event::AddHandler(const EventHandler & aHandler)
	{
		this->mHandlers.push_back(new EventHandler(aHandler));
	}
	void Event::RemoveHandler(const EventHandler & aHandler)
	{
		std::vector<EventHandler*>::iterator to_remove = this->mHandlers.begin();
		for (; to_remove != this->mHandlers.end(); ++to_remove)
		{
			if (*(*to_remove) == aHandler)
			{
				this->mHandlers.erase(to_remove);
				break;
			}
		}
	}
	void Event::operator()(EventData & aData)
	{
		this->Notify(aData);
	}
	Event & Event::operator+=(const EventHandler aHandler)
	{
		this->AddHandler(aHandler);
		return *this;
	}

	Event & Event::operator+=(const EventHandler::Func & aHandler)
	{
		this->AddHandler(EventHandler(aHandler));
		return *this;
	}

	Event & Event::operator-=(const EventHandler & aHandler)
	{
		this->RemoveHandler(aHandler);
		return *this;
	}

	void Event::Notify(EventData & aData)
	{
		std::vector<EventHandler*>::iterator func = this->mHandlers.begin();
		for (; func != this->mHandlers.end(); ++func)
		{
			if (*func != nullptr && (*func)->id != 0)
			{
				(*(*func))(aData);
			}
		}
	}

}