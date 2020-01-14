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
			mEntities()
		{
			//TODO remove this, just checks. Should implement some unit test system
			ComponentManager<int> compManager;
			Entity* ent = CreateEntity();
			compManager.AddComponent(ent, 2U);
			RemoveComponent<int>(ent);
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

		Entity* ECSManager::CreateEntity()
		{
			return new Entity(0U);//TODO
		}

		void ECSManager::RemoveEntity(Entity* apEntity)
		{

		}

		void ECSManager::AddComponentManager(std::unique_ptr<IComponentManager> apComponentManager)
		{
			mComponentManagers.push_back(std::move(apComponentManager));
		}

		template <typename TComponentType>
		void ECSManager::RemoveComponent(Entity* apEntity)
		{
			unsigned int FamilyID = ComponentManager<TComponentType>::GetFamilyId();
			auto pComponentManager = static_cast<ComponentManager<TComponentType>*>(mComponentManagers.at(FamilyID).get());
			pComponentManager->RemoveComponent(apEntity);
		}

		void ECSManager::AddSystem(std::unique_ptr<System> apSystem)
		{
			mSystems.push_back(std::move(apSystem));
		}

		template<typename TComponentType, typename ...TComponentTypeArgs>
		void ECSManager::GetEntityComponentManagers(Entity* apEntity, TComponentType& aComponentManager, TComponentTypeArgs&... aComponentManagers)
		{
			unsigned int ComponentFamily = ComponentManager<TComponentType>::GetFamilyId();
			aComponentManager = apEntity->GetComponent<TComponentType>(ComponentFamily);
			GetEntityComponentManagers<TComponentTypeArgs...>(apEntity, aComponentManager...);
		}
	
		template<typename TComponentType>
		void ECSManager::GetEntityComponentManagers(Entity* apEntity, TComponentType& aComponentManager)
		{
			unsigned int ComponentFamily = ComponentManager<TComponentType>::GetFamilyId();
			aComponentManager = apEntity->GetComponent<TComponentType>(ComponentFamily);
		}
	}
}
