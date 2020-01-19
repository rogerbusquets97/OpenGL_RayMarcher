#include "BitMask.h"

namespace Engine
{
	BitMask::BitMask() :
		mMask(0U)
	{

	}

	void BitMask::SetPosition(unsigned int aPosition, bool aValue)
	{
		if (aValue)
		{
			mMask |= 1U << aPosition;
		}
		else
		{
			mMask &= ~(1U << aPosition);
		}
	}

	bool BitMask::GetPosition(unsigned int aPosition) const
	{
		return mMask & (1U << aPosition);
	}

	bool BitMask::operator==(const BitMask& aBitMask) const
	{
		return mMask == aBitMask.mMask;
	}

}