#include "ComponentManagerHelper.h"
#include "ECS/Entity/Entity.h"

namespace Engine
{
	namespace ECS
	{
		tComponentFamilyId ComponentFamilyIdGenerator::mFamilyId = 0U;


		sEntitiesLookUp::sEntitiesLookUp() :
			mEntitiesToComponents(),
			mComponentsToEntities()
		{

		}


		Entity* sEntitiesLookUp::GetEntity(tComponentPosition aComponentPosition) const
		{
			return mComponentsToEntities.at(aComponentPosition);
		}

		sEntitiesLookUp::tComponentPosition sEntitiesLookUp::GetComponentPosition(Entity* apEntity) const
		{
			return mEntitiesToComponents.at(apEntity);
		}

		void sEntitiesLookUp::Remove(tComponentPosition aComponentPosition, Entity* const apEntity)
		{
			mComponentsToEntities.erase(aComponentPosition);
			mEntitiesToComponents.erase(apEntity);
		}

		void sEntitiesLookUp::Refresh(tComponentPosition aComponentPosition, Entity* const apEntity)
		{
			mComponentsToEntities[aComponentPosition] = apEntity;
			mEntitiesToComponents[apEntity] = aComponentPosition;
		}
	}
}