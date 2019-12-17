#pragma once
#include <IMGUI/ImGuiPlatformHandler.h>

namespace Engine
{
	class OpenGLImGuiHandler : public ImGuiPlatformHandler
	{
	public:
		virtual void Init() override;
		virtual void CleanUp() override;
		virtual void BeginFrame() override;
		virtual void EndFrame() override;
		virtual void BeginWindow(const char* aName, bool* aOpen) override;
		virtual void EndWindow() override;
	};
}
