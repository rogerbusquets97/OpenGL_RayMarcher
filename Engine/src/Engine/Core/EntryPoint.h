#pragma once

#ifdef PLATFORM_WINDOWS
extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	ENGINE_CORE_INFO("Engine Start");
	auto app = Engine::CreateApplication();

	if (app->Init())
	{
		bool Exit(false);

		while (!Exit)
		{
			Exit = !app->Run();
		}

		app->CleanUp();
	}
	else
	{
		ENGINE_CORE_ERROR("Failed to Initialize engine");
	}

	delete app;
}
#endif