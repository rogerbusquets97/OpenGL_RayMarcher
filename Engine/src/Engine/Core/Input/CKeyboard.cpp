#include "CKeyboard.h"

std::array<rubEngine::InputAction, (size_t)rubEngine::KeyId::NUM_KEYS> rubEngine::CKeyboard::mKeys = { rubEngine::InputAction::Released };

namespace rubEngine
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
