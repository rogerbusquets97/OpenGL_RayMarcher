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
		const std::string& AssetsPath = std::filesystem::current_path().string() + "\\Assets";
		if (!std::filesystem::exists(AssetsPath))
		{
			std::filesystem::create_directory(AssetsPath);
		}
		else
		{
			for (auto& File : std::filesystem::recursive_directory_iterator(AssetsPath))
			{
				CreateResource(File.path().string());
			}
		}

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
		mResources[aResource->GetType()].emplace(aResource->GetName(), aResource);
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

	void ResourceManager::CreateResource(const std::string& aPath)
	{
		std::string FileName(aPath);
		FileName.erase(0U, FileName.find_last_of("\\") + 1U);

		std::string FileExtension(FileName);
		FileExtension.erase(0U, FileExtension.find_last_of(".") + 1U);

		switch (GetResourceType(FileExtension))
		{
			case eResourceType::SHADER:
			{
				AddResource(new ShaderResource(aPath));
			}
			break;
			case eResourceType::MESH:
			{
				//AddResource(new MeshResource);
			}
			break;
			case eResourceType::TEXTURE:
			{
				//AddResource(new TextureResource);
			}
			break;
		}
	}

	eResourceType ResourceManager::GetResourceType(const std::string& aExtension)
	{
		//We should read supported files for each resource from a config file.
		//Temporal code
		if (aExtension == "shader")
		{
			return eResourceType::SHADER;
		}
		else if (aExtension == "fbx")
		{
			return eResourceType::MESH;
		}
		else if (aExtension == "png")
		{
			return eResourceType::TEXTURE;
		}
	}
}
