#pragma once
#include <string>
#include <vector>
#include <memory>
#include <Components/Component.h>

namespace Engine
{
	class GameObject
	{
	public:
		GameObject(const std::string& aName, GameObject* aParent = nullptr);
		~GameObject();
		void AddChild(GameObject* aChild);
		void AddComponent(Component* aComponent);
		bool Update();
	private:
		std::string mName;
		std::vector<GameObject*> mChildren;
		GameObject* mParent;
		std::vector<Component*> mComponents;
		bool mActive;
		bool mStatic;
	};
}