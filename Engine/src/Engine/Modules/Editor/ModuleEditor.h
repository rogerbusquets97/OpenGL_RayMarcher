#pragma once
#include <Core.h>
#include <Module.h>
#include <Events/Event.h>
#include <Editor/EditorElement.h>

namespace Engine
{
	class ENGINE_API ModuleEditor : public Module
	{
	public:
		ModuleEditor(Application* aApplication);
		~ModuleEditor();
		virtual bool Init() override;
		virtual bool Update(float aDeltaTime) override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate(float aDeltaTime) override;
		virtual bool PostUpdate(float aDeltaTime) override;
		virtual void OnGUI() override;

	private:
		std::vector<EditorElement*> mElements;
		bool mOpen;
	};
}