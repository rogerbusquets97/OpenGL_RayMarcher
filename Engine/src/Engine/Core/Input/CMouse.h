#ifndef  C_MOUSE_H
#define C_MOUSE_H

#include "Inputs.h"
#include <array>

namespace rubEngine
{
	class CMouse
	{
		friend class CInput;
	public:
		CMouse();
		InputAction GetButtonState(MouseButton aButton) const noexcept;
		float GetMouseX() const noexcept;
		float GetMouseY() const noexcept;

	protected:
		void OnEventMouseButton(MouseButton aButton, InputAction aAction) noexcept;
		void OnEventMouseMove(float x, float y) noexcept;

	private:
		static std::array< InputAction, (size_t)MouseButton::Last> mButtons;
		float mX;
		float mY;
	};
}
#endif // ! C_MOUSE_H

