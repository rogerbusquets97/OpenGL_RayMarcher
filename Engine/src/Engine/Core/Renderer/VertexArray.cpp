#include "VertexArray.h"
#include <Renderer/RenderAPI.h>
#include <Renderer/OpenGL/OpenGLVertexArray.h>

namespace rubEngine
{
	std::shared_ptr<VertexArray> rubEngine::VertexArray::Create()
	{
		switch (RenderAPI::GetAPI())
		{
		case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
		case RENDER_API::OPENGL: return std::make_shared<OpenGLVertexArray>();
		case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}
}