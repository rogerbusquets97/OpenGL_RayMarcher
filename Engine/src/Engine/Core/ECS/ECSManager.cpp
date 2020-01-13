#include "ECS/ECSManager.h"
#include "ECS/Component/ComponentManager.h"
#include "ECS/System/System.h"

namespace Engine
{
	namespace ECS
	{

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
