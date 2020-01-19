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
		TComponent& Entity::GetComponent(tComponentFamilyId aComponentFamilyId) const
		{
			tComponentsLookUp::iterator ComponentIterator = mComponentsLookUp.find(aComponentFamilyId);
			assert(ComponentIterator->second != mComponentsLookUp.end(), "Entity with id %d does not have any component from family %d", mId, aComponentFamilyId);
			return *static_cast<TComponent*>(ComponentIterator->second);
		}

		void Entity::RemoveComponent(tComponentFamilyId aComponentFamilyId)
		{
			mComponentsLookUp.erase(aComponentFamilyId);
		}

		void Entity::ObtainComponentFamilies(tComponentFamilyIds& aComponentFamilies) const
		{
			for (const auto& ComponentsIterator : mComponentsLookUp)
			{
				aComponentFamilies.push_back(ComponentsIterator.first);
			}
		}
	}
}