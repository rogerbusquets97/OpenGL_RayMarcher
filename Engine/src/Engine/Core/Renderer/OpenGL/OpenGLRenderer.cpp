#include "OpenGLRenderer.h"
#include <glad/glad.h>
#include <filesystem>
#include <Application.h>
#include <Window/ModuleWindow.h>

namespace Engine
{
	OpenGLRenderer::OpenGLRenderer()
	{
	}


	OpenGLRenderer::~OpenGLRenderer()
	{
	}

	bool OpenGLRenderer::Init()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);

		return true;
	}

	bool OpenGLRenderer::CleanUp()
	{
		return true;
	}

	void OpenGLRenderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRenderer::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRenderer::ClearColor(const glm::vec4 & aColor)
	{
		glClearColor(aColor.r, aColor.g, aColor.b, aColor.a);
	}

	void OpenGLRenderer::ClearDepth(float aDepth)
	{
		glClearDepth(aDepth);
	}

	void OpenGLRenderer::DrawIndexed(const std::shared_ptr<VertexArray>& aArray) const
	{
		glDrawElements(GL_TRIANGLES, aArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void OpenGLRenderer::DrawArray(unsigned int aFirst, unsigned int aCount) const
	{
		glDrawArrays(GL_TRIANGLE_STRIP, aFirst, aCount);
	}
}