#ifndef ENGINE_ECS_ENTITY
#define ENGINE_ECS_ENTITY

#include "Core.h"
#include <map>
#include "ECS/ECSCommon.h"

namespace Engine
{
	namespace ECS
	{

		class ENGINE_API Entity
		{
		public:
			typedef unsigned int tEntityId;

			Entity(tEntityId aId);
			~Entity();

			template <typename TComponent>
			TComponent& GetComponent(tComponentFamilyId aComponentFamilyId) const;

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
