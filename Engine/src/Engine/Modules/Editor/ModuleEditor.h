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
		virtual bool Update() override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate() override;
		virtual bool PostUpdate() override;
		virtual void OnEvent(MemoryBuffer& aData) override;
		virtual void OnGUI() override;

	private:
		std::vector<EditorElement*> mElements;
		bool mOpen;
	};
}