#pragma once
#include <Application.h>
#include <chrono>

#ifdef PLATFORM_WINDOWS
extern const std::unique_ptr<rubEngine::Application>& rubEngine::CreateApplication();

int main(int argc, char** argv)
{

	rubEngine::Log::Init();
	ENGINE_CORE_INFO("rubEngine Start");
	const std::unique_ptr<rubEngine::Application>& App = rubEngine::CreateApplication();

	if (App->Init())
	{
		bool Exit(false);

		unsigned int FPS = 60U; //TODO parameterize this
		float IdealDeltaTime = 1.0f / static_cast<float>(FPS);

		auto PreviousTime = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::time_point CurrentTime;
		float DeltaTime;
		float LagTime = 0.0f;

		while (!Exit)
		{
			CurrentTime = std::chrono::high_resolution_clock::now();
			DeltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(CurrentTime - PreviousTime).count();
			PreviousTime = CurrentTime;
			LagTime += DeltaTime;

			while (LagTime >= IdealDeltaTime)
			{
				Exit |= !App->Run(IdealDeltaTime);
				LagTime -= IdealDeltaTime;
			}

			//TODO special treatment for render module, should have just the update method and call it here LagTime/ IdealDeltaTime
		}

		App->CleanUp();
	}
	else
	{
		ENGINE_CORE_ERROR("Failed to Initialize engine");
	}
}
#endif