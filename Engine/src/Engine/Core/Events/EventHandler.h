#ifndef ENGINE_EVENT_HANDLER
#define ENGINE_EVENT_HANDLER

#include <functional>
#include <memory>
#include "Core.h"

namespace Engine
{
	template<typename... Args>
	class ENGINE_API EventHandler
	{
	public:
		typedef std::function<void(Args...)> tHandlerFunction;

		EventHandler() : mId(0U) 
		{
		}

		EventHandler(const tHandlerFunction& aFunc)
		{
			mId = ++EventHandler::mCounter;
			mFunc = aFunc;
		}


		void operator()(Args... aArgs) const
		{
			mFunc(aArgs...);
		}

		void operator=(const EventHandler& aFunc)
		{
			if (mFunc == nullptr)
			{
				mFunc = aFunc;
				mId = ++EventHandler::mCounter;
			}
		}

		bool operator==(const EventHandler& aHandler)
		{
			return mId == aHandler.mId;
		}

		bool operator!=(nullptr_t)
		{
			return mFunc != nullptr;
		}

	public:
		int mId;
		inline static int mCounter = 0U;

	private:
		tHandlerFunction mFunc;
	};
}

#endif