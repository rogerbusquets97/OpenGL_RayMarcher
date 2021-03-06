#include "ModuleRenderer.h"
#include <Application.h>
#include <Log/Log.h>
#include <filesystem>
#include <Window/ModuleWindow.h>
#include <Camera/ModuleCamera.h>
#include <Renderer/Renderer.h>
#include <Renderer/ComputeShader.h>
#include <Renderer/Shader.h>
#include <Renderer/VertexArray.h>
#include <Renderer/Texture.h>
#include <Renderer/Material.h>
#include "Camera/PerspectiveCamera.h"
#include <Resources/ResourceManager.h>
#include <Input/CInput.h>
#include <Log/Log.h>
#include <Events/Event.h>

namespace rubEngine
{
	bool ModuleRenderer::mNeedRepaint = true;

	ModuleRenderer::ModuleRenderer() : Module(), mQuadMaterial(nullptr), mShader(nullptr), mComputeShader(nullptr), mQuadVA(nullptr), mQuadTexture(nullptr)
	{
	}


	ModuleRenderer::~ModuleRenderer()
	{
	}

	bool ModuleRenderer::Init()
	{
		bool ReturnValue(false);

		ReturnValue = Renderer::Init();
		
		const auto& pWindow = Application::GetInstance()->GetModule<ModuleWindow>();
		WindowEventsContainer& WindowEvents = pWindow->GetWindow()->GetWindowEvents();
		(*WindowEvents.mResizeWindowsEvent) += std::bind(&ModuleRenderer::OnResizeWindowEvent, this, std::placeholders::_1, std::placeholders::_2);
		
		/*mQuadVA = VertexArray::Create();
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
		std::string CurrentDirectory = std::filesystem::current_path().string();
		CurrentDirectory.substr(CurrentDirectory.find_last_of("\\/"));

		mpShaderResource = mApplication->GetResourceManager()->GetResource<ShaderResource>("StandardShader.shader", eResourceType::SHADER);
		mShader = mpShaderResource->GetShader();

		mComputeShader = ComputeShader::Create();
		std::string ComputePath = CurrentDirectory + "/Resources/ComputeShader.compute";
		mComputeShader->Load(ComputePath.c_str());

		mQuadTexture = RenderTexture2D::Create(ModuleWindow::GetWidth(), ModuleWindow::GetHeight());
		mQuadMaterial = Material::Create(mShader);*/
		return ReturnValue;
	}

	bool ModuleRenderer::Update(float aDeltaTime)
	{
		bool ReturnValue(true);
				
		/*mShader->SetMat4("viewMatrix", ModuleCamera::GetCamera()->GetViewMatrix());
		mShader->SetMat4("projectionMatrix", ModuleCamera::GetCamera()->GetProjectionMatrix());
		mShader->Bind();

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
		Renderer::DrawArray(0, 4);*/

		if (CInput::GetInstance()->GetKeyState(KeyId::A) == InputAction::Pressed)
		{
			ENGINE_CORE_ERROR("Mouse X {0}", CInput::GetInstance()->GetMouseX());
		}

		return ReturnValue;
	}

	bool ModuleRenderer::CleanUp()
	{
		/*mpShaderResource->Drop();
		bool ReturnValue = Renderer::CleanUp();*/
		return true;
	}
	bool ModuleRenderer::Awake()
	{
		mNeedRepaint = true;
		return true;
	}
	bool ModuleRenderer::PreUpdate(float aDeltaTime)
	{
		return true;
	}
	bool ModuleRenderer::PostUpdate(float aDeltaTime)
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
