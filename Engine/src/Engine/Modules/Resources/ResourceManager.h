#pragma once
#include <Resources/Resource.h>
#include <unordered_map>
#include <memory>
#include <Module.h>
#include <Application.h>
#include <FileSystem/FileWatcher.h>
#include <thread>

namespace Engine
{
	typedef std::unordered_map <eResourceType, std::unordered_map<std::string, Resource*>> ResourcesMap;

	class ResourceManager : public Module
	{
	public:
		ResourceManager(Application* aApplication);
		~ResourceManager() = default;

		virtual bool Init() override;
		virtual bool Update(float aDeltaTime) override;
		virtual bool CleanUp() override;
		virtual bool Awake() override;
		virtual bool PreUpdate(float aDeltaTime) override;
		virtual bool PostUpdate(float aDeltaTime) override;

		template <typename T>
		const std::unique_ptr<T>& GetResource(const std::string& aName, eResourceType aType)
		{
			static_assert(mResources.find(aType), "Invalid Resource Type");
			static_assert(mResources.at(aType).find(aName), "Wrong resource name");

			std::unique_ptr<T> ReturnValue = dynamic_cast<std::unique_ptr<T>>(mResources.at(aType).at(aName));
			static_assert(ReturnValue == nullptr, "Cannot convert to the asked type. Are you sure it is derived from Resource?");
			return ReturnValue;
		}

		void AddResource(Resource* aResource);

	private:
		void OnFileNotify(const std::string& aPath, eFileStatus aFileStatus);
	private:

		ResourcesMap mResources;
		FileWatcher mFileWatcher;
		std::thread mFileWatcherThread;
	};
}