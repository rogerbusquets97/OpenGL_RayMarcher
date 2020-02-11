#include "ShaderResource.h"
#include <iostream>
#include <fstream>

Engine::ShaderResource::ShaderResource(const std::string& aPath) : Resource(aPath, eResourceType::SHADER), mShader(Shader::Create())
{
}

Engine::ShaderResource::~ShaderResource()
{
	if (mLoaded)
	{
		UnloadResource();
	}
}

void Engine::ShaderResource::LoadResource()
{
	if (!mLoaded)
	{
		mShader->Load(mPath);
		mLoaded = true;
	}
}

void Engine::ShaderResource::UnloadResource()
{
	if (mLoaded)
	{
		mLoaded = false;
	}
}