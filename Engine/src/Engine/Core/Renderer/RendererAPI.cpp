#include "RenderAPI.h"
#include <Log/Log.h>
#include <Renderer/OpenGL/OpenGLRenderer.h>

namespace rubEngine
{
	RENDER_API RenderAPI::mCurrentAPI = RENDER_API::OPENGL;

	std::unique_ptr<RenderAPI> RenderAPI::Create()
	{
		switch (mCurrentAPI)
		{
			case RENDER_API::None: ENGINE_CORE_ERROR("rubEngine API None not supported"); return nullptr;
			case RENDER_API::OPENGL: return std::make_unique<OpenGLRenderer>();
			case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DIRECTX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API"); 
		return nullptr;
	}

}