//
// EPITECH PROJECT, 2018
// cpp_arcade - KeyEvent.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_KEYEVENT_HPP
#define CPP_ARCADE_KEYEVENT_HPP

#include <cstring>

namespace arc
{
	class KeyEvent
	{
	public:
		enum Key {
			UNKNOWN = -1,
			A = 0,
			B, C, D, E,
			F, G, H, I,
			K, L, M, N,
			O, P, Q, R,
			S, T, U, V,
			W, X, Y, Z,
			LEFT, RIGHT,
			UP, DOWN,
			ESCAPE, SPACE,
			LSHIFT, RSHIFT,
			TAB, MAJ, RETURN
		};
		KeyEvent();
		bool isKeyPressed(Key);
		void setKeyPressed(Key);
		void setKeyState(Key, bool isPressed);
		void setKeyReleased(Key);
	private:
		bool _btns[38];
	};
}
#endif //CPP_ARCADE_KEYEVENT_HPP
