#include "MemoryBuffer.h"
#include <algorithm>
#include "Log/Log.h"

namespace Engine
{
	void MemoryBuffer::Write(const void * aData, size_t aByteCount)
	{
		const uint32_t ResultHead = mWriteHead + static_cast<uint32_t>(aByteCount);
		if (ResultHead > mCapacity)
		{
			ReallocBuffer(std::max(mCapacity * 2, ResultHead));
		}

		std::memcpy(mBuffer + mWriteHead, aData, aByteCount);
		mWriteHead = ResultHead;
	}
	void MemoryBuffer::Read(void * aData, size_t aByteCount) const
	{
		uint32_t ResultHead = mReadHead + static_cast<uint32_t>(aByteCount);
		if (ResultHead > mWriteHead)
		{
			ENGINE_CORE_ERROR("Exceded memory while reading buffer!");
		}

		std::memcpy(aData, mBuffer + mReadHead, aByteCount);
		mReadHead = ResultHead;
	}
	void MemoryBuffer::ReallocBuffer(uint32_t aLength)
	{
		mBuffer = static_cast<char*>(std::realloc(mBuffer, aLength));
		mCapacity = aLength;
	}
}
