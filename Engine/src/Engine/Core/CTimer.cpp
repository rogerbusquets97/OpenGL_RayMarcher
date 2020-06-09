#include "CTimer.h"

using namespace std::chrono;

namespace rubEngine
{
	CTimer::CTimer()
	{
		mLast = steady_clock::now();
	}

	float CTimer::Mark()
	{
		const auto Old = mLast;
		mLast = steady_clock::now();
		const duration<float> FrameTime = mLast - Old;
		return FrameTime.count();
	}

	float CTimer::Peek() const
	{
		return duration<float>(steady_clock::now() - mLast).count();
	}
}