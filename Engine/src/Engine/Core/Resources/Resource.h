#pragma once
#include <string>

namespace Engine
{
	enum class eResourceType
	{
		MESH,
		TEXTURE,
		SHADER
	};
	class Resource
	{
	public:
		Resource(const std::string& aPath, const std::string& aName, eResourceType aType) : mType(aType), mPath(aPath), mName(aName){}
		virtual ~Resource() = default;

		virtual void LoadResource() = 0;
		virtual void UnloadResource() = 0;

		std::string GetPath() const { return mPath; }

	protected:
		eResourceType mType;
		std::string mPath;
		std::string mName;
	};
}