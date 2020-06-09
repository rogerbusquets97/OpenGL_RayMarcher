#ifndef C_KEYBOARD_H
#define C_KEYBOARD_H

#include "Inputs.h"
#include <bitset>
#include <array>

namespace Engine
{
	class CKeyboard
	{
		friend class CInput;
	public:

		CKeyboard();

		InputAction GetKeyState(KeyId aKey) const noexcept;

	protected:

		void OnKeyEvent(KeyId aKey, InputAction aAction) noexcept;

	private:

		static std::array< InputAction, (size_t)KeyId::NUM_KEYS> mKeys;
	};
}
#endif