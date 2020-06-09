#ifndef ENGINE_ECS_COMPONENT_MANAGER
#define ENGINE_ECS_COMPONENT_MANAGER

#include "Core.h"
#include "ECS/Entity/Entity.h"
#include "ECS/ECSCommon.h"
#include "ECS/Component/IComponentManager.h"
#include "ECS/Component/ComponentManagerHelper.h"

namespace rubEngine
{
	namespace ECS
	{

		template<typename TComponentType>
		class ENGINE_API ComponentManager : public IComponentManager
		{
		public:
			ComponentManager() :
				IComponentManager()
			{
				assert(mFamilyId == UNASIGNED_COMPONENT_FAMILY_ID, "Tried to add same component manager type %s twice", typeid(TComponentType));

				mFamilyId = ComponentFamilyIdGenerator::GenerateNewId();
			}

			virtual ~ComponentManager() {};

			void AddComponent(Entity* apEntity, const TComponentType& aComponent)
			{
				apEntity->SetComponent(mFamilyId, &mComponentsContainer.mComponents.at(mComponentsContainer.mSize));

				mEntitiesLookUp.Refresh(mComponentsContainer.mSize, apEntity);
				mComponentsContainer.mComponents.at(mComponentsContainer.mSize++) = aComponent;
			}
			
			virtual void RemoveComponent(Entity* apEntity) override
			{
				unsigned int ComponentToRemovePosition = mEntitiesLookUp.GetComponentPosition(apEntity);
				unsigned int LastComponentPosition = mComponentsContainer.mSize - 1U;
				mComponentsContainer.mComponents.at(ComponentToRemovePosition) = mComponentsContainer.mComponents.at(LastComponentPosition);
				mComponentsContainer.mSize--;

				Entity* ComponentMovedEntity = mEntitiesLookUp.GetEntity(LastComponentPosition);
				mEntitiesLookUp.Remove(ComponentToRemovePosition, apEntity);
				apEntity->RemoveComponent(mFamilyId);

				if (mComponentsContainer.mSize > 0U)
				{
					mEntitiesLookUp.Refresh(ComponentToRemovePosition, ComponentMovedEntity);
					ComponentMovedEntity->SetComponent(mFamilyId, &mComponentsContainer.mComponents.at(ComponentToRemovePosition));
				}
			}

			static tComponentFamilyId GetFamilyId()
			{
				assert(mFamilyId != UNASIGNED_COMPONENT_FAMILY_ID, "Tried to use a component manager with type %s not added to the system", typeid(TComponentType));
				return mFamilyId;
			}

		private:
			sComponentsContainer<TComponentType>		mComponentsContainer;
			sEntitiesLookUp								mEntitiesLookUp;
			static tComponentFamilyId					mFamilyId;
		};

		template<typename TComponentType>
		tComponentFamilyId ComponentManager<TComponentType>::mFamilyId = UNASIGNED_COMPONENT_FAMILY_ID;

	}
}

#endif