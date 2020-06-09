#include "GraphicsContext.h"
#include "OpenGL/OpenGLContext.h"
#include "RenderAPI.h"
#include <Log/Log.h>
#include <Window/GLWindow.h>

namespace rubEngine
{
	std::shared_ptr<GraphicsContext> GraphicsContext::Create(void* aWindow)
	{
		switch (RenderAPI::GetAPI())
		{
			case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
			case RENDER_API::OPENGL: return std::make_shared<OpenGLContext>(static_cast<GLFWwindow*>(aWindow));
			case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}
}
