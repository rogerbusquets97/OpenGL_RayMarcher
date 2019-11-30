#pragma once
#include "../Module.h"
#include "../../Core/Core.h"
#include "../../Core/Application.h"

namespace Engine
{
	class ENGINE_API ModuleRenderer : public Module
	{
	public:
		ModuleRenderer(Application* aApplication);
		virtual ~ModuleRenderer();

		virtual bool Init() override;
		virtual bool Update() override;
		virtual bool CleanUp() override;
	};
}

