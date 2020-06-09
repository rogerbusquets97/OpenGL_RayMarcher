#pragma once
#include <IMGUI/ImGuiPlatformHandler.h>

namespace rubEngine
{
	class OpenGLImGuiHandler : public ImGuiPlatformHandler
	{
	public:
		virtual void Init() override;
		virtual void CleanUp() override;
		virtual void BeginFrame() override;
		virtual void EndFrame() override;
	};
}
