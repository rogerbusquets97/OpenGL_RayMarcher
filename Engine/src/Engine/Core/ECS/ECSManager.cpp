#include "ECS/ECSManager.h"
#include "ECS/System/System.h"

namespace rubEngine
{
	namespace ECS
	{
		ECSManager::ECSManager():
			mSystems(),
			mComponentManagers(),
			mEntityManager()
		{

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
			BitMask OldComponentsMask;
			mEntityManager.GetEntityComponentsMask(ComponentsFamilies, OldComponentsMask);

			for (tComponentFamilyId ComponentFamilyId : ComponentsFamilies)
			{
				mComponentManagers.at(ComponentFamilyId)->RemoveComponent(apEntity.get());
			}

			RefreshSystemsEntity(apEntity, OldComponentsMask, BitMask());
		}

		void ECSManager::AddSystem(std::unique_ptr<System> apSystem)
		{
			mSystems.push_back(std::move(apSystem));
		}

		void ECSManager::RefreshSystemsEntity(std::shared_ptr<Entity> apEntity, const BitMask& aOldComponentsMask, const BitMask& aNewComponentsMask)
		{
			for (auto& pSystem : mSystems)
			{
				const BitMask& SystemComponentsMask = pSystem ->GetComponentsMask();
				if (SystemComponentsMask == aOldComponentsMask && SystemComponentsMask != aNewComponentsMask)
				{
					pSystem->RemoveEntity(apEntity);
				}
				if (SystemComponentsMask != aOldComponentsMask && SystemComponentsMask == aNewComponentsMask)
				{
					pSystem->AddEntity(apEntity);
				}
			}
		}

	}
}