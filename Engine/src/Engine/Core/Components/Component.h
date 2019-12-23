#pragma once
#include <GameObjects/GameObject.h>

namespace Engine
{
	class Component
	{
	public:
		Component(GameObject* aParent) : mParent(aParent){};
		virtual ~Component() {};
		virtual bool Init() = 0;
		virtual bool Update() = 0;
		virtual bool CleanUp() = 0;

	protected:
		GameObject* mParent;
	};
}
