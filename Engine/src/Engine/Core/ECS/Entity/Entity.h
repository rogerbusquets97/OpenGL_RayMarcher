#ifndef ENGINE_ECS_ENTITY
#define ENGINE_ECS_ENTITY

#include "Core.h"
#include <map>

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
			TComponent& GetComponent(unsigned int aComponentFamilyId) const;

			void RemoveComponent(unsigned int aComponentFamilyId);
			
			template <typename TComponent>
			void SetComponent(unsigned int aComponentFamilyId, TComponent* apComponent);


			tEntityId			mId;

		private:

			typedef std::map<tEntityId, void*> tComponentsLookUp;


			tComponentsLookUp	mComponentsLookUp; //!< Map to obtain a component pointer from its family id.
		};
	}
}

#endif 
