#ifndef ENGINE_BIT_MASK
#define ENGINE_BIT_MASK

#include "Core.h"

namespace Engine
{

	class ENGINE_API BitMask
	{
	public:

		BitMask();

		void SetPosition(unsigned int aPosition, bool aValue);

		bool GetPosition(unsigned int aPosition) const;

		bool operator==(const BitMask& aBitMask) const;

	private:
		unsigned int mMask;
	};
}

#endif 