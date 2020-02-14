#include <gtest/gtest.h>
#include "ECS/ECSManager.h"
#include "ECS/System/System.h"

using namespace Engine;
using namespace Engine::ECS;

TEST(ECSManager, AddRemoveEntity)
{
	ComponentFamilyIdGenerator::mFamilyId = 0U;
	ECSManager Manager;
	Manager.AddComponentManager<int>();
	std::shared_ptr<Entity> ent = Manager.CreateEntity();
	Manager.AddComponent<int>(ent, 2);
	Manager.RemoveEntity(ent);
}

TEST(ECSManager, AddSameTypeComponents)
{
	ComponentFamilyIdGenerator::mFamilyId = 0U;
	ECSManager Manager;
	//EXPECT_EXIT(Manager.AddComponentManager<int>(), ::testing::ExitedWithCode(EXIT_FAILURE), ""); //Added same type from previous test
}

TEST(ECSManager, AddRemoveComponent)
{
	ComponentFamilyIdGenerator::mFamilyId = 0U;
	ECSManager Manager;
	Manager.AddComponentManager<float>();
	std::shared_ptr<Entity> ent = Manager.CreateEntity();
	Manager.AddComponent<float>(ent, 2);
	Manager.RemoveComponent<float>(ent);
}

TEST(ECSManager, AddSystem)
{
	ComponentFamilyIdGenerator::mFamilyId = 0U;

	class DummySystem : public System
	{
	public:
		DummySystem(ECSManager& aECSManager) :
			System(aECSManager)
		{}
		virtual ~DummySystem() {}

		virtual void PreUpdate(float aDeltaTime) override {}
		virtual void Update(float aDeltaTime) override {}
		virtual void PostUpdate(float aDeltaTime) override {}
	};
	ECSManager Manager;
	Manager.AddSystem(std::make_unique<DummySystem>(Manager));
}

TEST(ECSManager, GetEntityComponents)
{
	ComponentFamilyIdGenerator::mFamilyId = 0U;
	ECSManager Manager;
	Manager.AddComponentManager<unsigned int>();
	Manager.AddComponentManager<double>();
	Manager.AddComponentManager<std::string>();
	std::shared_ptr<Entity> ent = Manager.CreateEntity();
	Manager.AddComponent(ent, 2U);
	Manager.AddComponent<double>(ent, 5);
	Manager.AddComponent<std::string>(ent, "nani");

	int Comp0;
	double Comp1;
	std::string Comp2;
	Manager.GetEntityComponents(ent, Comp0, Comp1, Comp2);
	EXPECT_EQ(Comp0, 2U);
	EXPECT_EQ(Comp1, 5);
	EXPECT_EQ(Comp2, "nani");
	
	double Comp3;
	std::string Comp4;
	int Comp5;
	Manager.GetEntityComponents(ent, Comp3, Comp4, Comp5);
	EXPECT_EQ(Comp5, 2U);
	EXPECT_EQ(Comp3, 5);
	EXPECT_EQ(Comp4, "nani");

	std::string Comp6;
	Manager.GetEntityComponents(ent, Comp6);
	EXPECT_EQ(Comp6, "nani");

	std::vector<int> Comp7;
	//EXPECT_ANY_THROW(Manager.GetEntityComponents(ent, Comp7));
}
