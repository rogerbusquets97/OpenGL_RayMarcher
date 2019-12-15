#ifndef ENGINE_EVENT_HANDLER
#define ENGINE_EVENT_HANDLER

#include "Memory/MemoryBuffer.h"
#include <functional>
#include <memory>
#include "Core.h"

namespace Engine
{
	class ENGINE_API EventHandler
	{
	public:
		using Func = std::function<void(MemoryBuffer&)>;

		EventHandler() : id(0U) {}
		EventHandler(const Func& aFunc);


		void operator()(MemoryBuffer& aData);

		void operator=(const EventHandler& aFunc);

		bool operator==(const EventHandler& aHandler);

		bool operator!=(nullptr_t);

	public:
		int id;
		static int counter;
	private:
		std::function<void(MemoryBuffer&)> mFunc;
	};
}

#endif