#include "Renderer.h"

namespace Engine
{
	std::unique_ptr<RenderAPI> Renderer::mRenderAPI = RenderAPI::Create();
}