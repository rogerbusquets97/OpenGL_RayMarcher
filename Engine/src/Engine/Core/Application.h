#pragma once
#include "Core.h"
#include <vector>
#include <Module.h>
#include "Window/Inputs.h"
#include <map>
#include "CSingleton.h"

namespace rubEngine
{
	class ResourceManager;

	class ENGINE_API Application : public CSingleton<Application>
	{
	public:
		Application();
		virtual ~Application();
		bool Run(float aDeltaTime);
		bool Init();
		bool CleanUp();

		template<typename T>
		void AddModule()
		{
			static_assert(std::is_base_of<Module, T>::value, "Added modules must inherit from base class Module");
			mModules.emplace(typeid(T).hash_code(), std::make_unique<T>());
		}

		template<typename T>
		const T* GetModule()
		{
			static_assert(std::is_base_of<Module, T>::value, "Cannont retrieve a non Module module!");
			size_t HashCode = typeid(T).hash_code();

			if (mModules.find(HashCode) != mModules.end())
			{
				return static_cast<T*>(mModules.at(HashCode).get());
			}

			return nullptr;
		}
		
		void OnCursorMovedEvent(float aXPos, float aYPos);
		void OnMouseButtonEvent(MouseButton aMouseButton, InputAction aInputAction);
		void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight);
		void OnKeyWindowEvent(KeyId aKeyId, InputAction aInputAction);
		void OnFileDropped(const std::string& aPath);
	
	private:		
		std::map<size_t, std::unique_ptr<Module>> mModules;
	};

	//Defined by client
	const std::unique_ptr<Application>& CreateApplication();
}



