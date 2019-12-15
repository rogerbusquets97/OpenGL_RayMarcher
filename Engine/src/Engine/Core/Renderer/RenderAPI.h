#pragma once
#include <Core.h>
#include <glm.hpp>
#include <Renderer/VertexArray.h>

namespace Engine
{
	enum class RENDER_API
	{
		None = 0,
		OPENGL,
		DIRECTX
	};
	
	class ENGINE_API RenderAPI
	{
	public:
		RenderAPI() {}
		virtual ~RenderAPI() {}
		virtual bool Init() = 0;
		virtual bool CleanUp() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void Clear() = 0;
		virtual void ClearColor(const glm::vec4& aColor) = 0;
		virtual void ClearDepth(float aDepth) = 0;
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& aArray) const = 0;
		virtual void DrawArray(unsigned int aFirst, unsigned int aCount) const = 0;
		inline static RENDER_API GetAPI() { return mCurrentAPI; }
		static std::unique_ptr<RenderAPI> Create();
	
	private:
		static RENDER_API mCurrentAPI;
	};
}

