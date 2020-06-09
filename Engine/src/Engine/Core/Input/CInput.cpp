#include "CInput.h"

std::unique_ptr<Engine::CInput> Engine::CSingleton<Engine::CInput>::mInstance = nullptr;

namespace Engine
{
	CInput::CInput() : mKeyboard(std::make_unique<CKeyboard>())
	{
	}

	InputAction CInput::GetKeyState(KeyId aKey) const noexcept
	{
		return mKeyboard->GetKeyState(aKey);
	}

	void CInput::OnKeyEvent(KeyId aKey, InputAction aAction) noexcept
	{
		mKeyboard->OnKeyEvent(aKey, aAction);
	}
}
