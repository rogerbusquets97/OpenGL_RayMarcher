#include "EventHandler.h"

namespace Engine
{

	int EventHandler::counter = 0U;

	EventHandler::EventHandler(const Func& aFunc)
	{
		this->id = ++EventHandler::counter;
		this->mFunc = aFunc;
	}
	void EventHandler::operator()(MemoryBuffer& aData)
	{
		this->mFunc(aData);
	}
	void EventHandler::operator=(const EventHandler& aFunc)
	{
		if (this->mFunc == nullptr)
		{
			this->mFunc = aFunc;
			this->id = ++EventHandler::counter;
		}
	}
	bool EventHandler::operator==(const EventHandler& aHandler)
	{
		return this->id == aHandler.id;
	}
	bool EventHandler::operator!=(nullptr_t)
	{
		return this->mFunc != nullptr;
	}

}