#pragma once
#include <Core.h>
#include <Renderer/RenderAPI.h>

namespace rubEngine
{
	class ENGINE_API Renderer
	{
	public:
		inline static bool Init()
		{
			return mRenderAPI->Init();
		}

		inline static bool CleanUp()
		{
			return mRenderAPI->Init();
		}

		inline static void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			mRenderAPI->SetViewport(x, y, width, height);
		}

		inline static void Clear()
		{
			mRenderAPI->Clear();
		}

		inline static void ClearColor(const glm::vec4& aColor)
		{
			mRenderAPI->ClearColor(aColor);
		}

		inline static void ClearDepth(float aDepth)
		{
			mRenderAPI->ClearDepth(aDepth);
		}

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& aArray)
		{
			mRenderAPI->DrawIndexed(aArray);
		}

		inline static void DrawArray(unsigned int aFirst, unsigned int aCount)
		{
			mRenderAPI->DrawArray(aFirst, aCount);
		}

		inline static void Resize(unsigned int aWidth, unsigned int aHeight)
		{
			mRenderAPI->Resize(aWidth, aHeight);
		}

	private:
		static std::unique_ptr<RenderAPI> mRenderAPI;
	};
}

