#ifndef ENGINE_ECS_MANAGER
#define ENGINE_ECS_MANAGER

#include <vector>
#include <memory>

#include "Core.h"
#include "Utilities/BitMask.h"

#include "ECS/Entity/EntityManager.h"
#include "ECS/Component/ComponentManager.h"
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		class System;

		class Entity;

		class ENGINE_API ECSManager
		{
		public:

			ECSManager();
			~ECSManager();

			void PreUpdate(float aDeltaTime);
			void Update(float aDeltaTime);
			void PostUpdate(float aDeltaTime);

			std::shared_ptr<Entity> CreateEntity();
			void RemoveEntity(std::shared_ptr<Entity> apEntity);

			template <typename TComponentType>
			void AddComponentManager()
			{
				mComponentManagers.push_back(std::make_unique<ComponentManager<TComponentType>>());
			}

			template <typename TComponentType>
			void AddComponent(std::shared_ptr<Entity> apEntity, TComponentType&& aComponent)
			{
				BitMask OldComponentsMask;
				mEntityManager.GetEntityComponentsMask(*apEntity.get(), OldComponentsMask);

				ComponentManager<TComponentType>* pComponentManager = GetComponentManager<TComponentType>();
				pComponentManager->AddComponent(apEntity.get(), aComponent);

				BitMask NewComponentsMask = OldComponentsMask;
				NewComponentsMask.SetBit(pComponentManager->GetFamilyId());

				//TODO improvement: Another function to do this when all components added to a entity when initializing it. This way we avoid calls to system
				RefreshSystemsEntity(apEntity, OldComponentsMask, NewComponentsMask);
			}
			
			template <typename TComponentType>
			void RemoveComponent(std::shared_ptr<Entity> apEntity)
			{
				BitMask OldComponentsMask;
				mEntityManager.GetEntityComponentsMask(*apEntity.get(), OldComponentsMask);

				ComponentManager<TComponentType>* pComponentManager = GetComponentManager<TComponentType>();
				pComponentManager->RemoveComponent(apEntity.get());

				BitMask NewComponentsMask = OldComponentsMask;
				NewComponentsMask.ClearBit(pComponentManager->GetFamilyId());

				RefreshSystemsEntity(apEntity, OldComponentsMask, NewComponentsMask);
			}

			void AddSystem(std::unique_ptr<System> apSystem);

			template<typename TComponentType, typename ...TComponentTypeArgs>
			void GetEntityComponents(std::shared_ptr<Entity> apEntity, TComponentType& aComponent, TComponentTypeArgs&... aComponents)
			{
				unsigned int ComponentFamily = ComponentManager<TComponentType>::GetFamilyId();
				aComponent = apEntity->GetComponent<TComponentType>(ComponentFamily);
				GetEntityComponents<TComponentTypeArgs...>(apEntity, aComponents...);
			}
			template<typename TComponentType>
			void GetEntityComponents(std::shared_ptr<Entity> apEntity, TComponentType& aComponent)
			{
				unsigned int ComponentFamily = ComponentManager<TComponentType>::GetFamilyId();
				aComponent = apEntity->GetComponent<TComponentType>(ComponentFamily);
			}

		private:
			typedef std::vector<std::unique_ptr<System>>				tSystemContainer;
			typedef std::vector<std::unique_ptr<IComponentManager>>		tComponentManagerContainer;

			template<typename TComponentType>
			ComponentManager<TComponentType>* GetComponentManager()
			{
				unsigned int FamilyID = ComponentManager<TComponentType>::GetFamilyId();
				return static_cast<ComponentManager<TComponentType>*>(mComponentManagers.at(FamilyID).get());
			}

			void RefreshSystemsEntity(std::shared_ptr<Entity> apEntity, const BitMask& aOldComponentsMask, const BitMask& aNewComponentsMask);

			tSystemContainer				mSystems;
			tComponentManagerContainer		mComponentManagers;
			EntityManager					mEntityManager;
		};
	}
}

#endif