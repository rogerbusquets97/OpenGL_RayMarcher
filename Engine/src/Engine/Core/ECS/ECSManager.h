#ifndef ENGINE_ECS_HANDLER
#define ENGINE_ECS_HANDLER

#include "Core.h"
#include <vector>
#include <memory>
#include "Entity/EntityManager.h"

namespace Engine
{
	namespace ECS
	{
		class System;
		class IComponentManager;

		template <typename TComponentType>
		class ComponentManager;

		class IComponentManager;
		class Entity;
		class Component;

		class ENGINE_API ECSManager
		{
		public:

			ECSManager();
			~ECSManager();

			typedef std::vector<std::unique_ptr<IComponentManager>>	tComponentManagerContainer;

			void PreUpdate(float aDeltaTime);
			void Update(float aDeltaTime);
			void PostUpdate(float aDeltaTime);

			std::shared_ptr<Entity> CreateEntity();
			void RemoveEntity(std::shared_ptr<Entity> apEntity);

			template <typename TComponentType>
			void AddComponentManager();

			template <typename TComponentType>
			void AddComponent(std::shared_ptr<Entity> apEntity, TComponentType&& aComponent);
			
			template <typename TComponentType>
			void RemoveComponent(std::shared_ptr<Entity> apEntity);

			void AddSystem(std::unique_ptr<System> apSystem);

			template<typename TComponentType, typename ...TComponentTypeArgs>
			void GetEntityComponents(std::shared_ptr<Entity> apEntity, TComponentType& aComponent, TComponentTypeArgs&... aComponents);

		private:
			typedef std::vector<std::unique_ptr<System>>				tSystemContainer;

			template<typename TComponentType>
			void GetEntityComponent(std::shared_ptr<Entity> apEntity, TComponentType& aComponent);

			template<typename TComponentType>
			ComponentManager<TComponentType>* GetComponentManager();


			tSystemContainer				mSystems;
			tComponentManagerContainer		mComponentManagers;
			EntityManager					mEntityManager;
		};
	}
}

#endif