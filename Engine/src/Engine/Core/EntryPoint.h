#pragma once
#include <Application.h>

#ifdef PLATFORM_WINDOWS
extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	ENGINE_CORE_INFO("Engine Start");
	auto App = Engine::CreateApplication();

	if (App->Init())
	{
		bool Exit(false);

		while (!Exit)
		{
			Exit = !App->Run(0.0f);
		}

		App->CleanUp();
	}
	else
	{
		ENGINE_CORE_ERROR("Failed to Initialize engine");
	}

	delete App;
}
#endif