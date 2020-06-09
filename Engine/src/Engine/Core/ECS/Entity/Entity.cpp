#include "ECS/Entity/Entity.h"

namespace rubEngine
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

		Entity::tEntityId Entity::GetId() const
		{
			return mId;
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