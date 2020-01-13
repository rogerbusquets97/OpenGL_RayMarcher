#include "ECS/ECSManager.h"
#include "ECS/Component/ComponentManager.h"
#include "ECS/System/System.h"
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		ECSManager::ECSManager():
			mpSystems(),
			mpComponentManagers(),
			mpEntities()
		{

		}

		ECSManager::~ECSManager()
		{

		}


		void ECSManager::PreUpdate(float aDeltaTime)
		{
			for (auto& pSystem : mpSystems)
			{
				pSystem->PreUpdate(aDeltaTime);
			}
		}

		void ECSManager::Update(float aDeltaTime)
		{
			for (auto& pSystem : mpSystems)
			{
				pSystem->Update(aDeltaTime);
			}
		}

		void ECSManager::PostUpdate(float aDeltaTime)
		{
			for (auto& pSystem : mpSystems)
			{
				pSystem->PostUpdate(aDeltaTime);
			}
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
