#include "GameObject.h"

rubEngine::GameObject::GameObject(const std::string& aName, GameObject* aParent) : mName(aName), mChildren(), mParent(aParent), mComponents(), mActive(true), mStatic(true)
{
}

rubEngine::GameObject::~GameObject()
{
	for (auto& Child : mChildren)
	{
		delete Child;
	}

	for (auto& Component : mComponents)
	{
		delete Component;
	}
}

void rubEngine::GameObject::AddChild(GameObject* aChild)
{
	mChildren.push_back(aChild);
}

void rubEngine::GameObject::AddComponent(Component* aComponent)
{
	mComponents.push_back(aComponent);
	aComponent->Init();
}

bool rubEngine::GameObject::Update(float aDeltaTime)
{
	bool Result = true;

	for (auto& Component : mComponents)
	{
		Result &= Component->Update(aDeltaTime);
	}

	return Result;
}
