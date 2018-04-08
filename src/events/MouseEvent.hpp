//
// EPITECH PROJECT, 2018
// cpp_arcade - MouseEvent.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_MOUSEEVENT_HPP
#define CPP_ARCADE_MOUSEEVENT_HPP

#include "src/std/Vertex.hpp"

#define BUTTON_NUMBER	3

namespace arc
{
	class MouseEvent
	{
	public:
		enum MouseButton {
			LEFT_BUTTON = 0,
			MIDDLE_BUTTON,
			RIGHT_BUTTON
		};
		MouseEvent();
		Vertex<float> getPos() const;
		void setPos(Vertex<float>);
		void setButtonPressed(MouseButton);
		void setButtonReleased(MouseButton);

		bool isButtonPressed(MouseButton);
		bool isButtonjustPressed(MouseButton);
		void makeOld();

	private:
		Vertex<float> _pos;
		bool _btns[BUTTON_NUMBER];
		bool _oldSts[BUTTON_NUMBER];
	};
}

#endif //CPP_ARCADE_MOUSEEVENT_HPP
