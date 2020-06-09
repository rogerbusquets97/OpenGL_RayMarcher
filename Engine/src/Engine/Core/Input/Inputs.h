#ifndef ENGINE_WINDOW_INPUTS
#define ENGINE_WINDOW_INPUTS

namespace Engine
{
	enum class MouseButton
	{
		Left = 0U ,
		Middle,
		Right,
		Last
	};

	enum class InputAction
	{
		Released = 0U,
		Pressed,
		Repeat
	};

	enum class KeyId
	{
		Space = 0U,
		Comma,
		Semicolon,
		Enter,
		Escape,
		Delete,
		Num_0,
		Num_1,
		Num_2,
		Num_3,
		Num_4,
		Num_5,
		Num_6,
		Num_7,
		Num_8,
		Num_9,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		NUM_KEYS

		//TODO add the misssing keys
	};
}

#endif 
