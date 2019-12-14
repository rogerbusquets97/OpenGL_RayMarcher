#pragma once
#include <Renderer/RenderAPI.h>
#include <Core.h>
#include <Renderer/Shader.h>
#include <Renderer/ComputeShader.h>
#include <Renderer/VertexArray.h>


namespace Engine
{
	class ENGINE_API OpenGLRenderer : public RenderAPI
	{
	public:
		OpenGLRenderer();
		~OpenGLRenderer();
		virtual bool Init() override;
		virtual bool CleanUp() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		virtual void Clear() override;
		virtual void ClearColor(const glm::vec4& aColor) override;
		virtual void ClearDepth(float aDepth) override;
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& aArray) const override;
		virtual void DrawArray(unsigned int aFirst, unsigned int aCount) const override;
	};
}

