#include "ShaderResource.h"
#include <iostream>
#include <fstream>

rubEngine::ShaderResource::ShaderResource(const std::string& aPath) : Resource(aPath, eResourceType::SHADER), mShader(Shader::Create())
{
}

rubEngine::ShaderResource::~ShaderResource()
{
	if (mLoaded)
	{
		UnloadResource();
	}
}

void rubEngine::ShaderResource::LoadResource()
{
	if (!mLoaded)
	{
		mShader->Load(mPath);
		mLoaded = true;
	}
}

void rubEngine::ShaderResource::UnloadResource()
{
	if (mLoaded)
	{
		mLoaded = false;
	}
}