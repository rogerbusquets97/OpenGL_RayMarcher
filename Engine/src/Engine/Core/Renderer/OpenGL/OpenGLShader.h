#pragma once
#include <Core.h>
#include <Renderer/Shader.h>

namespace Engine
{
	class ENGINE_API OpenGLShader : public Shader
	{
	public:
		OpenGLShader();
		virtual ~OpenGLShader();
		virtual void Load(const std::string& aPath) override;
		virtual void Unload() override;
		virtual void Bind() override;
		virtual void Unbind() override;
		virtual void SetBool(const std::string& aName, bool aValue) const override;
		virtual void SetInt(const std::string& aName, int aValue) const override;
		virtual void SetFloat(const std::string& aName, float aValue) const override;
		virtual void SetVec2(const std::string& aName, glm::vec2 aValue) const override;
		virtual void SetMat4(const std::string& aName, const glm::mat4& aValue) const override;

	private:
		void Compile(const char* aVertex, const char* aFragment);
		void CheckCompileErrors(unsigned int aShader, std::string aType);

	private:
		unsigned int mID;
		bool mLoaded;
	};
}

