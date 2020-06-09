#ifndef  C_TIMER_H
#define C_TIMER_H

#include <chrono>

namespace rubEngine
{
	class CTimer
	{
	public:
		CTimer();
		float Mark();
		float Peek() const;

	private:
		std::chrono::steady_clock::time_point mLast;
	};
}

#endif 
