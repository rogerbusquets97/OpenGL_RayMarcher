#pragma once
#include <string>
#include "../Core/Core.h"

namespace Engine
{
	class ENGINE_API Module
	{
	public:

		Module(const std::string& aName, Application* aApplication)
		{
			mName = aName;
			mApplication = aApplication;
		}

		virtual ~Module() {}
		virtual bool Init() = 0;
		virtual bool CleanUp() = 0;
		virtual bool Update() = 0;
		inline const std::string& GetName() const { return mName; }

	protected:
		std::string mName;
		Application* mApplication;
	};
}

