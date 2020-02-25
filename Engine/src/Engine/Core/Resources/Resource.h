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
		Resource(const std::string& aPath, eResourceType aType) : mType(aType), mPath(aPath), mName(), mReferenceCount(0U), mLoaded(false)
		{
			mName = aPath;
			mName.erase(0U, mName.find_last_of("\\") + 1U);
		}
		virtual ~Resource() = default;

		virtual void LoadResource() = 0;
		virtual void UnloadResource() = 0;

		inline const std::string& GetPath() const { return mPath; }
		inline const std::string& GetName() const { return mName; }
		inline eResourceType GetType() const { return mType; }
		inline void Grab() { ++mReferenceCount; if (mReferenceCount && !mLoaded) LoadResource(); }
		inline void Drop() { --mReferenceCount; if (!mReferenceCount) UnloadResource();}

	protected:
		eResourceType mType;
		std::string mPath;
		std::string mName;
		unsigned int mReferenceCount;
		bool mLoaded;
	};
}