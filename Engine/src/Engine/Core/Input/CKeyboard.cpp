#include "CKeyboard.h"

std::array<Engine::InputAction, (size_t)Engine::KeyId::NUM_KEYS> Engine::CKeyboard::mKeys = { Engine::InputAction::Released };

namespace Engine
{
	CKeyboard::CKeyboard()
	{
		mKeys = { InputAction::Released };
	}

	InputAction CKeyboard::GetKeyState(KeyId aKey) const noexcept
	{
		return mKeys.at((size_t)aKey);
	}

	void CKeyboard::OnKeyEvent(KeyId aKey, InputAction aAction) noexcept
	{
		mKeys.at((size_t)aKey) = aAction;
	}
}
