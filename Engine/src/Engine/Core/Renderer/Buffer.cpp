#include "Buffer.h"
#include <Renderer/RenderAPI.h>
#include <Renderer/OpenGL/OpenGLBuffer.h>

namespace Engine
{
	std::shared_ptr<VertexBuffer> Engine::VertexBuffer::Create(float * aVertices, uint32_t aSize)
	{
		switch (RenderAPI::GetAPI())
		{
		case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
		case RENDER_API::OPENGL: return std::make_shared<OpenGLVertexBuffer>(aVertices, aSize);
		case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t * aIndices, uint32_t aSize)
	{
		switch (RenderAPI::GetAPI())
		{
		case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
		case RENDER_API::OPENGL: return std::make_shared<OpenGLIndexBuffer>(aIndices, aSize);
		case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}
}
