#ifndef C_SINGLETON_H
#define C_SINGLETON_H

#include <memory>

namespace Engine
{
	template<typename TYPE>
	class CSingleton
	{
	public:
		CSingleton() = default;
		CSingleton(const CSingleton&) = delete;
		
		virtual ~CSingleton() = default;

		static const std::unique_ptr<TYPE>& GetInstance()
		{
			if (mInstance == nullptr)
			{
				mInstance = std::make_unique<TYPE>();
			}

			return mInstance;
		}

	protected:
		static std::unique_ptr<TYPE> mInstance;
	};
}
#endif // !C_SINGLETON_H

