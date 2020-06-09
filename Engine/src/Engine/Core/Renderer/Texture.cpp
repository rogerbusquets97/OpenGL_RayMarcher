#include "Texture.h"
#include <Renderer/RenderAPI.h>
#include <Renderer/OpenGL/OpenGLTexture.h>

namespace rubEngine
{
	std::shared_ptr<Texture2D> rubEngine::Texture2D::Create(uint32_t aWidth, uint32_t aHeight)
	{
		switch (RenderAPI::GetAPI())
		{
		case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
		case RENDER_API::OPENGL: return std::make_shared<OpenGLTexture2D>(aWidth, aHeight);
		case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}

	std::shared_ptr<RenderTexture2D> rubEngine::RenderTexture2D::Create(uint32_t aWidth, uint32_t aHeight)
	{
		switch (RenderAPI::GetAPI())
		{
		case RENDER_API::None: ENGINE_CORE_ERROR("None API not supported"); return nullptr;
		case RENDER_API::OPENGL: return std::make_shared<OpenGLRenderTexture2D>(aWidth, aHeight);
		case RENDER_API::DIRECTX: ENGINE_CORE_ERROR("DirectX not supported yet"); return nullptr;
		}

		ENGINE_CORE_ERROR("Unknown API");
		return nullptr;
	}
}