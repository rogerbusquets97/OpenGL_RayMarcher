#ifndef ENGINE_ECS_SYSTEM
#define ENGINE_ECS_SYSTEM

#include "Core.h"
#include <vector>
#include <memory>
#include "Utilities/BitMask.h"
#include "ECS/ECSCommon.h"

namespace Engine
{
	namespace ECS
	{
		class ECSManager;
		class Entity;

		class ENGINE_API System
		{
		public:

			System(ECSManager& aECSManager);
			virtual ~System();

			virtual void PreUpdate(float aDeltaTime) = 0;
			virtual void Update(float aDeltaTime) = 0;
			virtual void PostUpdate(float aDeltaTime) = 0;

			void AddEntity(std::shared_ptr<Entity> apEntity);
			void RemoveEntity(std::shared_ptr<Entity> apEntity);

			template<typename TCurrentComponentType, typename TNextComponentType, typename ...TComponentTypeArgs>
			void GenerateComponentsMask()
			{
				mComponentsMask.SetBit(ComponentManager<TCurrentComponentType>::GetFamilyId());
				GenerateComponentsMask<TNextComponentType, TComponentTypeArgs...>();
			}
			template<typename TCurrentComponentType>
			void GenerateComponentsMask()
			{
				mComponentsMask.SetBit(ComponentManager<TCurrentComponentType>::GetFamilyId());
			}

			const BitMask& GetComponentsMask() const;

		protected:

			typedef std::vector<std::shared_ptr<Entity>>	tEntitiesContainer;

			tEntitiesContainer		mEntities;			//!< Contains the entities the system must interact with. TODO make this a map?
			ECSManager&				mECSManager;		//!< Pointer to the manager.

		private:

			BitMask					mComponentsMask;	//!< Contains the components family this system cares about.
		};
	}
}

#endif
