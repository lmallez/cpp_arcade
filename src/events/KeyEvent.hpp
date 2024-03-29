//
// EPITECH PROJECT, 2018
// cpp_arcade - KeyEvent.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_KEYEVENT_HPP
#define CPP_ARCADE_KEYEVENT_HPP

#include <cstring>
#include <unordered_map>
#include <vector>

#define KEY_NUMBER 49

namespace arc
{
	class KeyEvent
	{
	public:
		enum Status {
			PRESSED,
			RELEASED,
			JUSTPRESSED,
			JUSTRELEASED
		};
		enum Key {
			UNKNOWN = -1,
			A = 0,
			B, C, D, E,
			F, G, H, I,
			J, K, L, M, N,
			O, P, Q, R,
			S, T, U, V,
			W, X, Y, Z,
			LEFT, RIGHT,
			UP, DOWN,
			ESCAPE, SPACE,
			LSHIFT, RSHIFT,
			TAB, MAJ, RETURN, BACKSPACE,
			NUM0, NUM1, NUM2, NUM3,
			NUM4, NUM5, NUM6,
			NUM7, NUM8, NUM9
		};
		KeyEvent();
		bool isKeyPressed(Key);
		void setKeyPressed(Key);
		void setKeyState(Key, bool isPressed);
		void setKeyReleased(Key);

		bool isKeyjustPressed(Key);
		bool isKeyjustReleased(Key);
		void makeOld();

	private:
		bool _btns[KEY_NUMBER];
		bool _oldSts[KEY_NUMBER];
	};
}
#endif //CPP_ARCADE_KEYEVENT_HPP
