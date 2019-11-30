#include "RenderAPI.h"
#include "../../Log/Log.h"

namespace Engine
{
	RENDER_API RenderAPI::mCurrentAPI = RENDER_API::OPENGL;

	RenderAPI* RenderAPI::Create()
	{
		switch (mCurrentAPI)
		{
			case RENDER_API::None: ENGINE_CORE_ERROR("Engine API None not supported"); return nullptr;
			case RENDER_API::OPENGL: return nullptr;//return openglrenderer
			case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DIRECTX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API"); 
		return nullptr;
	}

}