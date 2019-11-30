#pragma once
#include "../Core.h"

namespace Engine
{
	enum RENDER_API
	{
		None = 0,
		OPENGL,
		DIRECTX
	};
	
	class ENGINE_API RenderAPI
	{
	public:
		RenderAPI() {}
		virtual ~RenderAPI() {}
		virtual bool Init() = 0;
		virtual bool CleanUp() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		inline static RENDER_API GetAPI() { return mCurrentAPI; }
		static RenderAPI* Create();
	
	private:
		static RENDER_API mCurrentAPI;
	};
}

