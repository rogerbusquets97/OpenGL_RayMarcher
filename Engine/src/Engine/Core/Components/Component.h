#ifndef ENGINE_COMPONENT
#define ENGINE_COMPONENT

namespace rubEngine
{
	class GameObject;

	class Component
	{
	public:
		Component(GameObject* aParent) : mParent(aParent){};
		virtual ~Component() {};
		virtual bool Init() = 0;
		virtual bool Update(float aDeltaTime) = 0;
		virtual bool CleanUp() = 0;

	protected:
		GameObject* mParent;
	};
}

#endif