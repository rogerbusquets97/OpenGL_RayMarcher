#include "Renderer.h"

namespace rubEngine
{
	std::unique_ptr<RenderAPI> Renderer::mRenderAPI = RenderAPI::Create();
}