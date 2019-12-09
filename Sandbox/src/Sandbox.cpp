#include <Engine.h>
#include <Engine/Modules/Window/ModuleWindow.h>
#include <Engine/Modules/Renderer/ModuleRenderer.h>

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
		AddModule(new Engine::ModuleWindow(this));
		AddModule(new Engine::ModuleRenderer(this));
	}

	~Sandbox()
	{

	}
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}