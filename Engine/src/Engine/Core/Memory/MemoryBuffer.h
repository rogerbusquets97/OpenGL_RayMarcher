#pragma once
#include <Core.h>
#include <string>
#include <vector>
#include "ByteSwap.h"
#define NOMINMAX

namespace rubEngine
{
	constexpr uint32_t DEFAULT_STREAM_SIZE = 1460;

	class ENGINE_API MemoryBuffer
	{
	public:
		MemoryBuffer(uint32_t aSize = DEFAULT_STREAM_SIZE) : mBuffer(nullptr), mCapacity(0), mWriteHead(0), mReadHead(0)
		{
			ReallocBuffer(aSize);
		}

		~MemoryBuffer()
		{
			std::free(mBuffer);
		}

		const char *GetBufferPtr() const { return mBuffer; }
		uint32_t GetCapacity() const { return mCapacity; }
		uint32_t GetSize() const { return mWriteHead; }

		void Reset() { mReadHead = 0; }
		void Write(const void* aData, size_t aByteCount);
		void Read(void* aData, size_t aByteCount) const;

		template<typename T>
		void Write(T aData)
		{
			static_assert(std::is_arithmetic<T>::value || std::is_enum<T>::value, "Generic Write only supports primitive data types");
			
			//Assume we're running on Windows (LittleEndian)
			T SwappedData = ByteSwap(aData);
			Write(&SwappedData, sizeof(SwappedData));
		}

		template<typename T>
		void Read(T& aData) const
		{
			static_assert(std::is_arithmetic< T >::value || std::is_enum< T >::value, "Generic Write only supports primitive data types");

			T UnswappedData;
			Read(&UnswappedData, sizeof(UnswappedData));
			aData = ByteSwap(UnswappedData);
		}

	private:
		void ReallocBuffer(uint32_t aLength);
		char* mBuffer;
		uint32_t mCapacity;
		uint32_t mWriteHead;
		mutable uint32_t mReadHead;
	};
}

