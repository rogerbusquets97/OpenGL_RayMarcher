#include "GameObject.h"

Engine::GameObject::GameObject(const std::string& aName, GameObject* aParent) : mName(aName), mChildren(), mParent(aParent), mComponents(), mActive(true), mStatic(true)
{
}

Engine::GameObject::~GameObject()
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

void Engine::GameObject::AddChild(GameObject* aChild)
{
	mChildren.push_back(aChild);
}

void Engine::GameObject::AddComponent(Component* aComponent)
{
	mComponents.push_back(aComponent);
	aComponent->Init();
}

bool Engine::GameObject::Update()
{
	for (auto& Component : mComponents)
	{
		Component->Update();
	}
}
