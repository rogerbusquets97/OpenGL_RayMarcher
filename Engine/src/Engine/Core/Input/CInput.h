#ifndef C_INPUT_H
#define C_INPUT_H

#include <CSingleton.h>
#include "CKeyboard.h"
#include "Inputs.h"

namespace rubEngine
{
	class CInput : public CSingleton<CInput>
	{
		friend class ModuleWindow;
	public:

		CInput();
		virtual ~CInput() = default;

		InputAction GetKeyState(KeyId aKey) const noexcept;

	protected:

		void OnKeyEvent(KeyId aKey, InputAction aAction) noexcept;

	private:
		
		const std::unique_ptr<CKeyboard>& mKeyboard;
	};
}

#endif
