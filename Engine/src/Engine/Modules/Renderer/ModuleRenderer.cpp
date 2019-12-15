#include "ModuleRenderer.h"
#include <Application.h>
#include <Log/Log.h>
#include <filesystem>
#include <Renderer/Renderer.h>
#include <Window/ModuleWindow.h>

namespace Engine
{
	ModuleRenderer::ModuleRenderer(Application* aApplication) : Module("Renderer", aApplication), mQuadShader(), mQuadVA()
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
		mQuadShader = Shader::Create();
		std::string CurrentDirectory = std::filesystem::current_path().string();
		CurrentDirectory.substr(CurrentDirectory.find_last_of("\\/"));
		std::string VertexPath = CurrentDirectory + "/Resources/StandardShader.vs";
		std::string FragmentPath = CurrentDirectory + "/Resources/StandardShader.fs";
		mQuadShader->Load(VertexPath.c_str(), FragmentPath.c_str());

		mComputeShader = ComputeShader::Create();
		std::string ComputePath = CurrentDirectory + "/Resources/ComputeShader.compute";
		mComputeShader->Load(ComputePath.c_str());

		mQuadTexture = RenderTexture2D::Create(ModuleWindow::GetWidth(), ModuleWindow::GetHeight());
		return ReturnValue;

		//Example Compute shader texture
		/*mComputeShader = ComputeShader::Create();
		std::string ComputePath = CurrentDirectory + "/Resources/ComputeShader.compute";
		mComputeShader->Load(ComputePath.c_str());

		//Texture - This could be implemented in a OpenGLTexture class (just like shaders)
		glm::vec2 Resolution = Window::GetResolution();
		glGenTextures(1, &OutputTexture);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, OutputTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, Resolution.x, Resolution.y, 0, GL_RGBA, GL_FLOAT, NULL);
		glBindImageTexture(0, OutputTexture, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
		*/
	}

	bool ModuleRenderer::Update()
	{
		bool ReturnValue(false);

		Renderer::ClearColor(glm::vec4(0));
		Renderer::ClearDepth(1.0f);
		Renderer::Clear();

		mQuadTexture->Bind();
		mComputeShader->Bind();
		mComputeShader->Dispatch(ModuleWindow::GetWidth(), ModuleWindow::GetHeight(), 1);
		//Draw stuff
		mQuadShader->Bind();
		Renderer::DrawArray(0,4);

		return ReturnValue;
	}

	bool ModuleRenderer::CleanUp()
	{
		bool ReturnValue = Renderer::CleanUp();
		return ReturnValue;
	}
	bool ModuleRenderer::Awake()
	{
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
	void ModuleRenderer::OnEvent(MemoryBuffer& aData)
	{
		//TODO: Handle window resize
	}
}
