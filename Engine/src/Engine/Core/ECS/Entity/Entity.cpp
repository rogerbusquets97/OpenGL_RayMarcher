#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		Entity::Entity(tEntityId aId) :
			mId(aId),
			mComponentsLookUp()
		{
		}

		
		Entity::~Entity()
		{

		}


		template <typename TComponent>
		TComponent& Entity::GetComponent(unsigned int aComponentFamilyId) const
		{
			tComponentsLookUp::iterator ComponentIterator = mComponentsLookUp.find(aComponentFamilyId);
			assert(ComponentIterator->second != mComponentsLookUp.end(), "Entity with id %d does not have any component from family %d", mId, aComponentFamilyId);
			return *static_cast<TComponent*>(ComponentIterator->second);
		}

		void Entity::RemoveComponent(unsigned int aComponentFamilyId)
		{
			mComponentsLookUp.erase(aComponentFamilyId);
		}

		template <typename TComponent>
		void Entity::SetComponent(unsigned int aComponentFamilyId, TComponent* apComponent)
		{
			mComponentsLookUp[aComponentFamilyId] = static_cast<void*>(apComponent);
		}
	}
}