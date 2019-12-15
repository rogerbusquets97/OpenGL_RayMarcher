#ifndef ENGINE_EVENT
#define ENGINE_EVENT

#include <list>
#include "Core.h"
#include "Events/EventHandler.h"

namespace Engine
{
	template<typename... Args>
	class ENGINE_API Event
	{
	public:
		typedef EventHandler<Args...> tHandlerType;
		typedef std::list<tHandlerType> tHandlerContainer;

		void AddHandler(const tHandlerType& aHandler)
		{
			mHandlers.push_back(aHandler);
		}

		void RemoveHandler(const tHandlerType& aHandler)
		{
			auto HandlerToRemoveIterator = std::find(mHandlers.begin(), mHandlers.end(), aHandler);
			if (HandlerToRemoveIterator != mHandlers.end())
			{
				mHandlers.erase(HandlerToRemoveIterator);
			}
		}

		void operator()(Args... aArgs) const
		{
			tHandlerContainer HandlersCopy(mHandlers);
			for (const auto& Handler : HandlersCopy)
			{
				Handler(aArgs...);
			}
		}

		Event& operator+=(const tHandlerType& aHandler)
		{
			AddHandler(aHandler);
			return *this;
		}

		/*Event& operator+=(const tHandlerType::tHandlerFunction& aHandler)
		{
			AddHandler(tHandlerContainer(aHandler));
			return *this;
		}*/

		Event& operator-=(const tHandlerType& aHandler)
		{
			RemoveHandler(aHandler);
			return *this;
		}

	private:
		tHandlerContainer mHandlers;
	};
}

#endif