#include <Engine.h>
#include <Engine/Modules/Window/ModuleWindow.h>
#include <Engine/Modules/Renderer/ModuleRenderer.h>
#include <Engine/Modules/Camera/ModuleCamera.h>
#include <Engine/Modules/ECS/ModuleECS.h>

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		AddModule(new Engine::ModuleWindow(this));
		AddModule(new Engine::ModuleRenderer(this));
		AddModule(new Engine::ModuleCamera(this));
		AddModule(new Engine::ModuleECS(this));
	}

	~Sandbox()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}