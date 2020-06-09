#include "CInput.h"

std::unique_ptr<rubEngine::CInput> rubEngine::CSingleton<rubEngine::CInput>::mInstance = nullptr;

namespace rubEngine
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
