#ifndef ENGINE_ECS_ENTITY
#define ENGINE_ECS_ENTITY

#include "Core.h"
#include <map>
#include "ECS/ECSCommon.h"

namespace rubEngine
{
	namespace ECS
	{

		class ENGINE_API Entity
		{
		public:
			typedef unsigned int tEntityId;

			Entity(tEntityId aId);
			~Entity();

			tEntityId GetId() const;

			template <typename TComponent>
			TComponent& GetComponent(tComponentFamilyId aComponentFamilyId) const
			{
				tComponentsLookUp::const_iterator ComponentIterator = mComponentsLookUp.find(aComponentFamilyId);
				assert(ComponentIterator != mComponentsLookUp.end(), "Entity with id %d does not have any component from family %d", mId, aComponentFamilyId);
				return *static_cast<TComponent*>(ComponentIterator->second);
			}

			void RemoveComponent(tComponentFamilyId aComponentFamilyId);
			
			template <typename TComponent>
			void SetComponent(tComponentFamilyId aComponentFamilyId, TComponent* apComponent)
			{
				mComponentsLookUp[aComponentFamilyId] = static_cast<void*>(apComponent);
			}

			void ObtainComponentFamilies(tComponentFamilyIds& aComponentFamilies) const;

			tEntityId			mId;

		private:

			typedef std::map<tComponentFamilyId, void*> tComponentsLookUp;


			tComponentsLookUp	mComponentsLookUp; //!< Map to obtain a component pointer from its family id.
		};
	}
}

#endif 
