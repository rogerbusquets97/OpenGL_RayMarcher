#ifndef ENGINE_ECS_COMPONENT_MANAGER
#define ENGINE_ECS_COMPONENT_MANAGER

#include "Core.h"
#include <array>
#include <unordered_map>
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		class ENGINE_API IComponentManager
		{
		};

		template<typename TComponentType>
		struct sComponentsContainer
		{
			unsigned int mSize = 0U;
			std::array<TComponentType, 1024> mComponents;//TODO use custom dynamic allocators? this allocators should be multiple of cache line size somehow to really benefit from ECS
		};

		struct sEntitiesLookUp
		{
			typedef unsigned int tComponentPosition;
			typedef std::unordered_map<Entity*, tComponentPosition>		tEntitiesToComponents;
			typedef std::unordered_map<tComponentPosition, Entity*>		tComponentsToEntities;

			tEntitiesToComponents mEntitiesToComponents;
			tComponentsToEntities mComponentsToEntities;
		};

		template<typename TComponentType>
		class ENGINE_API ComponentManager : public IComponentManager
		{
		public:

			TComponentType& GetEntityComponent(const Entity& aEntity) {
			}//Maybe this is no longer needed

			void AddComponent(const Entity& aEntity, TComponentType aComponent)
			{

			}
			
			void RemoveComponent(const Entity& aEntity)
			{
				unsigned int ComponentToRemovePosition = mEntitiesLookUp.mEntitiesToComponents[aEntity.mId];
				unsigned int LastComponentPosition = mComponentsContainer.mSize - 1U;
				TComponentType LastComponent = mComponentsContainer.mComponents.at(LastComponentPosition);
				mComponentsContainer.mComponents[ComponentToRemovePosition] = LastComponent;
				mComponentsContainer.mSize--;

				//TODO update mEntitiesLookUp

				aEntity.RemoveComponent(mFamilyId);

				Entity* ComponentMovedEntity = mEntitiesLookUp.mComponentsToEntities.at(LastComponentPosition);
				ComponentMovedEntity->SetComponent(mFamilyId, &LastComponent);
			}

		private:
			sComponentsContainer<TComponentType>		mComponentsContainer;
			sEntitiesLookUp								mEntitiesLookUp;
			unsigned int								mFamilyId;//TODO maybe this shouldn't be here
		};
	}
}

#endif
