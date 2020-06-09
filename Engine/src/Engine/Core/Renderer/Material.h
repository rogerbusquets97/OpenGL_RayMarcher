#pragma once
#include <Core.h>
#include <Renderer/Shader.h>
#include <vector>
#include <Renderer/Texture.h>
namespace rubEngine
{
	class ENGINE_API Material
	{
	public:
		Material(const std::string& aName = "Material");
		Material(const std::shared_ptr<Shader>& aShader, const std::string& aName = "Material");
		~Material();

		void Use() const;
		std::string GetName() const { return mName; }
		void AddTexture(const std::shared_ptr<Texture2D>& aTexture);
		void RemoveTexture(const std::shared_ptr<Texture2D>& aTexture);

		static std::shared_ptr<Material> Create(const std::shared_ptr<Shader>& aShader, const std::string& aName = "Material");

	private:
		std::shared_ptr<Shader> mShader;
		std::vector<std::shared_ptr<Texture2D>> mTextures;
		std::string mName;
	};
}
