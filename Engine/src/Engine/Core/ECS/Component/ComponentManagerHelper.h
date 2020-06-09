#ifndef ENGINE_ECS_COMPONENT_MANAGER_HELPER
#define ENGINE_ECS_COMPONENT_MANAGER_HELPER

#include "Core.h"
#include "ECS/ECSCommon.h"
#include <unordered_map>
#include <array>

namespace rubEngine
{
	namespace ECS
	{

		class Entity;

		struct ComponentFamilyIdGenerator
		{
			static tComponentFamilyId GenerateNewId()
			{
				return mFamilyId++;
			}
			static tComponentFamilyId mFamilyId;
		};

		template<typename TComponentType>
		struct sComponentsContainer
		{
		public:
			unsigned int mSize = 0U;
			std::array<TComponentType, 1024> mComponents;//TODO use custom dynamic allocators? this allocators should be multiple of cache line size somehow to really benefit from ECS
		};

		struct sEntitiesLookUp
		{
		public:
			sEntitiesLookUp();

			typedef unsigned int tComponentPosition;

			Entity* GetEntity(tComponentPosition aComponentPosition) const;

			tComponentPosition GetComponentPosition(Entity* apEntity) const;

			void Remove(tComponentPosition aComponentPosition, Entity* const apEntity);

			void Refresh(tComponentPosition aComponentPosition, Entity* const apEntity);

		private:
			typedef std::unordered_map<Entity*, tComponentPosition>		tEntitiesToComponents;
			typedef std::unordered_map<tComponentPosition, Entity*>		tComponentsToEntities;

			tEntitiesToComponents mEntitiesToComponents;
			tComponentsToEntities mComponentsToEntities;
		};
	}
}

#endif