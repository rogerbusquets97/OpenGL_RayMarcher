#pragma once
#include <Resources/Resource.h>
#include <unordered_map>
#include <memory>
#include <Module.h>
#include <Application.h>
#include <FileSystem/FileWatcher.h>
#include <thread>
#include <Resources/ShaderResource.h>

namespace rubEngine
{
	typedef std::unordered_map <eResourceType, std::unordered_map<std::string, Resource*>> ResourcesMap;

	class ResourceManager : public Module
	{
	public:
		ResourceManager();
		~ResourceManager() = default;

		virtual bool Init() override;
		virtual bool Update(float aDeltaTime) override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate(float aDeltaTime) override;
		virtual bool PostUpdate(float aDeltaTime) override;

		template <typename T>
		T* GetResource(const std::string& aName, eResourceType aType)
		{
			if (mResources.find(aType) != std::end(mResources))
			{
				if (mResources.at(aType).find(aName) != std::end(mResources.at(aType)))
				{
					T* ReturnValue = dynamic_cast<T*>(mResources.at(aType).at(aName));
					if (ReturnValue != nullptr)
					{
						static_cast<Resource*>(ReturnValue)->Grab();
						return ReturnValue;
					}
					else
					{
						return nullptr;
					}
				}
				else
				{
					return nullptr;
				}
			}
			else
			{
				return nullptr;
			}
		}

		void CreateResource(const std::string& aPath);
		virtual void OnFileDropped(const std::string& aPath) override;

	private:
		void OnFileNotify(const std::string& aPath, eFileStatus aFileStatus);
		eResourceType GetResourceType(const std::string& aExtension);
		void AddResource(Resource* aResource);
	private:

		ResourcesMap mResources;
		FileWatcher mFileWatcher;
		std::thread mFileWatcherThread;
	};
}