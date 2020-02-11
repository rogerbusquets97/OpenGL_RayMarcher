#pragma once
#include <Resources/Resource.h>
#include <Renderer/Shader.h>

namespace Engine
{
	class ShaderResource : Resource
	{
	public: 
		ShaderResource(const std::string& aPath);
		~ShaderResource();

		virtual void LoadResource() override;
		virtual void UnloadResource() override;

		const std::shared_ptr<Shader>& GetShader() const { return mShader; }

	private: 

		std::shared_ptr<Shader> mShader;
	};
}
