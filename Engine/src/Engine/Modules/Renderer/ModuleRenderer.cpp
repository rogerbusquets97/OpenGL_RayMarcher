#include "ModuleRenderer.h"
#include "../../Core/Application.h"

namespace Engine
{
	ModuleRenderer::ModuleRenderer(Application* aApplication) : Module("Renderer", aApplication)
	{
	}


	ModuleRenderer::~ModuleRenderer()
	{
	}

	bool ModuleRenderer::Init()
	{
		return false;
	}

	bool ModuleRenderer::Update()
	{
		return false;
	}

	bool ModuleRenderer::CleanUp()
	{
		return false;
	}
	void ModuleRenderer::OnEvent(EventData& aData)
	{
	}
}
