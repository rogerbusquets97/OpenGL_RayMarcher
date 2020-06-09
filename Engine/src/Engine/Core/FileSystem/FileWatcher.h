#pragma once
#include <string>
#include <chrono>
#include <functional>
#include <unordered_map>
#include <filesystem>

namespace rubEngine
{
	enum class eFileStatus { CREATED, MODIFIED, ERASED };

	class FileWatcher
	{
	public: 
		FileWatcher(const std::string& aPath, std::chrono::duration<int, std::milli> aDelay);
		~FileWatcher() = default;

		void Start(const std::function<void(std::string, eFileStatus)>& aCallback);
		void Stop();

	private:
		typedef std::unordered_map<std::string, std::filesystem::file_time_type> FilesMap;

		std::string mPathToWatch;
		std::chrono::duration<int, std::milli> mDelay;
		FilesMap mPaths;
		bool mIsRunning;

		bool Contains(const std::string& aKey)
		{
			auto Element = mPaths.find(aKey);
			return Element != mPaths.end();
		}

		void CheckFilesChanges(const std::function<void(std::string, eFileStatus)>& aCallback);
	};
}
