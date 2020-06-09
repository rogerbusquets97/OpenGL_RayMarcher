#include "CInput.h"

std::unique_ptr<rubEngine::CInput> rubEngine::CSingleton<rubEngine::CInput>::mInstance = nullptr;

namespace rubEngine
{
	CInput::CInput() : mKeyboard(std::make_shared<CKeyboard>()), mMouse(std::make_shared<CMouse>())
	{
	}

	InputAction CInput::GetKeyState(KeyId aKey) const noexcept
	{
		return mKeyboard->GetKeyState(aKey);
	}

	InputAction CInput::GetMouseButtonState(MouseButton aButton) const noexcept
	{
		return mMouse->GetButtonState(aButton);
	}

	float CInput::GetMouseX() const noexcept
	{
		return mMouse->GetMouseX();
	}

	float CInput::GetMouseY() const noexcept
	{
		return mMouse->GetMouseY();
	}

	void CInput::OnKeyEvent(KeyId aKey, InputAction aAction) noexcept
	{
		mKeyboard->OnKeyEvent(aKey, aAction);
	}
	void CInput::OnEventMouseButton(MouseButton aButton, InputAction aAction) noexcept
	{
		mMouse->OnEventMouseButton(aButton, aAction);
	}
	void CInput::OnEventMouseMove(float x, float y) noexcept
	{
		mMouse->OnEventMouseMove(x, y);
	}
}
