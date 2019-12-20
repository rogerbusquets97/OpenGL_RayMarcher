#include "ModuleRenderer.h"
#include <Application.h>
#include <Log/Log.h>
#include <filesystem>
#include <Renderer/Renderer.h>
#include <Window/ModuleWindow.h>

namespace Engine
{
	bool ModuleRenderer::mNeedRepaint = true;

	ModuleRenderer::ModuleRenderer(Application* aApplication) : Module("Renderer", aApplication), mQuadMaterial(nullptr), mComputeShader(nullptr), mQuadVA(nullptr), mQuadTexture(nullptr)
	{
	}


	ModuleRenderer::~ModuleRenderer()
	{
	}

	bool ModuleRenderer::Init()
	{
		bool ReturnValue(false);

		ReturnValue = Renderer::Init();
		
		mQuadVA = VertexArray::Create();
		//Screen Quad
		float quadVertices[] =
		{
			-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		};

		mQuadVA->Bind();
		std::shared_ptr<VertexBuffer> QuadVBO = VertexBuffer::Create(quadVertices, sizeof(quadVertices));
		QuadVBO->Bind();
		QuadVBO->SetAttributeArray( 
			{
				{eShaderDataType::Vec3, "aPosition"},
				{eShaderDataType::Vec2, "aTexCoord"}
			});
		
		mQuadVA->AddVertexBuffer(QuadVBO);

		//Quad Shader
		std::shared_ptr<Shader> QuadShader = Shader::Create();
		std::string CurrentDirectory = std::filesystem::current_path().string();
		CurrentDirectory.substr(CurrentDirectory.find_last_of("\\/"));
		std::string VertexPath = CurrentDirectory + "/Resources/StandardShader.vs";
		std::string FragmentPath = CurrentDirectory + "/Resources/StandardShader.fs";
		QuadShader->Load(VertexPath.c_str(), FragmentPath.c_str());

		mComputeShader = ComputeShader::Create();
		std::string ComputePath = CurrentDirectory + "/Resources/ComputeShader.compute";
		mComputeShader->Load(ComputePath.c_str());

		mQuadTexture = RenderTexture2D::Create(ModuleWindow::GetWidth(), ModuleWindow::GetHeight());
		mQuadMaterial = Material::Create(QuadShader);
		return ReturnValue;
	}

	bool ModuleRenderer::Update()
	{
		bool ReturnValue(true);
				
		Renderer::ClearColor(glm::vec4(0));
		Renderer::ClearDepth(1.0f);
		Renderer::Clear();

		mQuadTexture->Bind();

		if (mNeedRepaint)
		{
			mComputeShader->Bind();
			mComputeShader->Dispatch(ModuleWindow::GetWidth(), ModuleWindow::GetHeight(), 1);
			mNeedRepaint = false;
		}

		//Draw stuff
		mQuadMaterial->Use();
		Renderer::DrawArray(0, 4);

		return ReturnValue;
	}

	bool ModuleRenderer::CleanUp()
	{
		bool ReturnValue = Renderer::CleanUp();
		return ReturnValue;
	}
	bool ModuleRenderer::Awake()
	{
		mNeedRepaint = true;
		return true;
	}
	bool ModuleRenderer::PreUpdate()
	{
		return true;
	}
	bool ModuleRenderer::PostUpdate()
	{
		return true;
	}

	void ModuleRenderer::OnResizeWindowEvent(unsigned int aWidth, unsigned int aHeight)
	{
		Renderer::Resize(aWidth, aHeight);
	}
	void ModuleRenderer::NeedRepaint(bool aRepaint)
	{
		mNeedRepaint = aRepaint;
	}
}
