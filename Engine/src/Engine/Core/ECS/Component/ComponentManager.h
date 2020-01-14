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
		public:
			IComponentManager() {};
			virtual ~IComponentManager() {};
			IComponentManager(const IComponentManager&) = default;
			IComponentManager& operator=(const IComponentManager&) = default;
		};

		struct ComponentFamilyIdGenerator
		{
			static unsigned int GenerateNewId()
			{
				return mFamilyId++;
			}
			static unsigned int mFamilyId;
		};
		unsigned int ComponentFamilyIdGenerator::mFamilyId = 0U;

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
			typedef unsigned int tComponentPosition;

			Entity* GetEntity(tComponentPosition aComponentPosition) const
			{
				return mComponentsToEntities.at(aComponentPosition);
			}

			tComponentPosition GetComponentPosition(Entity* apEntity) const
			{
				return mEntitiesToComponents.at(apEntity);
			}

			void Remove(tComponentPosition aComponentPosition, Entity* const apEntity)
			{
				mComponentsToEntities.erase(aComponentPosition);
				mEntitiesToComponents.erase(apEntity);
			}

			void Refresh(tComponentPosition aComponentPosition, Entity* const apEntity)
			{
				mComponentsToEntities.at(aComponentPosition) = apEntity;
				mEntitiesToComponents.at(apEntity) = aComponentPosition;
			}

		private:
			typedef std::unordered_map<Entity*, tComponentPosition>		tEntitiesToComponents;
			typedef std::unordered_map<tComponentPosition, Entity*>		tComponentsToEntities;

			tEntitiesToComponents mEntitiesToComponents;
			tComponentsToEntities mComponentsToEntities;
		};

		template<typename TComponentType>
		class ENGINE_API ComponentManager : public IComponentManager
		{
		public:
			ComponentManager() :
				IComponentManager()
			{
				mFamilyId = ComponentFamilyIdGenerator::GenerateNewId();
			}

			virtual ~ComponentManager() {};

			void AddComponent(Entity* apEntity, const TComponentType& aComponent)
			{
				mEntitiesLookUp.Refresh(mComponentsContainer.mSize, apEntity);
				mComponentsContainer.mComponents.at(mComponentsContainer.mSize++) = aComponent;
			}
			
			void RemoveComponent(Entity* apEntity)
			{
				unsigned int ComponentToRemovePosition = mEntitiesLookUp.GetComponentPosition(apEntity);
				unsigned int LastComponentPosition = mComponentsContainer.mSize - 1U;
				mComponentsContainer.mComponents.at(ComponentToRemovePosition) = mComponentsContainer.mComponents.at(LastComponentPosition);
				mComponentsContainer.mSize--;

				Entity* ComponentMovedEntity = mEntitiesLookUp.GetEntity(LastComponentPosition);
				mEntitiesLookUp.Remove(ComponentToRemovePosition, apEntity);
				mEntitiesLookUp.Refresh(ComponentToRemovePosition, ComponentMovedEntity);

				apEntity->RemoveComponent(mFamilyId);
				ComponentMovedEntity->SetComponent(mFamilyId, &mComponentsContainer.mComponents[ComponentToRemovePosition]);
			}

			static unsigned int GetFamilyId()
			{
				return mFamilyId;
			}

		private:
			sComponentsContainer<TComponentType>		mComponentsContainer;
			sEntitiesLookUp								mEntitiesLookUp;
			static unsigned int							mFamilyId;
		};
	}
}

#endif
