#include "Shader.h"
#include <Renderer/RenderAPI.h>
#include <Log/Log.h>
#include <Renderer/OpenGL/OpenGLShader.h>

namespace Engine
{
	Shader* Shader::Create()
	{
		switch (RenderAPI::GetAPI())
		{
			case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
			case RENDER_API::OPENGL: return new OpenGLShader();
			case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}
}