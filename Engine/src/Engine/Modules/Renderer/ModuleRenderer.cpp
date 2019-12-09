#include "ModuleRenderer.h"
#include <Application.h>
#include <Log/Log.h>

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
		bool ReturnValue(false);

		mAPI = RenderAPI::Create();
		if (mAPI != nullptr)
		{
			ReturnValue = mAPI->Init();
		}
		else
		{
			ENGINE_CORE_ERROR("Failed to create Renderer");
		}
		
		return ReturnValue;
	}

	bool ModuleRenderer::Update()
	{
		bool ReturnValue(false);

		if (mAPI != nullptr)
		{
			ReturnValue = mAPI->Update();
		}

		return ReturnValue;
	}

	bool ModuleRenderer::CleanUp()
	{
		bool ReturnValue(false);

		if (mAPI != nullptr)
		{
			ReturnValue = mAPI->CleanUp();
		}

		return ReturnValue;
	}
	bool ModuleRenderer::Awake()
	{
		return true;
	}
	bool ModuleRenderer::PreUpdate()
	{
		return true;
	}
	bool ModuleRenderer::PostUpdate()
	{
		return true;
	}
	void ModuleRenderer::OnEvent(MemoryBuffer& aData)
	{
		//Handle window resize
	}
}
