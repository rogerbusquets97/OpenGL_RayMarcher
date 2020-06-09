#include "Material.h"

namespace rubEngine
{
	Material::Material(const std::string& aName) : mShader(nullptr), mTextures(), mName(aName)
	{
	}

	rubEngine::Material::Material(const std::shared_ptr<Shader>& aShader, const std::string& aName) : mShader(aShader), mTextures(), mName(aName)
	{
		//We should parse the shader to check how many textures does it need and create them (ideally the user should be able to assign them from an editor, let's add them using AddTexture() for now...)
	}

	rubEngine::Material::~Material()
	{
	}

	void rubEngine::Material::Use() const
	{
		for (int i = 0; i < mTextures.size(); ++i)
		{
			mTextures[i]->Bind(i);
		}

		mShader->Bind();
	}

	void Material::AddTexture(const std::shared_ptr<Texture2D>& aTexture)
	{
		mTextures.push_back(aTexture);
	}

	void Material::RemoveTexture(const std::shared_ptr<Texture2D>& aTexture)
	{
		mTextures.erase(std::find(mTextures.begin(), mTextures.end(), aTexture));
	}

	std::shared_ptr<Material> rubEngine::Material::Create(const std::shared_ptr<Shader>& aShader, const std::string& aName)
	{
		return std::make_shared<Material>(aShader, aName);
	}
}
