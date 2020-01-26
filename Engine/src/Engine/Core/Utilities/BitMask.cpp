#include "BitMask.h"

namespace Engine
{
	BitMask::BitMask() :
		mMask(1U, 0U)
	{

	}

	BitMask::BitMask(unsigned int aSize) :
		mMask((aSize / mMaskChunkSize) + 1U, 0U)
	{

	}

	void BitMask::SetBit(unsigned int aPosition)
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

		mMask.at(Chunk) |= 1U << PositionInChunk;
	}

	void BitMask::SetAll()
	{
		for (tMaskChunk& CurrentChunk : mMask)
		{
			CurrentChunk = std::numeric_limits<tMaskChunk>::max();
		}
	}
	
	void BitMask::ClearBit(unsigned int aPosition)
	{
		unsigned int Chunk = aPosition / mMaskChunkSize;

		if (mMask.size() > Chunk)
		{	
			unsigned int PositionInChunk = aPosition % mMaskChunkSize;
			mMask.at(Chunk) &= ~(1U << PositionInChunk);
		}
	}

	void BitMask::ClearAll()
	{
		for (tMaskChunk& CurrentChunk : mMask)
		{
			CurrentChunk = 0;
		}
	}

	bool BitMask::IsBitSetted(unsigned int aPosition) const
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
	
	bool BitMask::operator!=(const BitMask& aBitMask) const
	{
		return mMask != aBitMask.mMask;
	}
}