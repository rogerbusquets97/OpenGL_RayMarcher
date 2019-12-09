#pragma once
#include <Core.h>
#include <Renderer/ComputeShader.h>

namespace Engine
{
	class ENGINE_API OpenGLComputeShader : public ComputeShader
	{
	public:
		OpenGLComputeShader();
		virtual ~OpenGLComputeShader();
		virtual void Load(const char* aSource) override;
		virtual void Bind() override;
		virtual void Dispatch(unsigned int aSizeX, unsigned int aSizeY, unsigned int aSizeZ) override;
		virtual void SetBool(const std::string& aName, bool aValue) const override;
		virtual void SetInt(const std::string& aName, int aValue) const override;
		virtual void SetFloat(const std::string& aName, float aValue) const override;
		virtual void SetVec2(const std::string& aName, glm::vec2 aValue) const override;
		virtual void SetiVec2(const std::string& aName, glm::ivec2 aValue) const override;

	private:
		void Compile(const char* aSource);
		void CheckCompileErrors(unsigned int aShader, std::string aType);

	private:
		unsigned int mID;
	};
}
