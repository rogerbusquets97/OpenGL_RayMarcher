#ifndef ENGINE_ECS_COMMON
#define ENGINE_ECS_COMMON

#include <vector>

namespace rubEngine
{
	namespace ECS
	{
		typedef unsigned int tComponentFamilyId;
		typedef std::vector<tComponentFamilyId> tComponentFamilyIds;

		const tComponentFamilyId UNASIGNED_COMPONENT_FAMILY_ID = 0xFFFFFFFF;
	}
}

#endif