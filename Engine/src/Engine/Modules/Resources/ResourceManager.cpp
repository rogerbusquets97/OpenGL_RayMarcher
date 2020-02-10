#include "ResourceManager.h"
#include <Log/Log.h>

namespace Engine
{
	Engine::ResourceManager::ResourceManager(Application* aApplication) : Module("Resources", aApplication), mResources(), mFileWatcher(std::filesystem::current_path().string() + "/Assets", std::chrono::milliseconds(5000)), mFileWatcherThread()
	{
	}

	bool ResourceManager::Init()
	{
		//Runs in separate thread.
		const std::string& AssetsPath = std::filesystem::current_path().string() + "/Assets";
		if (!std::filesystem::exists(AssetsPath))
		{
			std::filesystem::create_directory(AssetsPath);
		}

		mFileWatcherThread = std::thread(std::bind(&FileWatcher::Start, &mFileWatcher, std::placeholders::_1), std::bind(&ResourceManager::OnFileNotify, this, std::placeholders::_1, std::placeholders::_2));
		return true;
	}

	bool ResourceManager::Update(float aDeltaTime)
	{
		return true;
	}

	bool ResourceManager::CleanUp()
	{
		mFileWatcher.Stop();
		mFileWatcherThread.join();
		return true;
	}

	bool ResourceManager::Awake()
	{
		return true;
	}

	bool ResourceManager::PreUpdate(float aDeltaTime)
	{
		return true;
	}

	bool ResourceManager::PostUpdate(float aDeltaTime)
	{
		return true;
	}

	void ResourceManager::AddResource(Resource* aResource)
	{
	}

	void ResourceManager::OnFileDropped(const std::string& aPath)
	{
		ENGINE_CORE_ERROR("File Dropped: ");
		ENGINE_CORE_ERROR(aPath.c_str());
	}

	void ResourceManager::OnFileNotify(const std::string& aPath, eFileStatus aFileStatus)
	{
		auto Message = "File Notified: " + aPath;
		ENGINE_CORE_ERROR(Message.c_str());
	}
}
