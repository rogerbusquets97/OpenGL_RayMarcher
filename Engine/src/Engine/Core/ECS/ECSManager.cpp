#include "ECS/ECSManager.h"
#include "ECS/Component/ComponentManager.h"
#include "ECS/System/System.h"
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		ECSManager::ECSManager():
			mSystems(),
			mComponentManagers(),
			mEntityManager()
		{
			//TODO remove this, just checks. Should implement some unit test system
			AddComponentManager<int>();
			std::shared_ptr<Entity> ent = CreateEntity();
			AddComponent(ent, 2U);
			//RemoveComponent<int>(ent);
			RemoveEntity(ent);
		}

		ECSManager::~ECSManager()
		{

		}

		void ECSManager::PreUpdate(float aDeltaTime)
		{
			for (auto& pSystem : mSystems)
			{
				pSystem->PreUpdate(aDeltaTime);
			}
		}

		void ECSManager::Update(float aDeltaTime)
		{
			for (auto& pSystem : mSystems)
			{
				pSystem->Update(aDeltaTime);
			}
		}

		void ECSManager::PostUpdate(float aDeltaTime)
		{
			for (auto& pSystem : mSystems)
			{
				pSystem->PostUpdate(aDeltaTime);
			}
		}

		std::shared_ptr<Entity> ECSManager::CreateEntity()
		{
			return mEntityManager.CreateEntity();
		}

		void ECSManager::RemoveEntity(std::shared_ptr<Entity> apEntity)
		{
			tComponentFamilyIds ComponentsFamilies;
			apEntity->ObtainComponentFamilies(ComponentsFamilies);
			for (tComponentFamilyId ComponentFamilyId : ComponentsFamilies)
			{
				mComponentManagers.at(ComponentFamilyId)->RemoveComponent(apEntity.get());
			}

			//TODO Notify systems
		}

		template <typename TComponentType>
		void ECSManager::AddComponentManager()
		{
			mComponentManagers.push_back(std::make_unique<ComponentManager< TComponentType>>());
		}

		template <typename TComponentType>
		void ECSManager::AddComponent(std::shared_ptr<Entity> apEntity, TComponentType&& aComponent)
		{
			ComponentManager<TComponentType>* pComponentManager = GetComponentManager<TComponentType>();
			pComponentManager->AddComponent(apEntity.get(), aComponent);

			//TODO Notify systems
		}

		template <typename TComponentType>
		void ECSManager::RemoveComponent(std::shared_ptr<Entity> apEntity)
		{
			ComponentManager<TComponentType>* pComponentManager = GetComponentManager<TComponentType>();
			pComponentManager->RemoveComponent(apEntity.get());

			//TODO Notify systems
		}

		void ECSManager::AddSystem(std::unique_ptr<System> apSystem)
		{
			mSystems.push_back(std::move(apSystem));
		}

		template<typename TComponentType, typename ...TComponentTypeArgs>
		void ECSManager::GetEntityComponents(std::shared_ptr<Entity>, TComponentType& aComponent, TComponentTypeArgs&... aComponents)
		{
			unsigned int ComponentFamily = ComponentManager<TComponentType>::GetFamilyId();
			aComponent = apEntity->GetComponent<TComponentType>(ComponentFamily);
			GetEntityComponentManagers<TComponentTypeArgs...>(apEntity, aComponents...);
		}
	
		template<typename TComponentType>
		void ECSManager::GetEntityComponent(std::shared_ptr<Entity>, TComponentType& aComponent)
		{
			unsigned int ComponentFamily = ComponentManager<TComponentType>::GetFamilyId();
			aComponent = apEntity->GetComponent<TComponentType>(ComponentFamily);
		}

		template<typename TComponentType>
		ComponentManager<TComponentType>* ECSManager::GetComponentManager()
		{
			unsigned int FamilyID = ComponentManager<TComponentType>::GetFamilyId();
			return static_cast<ComponentManager<TComponentType>*>(mComponentManagers.at(FamilyID).get());
		}
	}
}