#include "ComputeShader.h"
#include <Renderer/RenderAPI.h>
#include <Log/Log.h>
#include <Renderer/OpenGL/OpenGLComputeShader.h>

namespace Engine
{
	std::shared_ptr<ComputeShader> ComputeShader::Create()
	{
		switch (RenderAPI::GetAPI())
		{
			case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
			case RENDER_API::OPENGL: return std::make_shared<OpenGLComputeShader>();
			case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}
}
