#include "CMouse.h"
#include <Log/Log.h>

std::array<rubEngine::InputAction, (size_t)rubEngine::MouseButton::Last> rubEngine::CMouse::mButtons = { rubEngine::InputAction::Released };

namespace rubEngine
{
	CMouse::CMouse()
	{
		mButtons = { InputAction::Released };
		mX = mY = 0.0f;
	}

	InputAction CMouse::GetButtonState(MouseButton aButton) const noexcept
	{
		return mButtons.at((size_t)aButton);
	}

	float CMouse::GetMouseX() const noexcept
	{
		return mX;
	}

	float CMouse::GetMouseY() const noexcept
	{
		return mY;
	}

	void CMouse::OnEventMouseButton(MouseButton aButton, InputAction aAction) noexcept
	{
		mButtons.at((size_t)aButton) = aAction;
	}

	void CMouse::OnEventMouseMove(float x, float y) noexcept
	{
		mX = x;
		mY = y;
	}
}
