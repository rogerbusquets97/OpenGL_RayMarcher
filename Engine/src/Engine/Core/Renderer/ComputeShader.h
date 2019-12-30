#pragma once
#include <Core.h>
#include <vec2.hpp>

namespace Engine
{
	class ENGINE_API ComputeShader
	{
	public:
		ComputeShader() {};
		virtual ~ComputeShader() {};
		virtual void Load(const char* aSource) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual void Dispatch(unsigned int aSizeX, unsigned int aSizeY, unsigned int aSizeZ) = 0;
		virtual void SetBool(const std::string& aName, bool aValue) const = 0;
		virtual void SetInt(const std::string& aName, int aValue) const = 0;
		virtual void SetFloat(const std::string& aName, float aValue) const = 0;
		virtual void SetVec2(const std::string& aName, glm::vec2 aValue) const = 0;
		virtual void SetiVec2(const std::string& aName, glm::ivec2 aValue) const = 0;
		//... TODO: Add glm math library, so you can implement vec2, vec3, matrices ... 
		//TODO 2 unify with shader class to create common base class for same setAttributes functions

		static std::shared_ptr<ComputeShader> Create();
	};
}

