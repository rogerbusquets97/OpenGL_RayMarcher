#include "Event.h"

namespace Engine
{
	
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
	void Event::operator()(MemoryBuffer & aData)
	{
		this->Notify(aData);
	}
	Event & Event::operator+=(const EventHandler& aHandler)
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

	void Event::Notify(MemoryBuffer & aData)
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