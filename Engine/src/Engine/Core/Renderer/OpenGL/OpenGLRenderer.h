#pragma once
#include <Renderer/RenderAPI.h>
#include <Core.h>
#include <Renderer/Shader.h>
#include <Renderer/ComputeShader.h>


namespace Engine
{
	class ENGINE_API OpenGLRenderer : public RenderAPI
	{
	public:
		OpenGLRenderer();
		~OpenGLRenderer();
		virtual bool Init() override;
		virtual bool CleanUp() override;
		virtual bool Update() override;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

	private: 
		void DrawQuad();

	private:
		unsigned int QuadVAO; 
		unsigned int QuadVBO;
		Shader* QuadShader;
		ComputeShader* mComputeShader;
		unsigned int OutputTexture;
	};
}

