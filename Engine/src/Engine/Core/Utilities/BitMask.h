#ifndef ENGINE_BIT_MASK
#define ENGINE_BIT_MASK

#include "Core.h"
#include <vector>

namespace Engine
{

	class ENGINE_API BitMask
	{
	public:

		BitMask();
		BitMask(unsigned int aSize);

		void SetBit(unsigned int aPosition);
		void SetAll();

		void ClearBit(unsigned int aPosition);
		void ClearAll();

		bool IsBitSetted(unsigned int aPosition) const;

		bool IsSubset(const BitMask& aBitMask) const;

		bool operator==(const BitMask& aBitMask) const;

	private:
		typedef unsigned int	tMaskChunk;

		static const size_t			mMaskChunkSize = sizeof(tMaskChunk)*8U;
		std::vector<tMaskChunk>		mMask;
	};
}

#endif 