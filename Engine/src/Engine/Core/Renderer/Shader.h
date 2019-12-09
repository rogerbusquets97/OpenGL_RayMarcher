#pragma once
#include <Core.h>
#include <vec2.hpp>

namespace Engine
{
	class ENGINE_API Shader
	{
	public:
		Shader() {};
		virtual ~Shader() {};
		virtual void Load(const char* aVertex, const char* aFragment) = 0;
		virtual void Bind() = 0;
		virtual void SetBool(const std::string& aName, bool aValue) const = 0;
		virtual void SetInt(const std::string& aName, int aValue) const = 0;
		virtual void SetFloat(const std::string& aName, float aValue) const = 0;
		virtual void SetVec2(const std::string& aName, glm::vec2 aValue) const = 0;
		//... TODO: Add glm math library, so you can implement vec2, vec3, matrices ... 

		static Shader* Create();
	};
}

