#pragma once
#include <Editor/EditorElement.h>

namespace Engine
{
	class MainMenuBar : public EditorElement
	{
	public:
		MainMenuBar() {};
		~MainMenuBar() {};

		virtual void Init() override;
		virtual void CleanUp() override;
		virtual void Draw() override;
	};
}