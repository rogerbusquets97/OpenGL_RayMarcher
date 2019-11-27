#pragma once
#include "Log.h"

#ifdef PLATFORM_WINDOWS
extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	Engine::Log::Init();
	ENGINE_CORE_INFO("Engine Start");
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}
#endif