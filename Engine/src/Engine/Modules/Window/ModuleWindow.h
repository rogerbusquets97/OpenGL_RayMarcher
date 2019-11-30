#pragma once
#include "../../Core/Core.h"
#include "../../Core/Application.h"
#include "../Module.h"

namespace Engine
{
	class ENGINE_API ModuleWindow : Module
	{
	public:
		ModuleWindow(Application* aApplication);
		virtual ~ModuleWindow();

		virtual bool Init() override;
		virtual bool Update() override;
		virtual bool CleanUp() override;
	};
}

