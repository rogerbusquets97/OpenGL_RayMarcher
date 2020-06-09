#include "FileWatcher.h"
#include <thread>

namespace rubEngine
{
	rubEngine::FileWatcher::FileWatcher(const std::string& aPath, std::chrono::duration<int, std::milli> aDelay) : mPathToWatch(aPath), mDelay(aDelay), mPaths(), mIsRunning(false)
	{
	}

	void FileWatcher::Start(const std::function<void(std::string, eFileStatus)>& aCallback)
	{
		mIsRunning = true;

		for (auto& File : std::filesystem::recursive_directory_iterator(mPathToWatch))
		{
			mPaths.emplace(File.path().string(), std::filesystem::last_write_time(File));
		}

		CheckFilesChanges(aCallback);
	}

	void FileWatcher::Stop()
	{
		mIsRunning = false;
	}

	void FileWatcher::CheckFilesChanges(const std::function<void(std::string, eFileStatus)>& aCallback)
	{
		while (mIsRunning)
		{
			std::this_thread::sleep_for(mDelay);
			FilesMap CopyMap = mPaths;

			for (auto& Path : CopyMap)
			{
				if (!std::filesystem::exists(Path.first))
				{
					aCallback(Path.first, eFileStatus::ERASED);
					mPaths.erase(Path.first);
				}
			}

			for (auto& File : std::filesystem::recursive_directory_iterator(mPathToWatch))
			{
				auto LastTimeWrite = std::filesystem::last_write_time(File);
				const auto& FileName = File.path().string();

				if (!Contains(FileName))
				{
					mPaths.emplace(File.path().string(), LastTimeWrite);
					aCallback(FileName, eFileStatus::CREATED);
				}
				else
				{
					if (mPaths.at(FileName) != LastTimeWrite)
					{
						mPaths.at(FileName) = LastTimeWrite;
						aCallback(FileName, eFileStatus::MODIFIED);
					}
				}
			}
		}
	}


}
