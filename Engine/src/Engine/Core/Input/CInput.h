#ifndef C_INPUT_H
#define C_INPUT_H

#include <CSingleton.h>
#include "CKeyboard.h"
#include "Inputs.h"
#include "CMouse.h"

namespace rubEngine
{
	class CInput : public CSingleton<CInput>
	{
		friend class ModuleWindow;
	public:

		CInput();
		virtual ~CInput() = default;

		InputAction GetKeyState(KeyId aKey) const noexcept;
		InputAction GetMouseButtonState(MouseButton aButton) const noexcept;
		float GetMouseX() const noexcept;
		float GetMouseY() const noexcept;

	protected:

		void OnKeyEvent(KeyId aKey, InputAction aAction) noexcept;
		void OnEventMouseButton(MouseButton aButton, InputAction aAction) noexcept;
		void OnEventMouseMove(float x, float y) noexcept;

	private:
		
		std::shared_ptr<CKeyboard> mKeyboard;
		std::shared_ptr<CMouse> mMouse;
	};
}

#endif
