#ifndef ENGINE_ECS_HANDLER
#define ENGINE_ECS_HANDLER

#include "Core.h"
#include <vector>
#include <memory>

namespace Engine
{
	namespace ECS
	{
		class System;
		class IComponentManager;
		class Entity;
		class Component;

		class ENGINE_API ECSManager
		{
		public:

			ECSManager();
			~ECSManager();

			typedef std::vector< std::unique_ptr<IComponentManager>>	tComponentManagerContainer;

			void PreUpdate(float aDeltaTime);
			void Update(float aDeltaTime);
			void PostUpdate(float aDeltaTime);

			Entity* CreateEntity();
			void RemoveEntity(Entity* apEntity);

			void AddComponent(Component* aComponent);
			void RemoveComponent(Component* aComponent);

			void AddSystem(System* apSystem);
			void RemoveSystem(System* apSystem); //really necessary?

			template<typename TComponentType, typename ...TComponentTypeArgs>
			void GetEntityComponentManagers(Entity* apEntity, TComponentType& aComponentManager, TComponentTypeArgs&... aComponentManagers);

		private:
			typedef std::vector<std::unique_ptr<System>>				tSystemContainer;
			typedef std::vector< std::unique_ptr<Entity>>				tEntityContainer;

			template<typename TComponentType>
			void GetEntityComponentManagers(Entity* apEntity, TComponentType& aComponentManager);

			tSystemContainer				mpSystems;
			tComponentManagerContainer		mpComponentManagers;
			tEntityContainer				mpEntities;
		};
	}
}

#endif