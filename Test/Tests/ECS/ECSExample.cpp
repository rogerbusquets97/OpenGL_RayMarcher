#include <gtest/gtest.h>
#include "ECS/ECSManager.h"
#include "ECS/System/System.h"

using namespace rubEngine;
using namespace rubEngine::ECS;


struct ComponentPosition
{
	float x;
	float y;
	float z;
};
struct ComponentVelocity
{
	float x;
	float y;
	float z;
};
struct ComponentDummy
{
	int a; int b; int c; int d; int e; int f; int g; int h; int i; int j;
};

class MoveSystem : public System
{
public:
	MoveSystem(ECSManager& aECSManager) :
		System(aECSManager)
	{}
	virtual ~MoveSystem() {}

	virtual void PreUpdate(float aDeltaTime) override {}
	virtual void Update(float aDeltaTime) override
	{
		for (const auto& Entity : mEntities)
		{
			ComponentPosition Position;
			ComponentVelocity Velocity;
			mECSManager.GetEntityComponents(Entity, Position, Velocity);
			Position.x += Velocity.x * aDeltaTime;
			Position.y += Velocity.y * aDeltaTime;
			Position.z += Velocity.z * aDeltaTime;
		}
	}
	virtual void PostUpdate(float aDeltaTime) override {}
};

TEST(ECSManager, MoveSystem)
{
	ComponentFamilyIdGenerator::mFamilyId = 0U;

	ECSManager Manager;
	Manager.AddComponentManager<ComponentPosition>();
	Manager.AddComponentManager<ComponentDummy>();
	Manager.AddComponentManager<ComponentVelocity>();

	std::unique_ptr<MoveSystem> System = std::make_unique<MoveSystem>(Manager);
	System->GenerateComponentsMask<ComponentPosition, ComponentVelocity>();
	Manager.AddSystem(std::move(System));
	
	const unsigned int TotalEntities = 1024U;
	for (unsigned int NumEnt = 0; NumEnt < TotalEntities; ++NumEnt)
	{
		std::shared_ptr<Entity> ent = Manager.CreateEntity();
		Manager.AddComponent(ent, ComponentPosition({5.f, 5.f, 5.f}));
		Manager.AddComponent(ent, ComponentVelocity({0.f, 1.f, 0.f}));
	}
	Manager.Update(0.5);
}