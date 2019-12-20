#pragma once
#include <Core.h>

namespace Engine
{
	class ENGINE_API EditorElement
	{
	public:
		EditorElement(const bool aOpen = true) : Opened(aOpen) {}
		virtual ~EditorElement() = default;
		virtual void Init() = 0;
		virtual void Draw() = 0;
		virtual void CleanUp() = 0;

	public:
		bool Opened;
	};
}