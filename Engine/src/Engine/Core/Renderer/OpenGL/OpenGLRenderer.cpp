#include "OpenGLRenderer.h"
#include <glad/glad.h>
#include <filesystem>
#include <Application.h>
#include <Window/ModuleWindow.h>

namespace Engine
{
	OpenGLRenderer::OpenGLRenderer() : QuadVAO(0), QuadVBO(0)
	{
	}


	OpenGLRenderer::~OpenGLRenderer()
	{
	}

	bool OpenGLRenderer::Init()
	{
		glEnable(GL_DEPTH_TEST);

		//Screen Quad
		float quadVertices[] =
		{
			-1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
			1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
			1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		};

		glGenVertexArrays(1, &QuadVAO);
		glGenBuffers(1, &QuadVBO);
		glBindVertexArray(QuadVAO);
		glBindBuffer(GL_ARRAY_BUFFER, QuadVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

		//Shaders
		QuadShader = Shader::Create();
		std::string CurrentDirectory = std::filesystem::current_path().string();
		CurrentDirectory.substr(CurrentDirectory.find_last_of("\\/"));
		std::string VertexPath = CurrentDirectory + "/Resources/StandardShader.vs";
		std::string FragmentPath = CurrentDirectory + "/Resources/StandardShader.fs";
		QuadShader->Load(VertexPath.c_str(), FragmentPath.c_str());

		mComputeShader = ComputeShader::Create();
		std::string ComputePath = CurrentDirectory + "/Resources/ComputeShader.compute";
		mComputeShader->Load(ComputePath.c_str());
		mComputeShader->SetiVec2("Resolution", Window::GetResolution());

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

		return true;
	}

	bool OpenGLRenderer::CleanUp()
	{
		delete QuadShader;
		return true;
	}

	void OpenGLRenderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
	}

	bool OpenGLRenderer::Update()
	{
		{
			mComputeShader->Bind();
			mComputeShader->Dispatch(Window::GetResolution().x, Window::GetResolution().y, 1);
		}
		{
			glClearDepth(1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			QuadShader->Bind();
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, OutputTexture);
			DrawQuad();
			glUseProgram(0);
		}
		return true;
	}

	void OpenGLRenderer::DrawQuad()
	{
		if (QuadVAO && QuadVBO)
		{
			glBindVertexArray(QuadVAO);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
			glBindVertexArray(0);
		}
	}
}