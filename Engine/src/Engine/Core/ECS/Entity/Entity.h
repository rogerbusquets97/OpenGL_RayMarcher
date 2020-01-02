#ifndef ENGINE_ECS_ENTITY
#define ENGINE_ECS_ENTITY

#include "Core.h"

namespace Engine
{
	namespace ECS
	{

		struct ENGINE_API Entity
		{
			typedef unsigned int tEntityId;
			
			tEntityId	mId;
		};
	}
}

#endif 
