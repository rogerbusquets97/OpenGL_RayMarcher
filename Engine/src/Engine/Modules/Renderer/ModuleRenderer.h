#pragma once
#include <Module.h>
#include <Core.h>
#include <Renderer/RenderAPI.h>
#include <Renderer/Shader.h>
#include <Renderer/ComputeShader.h>
#include <Renderer/VertexArray.h>
#include <Renderer/Texture.h>
#include <Renderer/Material.h>

namespace Engine
{
	class ENGINE_API ModuleRenderer : public Module
	{
	public:
		ModuleRenderer(Application* aApplication);
		virtual ~ModuleRenderer();

		virtual bool Init() override;
		virtual bool Update(float aDeltaTime) override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate(float aDeltaTime) override;
		virtual bool PostUpdate(float aDeltaTime) override;

		static void NeedRepaint(bool aRepaint);

		virtual void OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight) override;

	private:
		std::shared_ptr<Material> mQuadMaterial;
		std::shared_ptr<ComputeShader> mComputeShader;
		std::shared_ptr<VertexArray> mQuadVA;
		std::shared_ptr<RenderTexture2D> mQuadTexture;
		static bool mNeedRepaint;
	};
}

