#include "BitMask.h"

namespace Engine
{
	BitMask::BitMask() :
		mMask(1U, 0U)
	{

	}

	void BitMask::SetPosition(unsigned int aPosition, bool aValue)
	{
		unsigned int Chunk = aPosition / mMaskChunkSize;
		unsigned int PositionInChunk = aPosition % mMaskChunkSize;

		size_t MaskChunks = mMask.size();
		if (MaskChunks <= Chunk)
		{
			for (size_t NewChunk = MaskChunks; NewChunk <= Chunk; ++NewChunk)
			{
				mMask.push_back(0U);
			}
		}

		if (aValue)
		{
			mMask.at(Chunk) |= 1U << PositionInChunk;
		}
		else
		{
			mMask.at(Chunk) &= ~(1U << PositionInChunk);
		}
	}

	bool BitMask::GetPosition(unsigned int aPosition) const
	{
		unsigned int Chunk = aPosition / mMaskChunkSize;
		unsigned int PositionInChunk = aPosition % mMaskChunkSize;
	
		return mMask.size() <= Chunk ? 
				false : 
				mMask.at(Chunk) & (1U << PositionInChunk);
	}

	bool BitMask::IsSubset(const BitMask& aBitMask) const
	{
		bool ReturnValue = false;
		size_t MaskSize = mMask.size();
		if (aBitMask.mMask.size() >= MaskSize)
		{
			for (size_t CurrentChunk = 0U; CurrentChunk < MaskSize && !ReturnValue; ++CurrentChunk)
			{
				ReturnValue = (mMask.at(CurrentChunk) & aBitMask.mMask.at(CurrentChunk)) == mMask.at(CurrentChunk);
			}
		}

		return ReturnValue;
	}

	bool BitMask::operator==(const BitMask& aBitMask) const
	{
		return mMask == aBitMask.mMask;
	}

}