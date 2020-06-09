#pragma once
#include <Core.h>
#include <Window/Window.h>

namespace rubEngine
{
	class ENGINE_API GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static std::shared_ptr<GraphicsContext> Create(void* aWindow);
	};
}

