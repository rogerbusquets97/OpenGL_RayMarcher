#ifndef ENGINE_IALLOCATOR
#define ENGINE_IALLOCATOR

#include "Core.h"

namespace rubEngine
{
	class ENGINE_API IAllocator
	{
		//TODO inherited classes	https://www.gamedev.net/articles/programming/general-and-gameplay-programming/c-custom-memory-allocation-r3010/
		//							https://gameprogrammingpatterns.com/object-pool.html

		virtual ~IAllocator() {}

		virtual void* Allocate(size_t aSize);
		
		virtual void Clear ();

	};
}

#endif
