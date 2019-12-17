#pragma once
#include <Module.h>
#include <Core.h>
#include <Renderer/RenderAPI.h>
#include <Renderer/Shader.h>
#include <Renderer/ComputeShader.h>
#include <Renderer/VertexArray.h>
#include <Renderer/Texture.h>
namespace Engine
{
	class ENGINE_API ModuleRenderer : public Module
	{
	public:
		ModuleRenderer(Application* aApplication);
		virtual ~ModuleRenderer();

		virtual bool Init() override;
		virtual bool Update() override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate() override;
		virtual bool PostUpdate() override;

	
		virtual void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight) override;

	private:
		std::shared_ptr<Shader> mQuadShader;
		std::shared_ptr<ComputeShader> mComputeShader;
		std::shared_ptr<VertexArray> mQuadVA;
		std::shared_ptr<RenderTexture2D> mQuadTexture;
	};
}

