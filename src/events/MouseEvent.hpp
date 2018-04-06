//
// EPITECH PROJECT, 2018
// cpp_arcade - MouseEvent.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_MOUSEEVENT_HPP
#define CPP_ARCADE_MOUSEEVENT_HPP

#include <src/std/Vertex.hpp>

namespace arc
{
	class MouseEvent
	{
	public:
		enum MouseButton {
			NONE,
			LEFT_BUTTON,
			MIDDLE_BUTTON,
			RIGHT_BUTTON
		};
		MouseEvent();
		Vertex<float> getPos() const;
		void setPos(Vertex<float>);
		MouseButton getButtonPressed() const;
		void setButtonPressed(MouseButton);
		void setButtonReleased(MouseButton);
	private:
		Vertex<float> _pos;
		MouseButton _buttonClicked;
	};
}

#endif //CPP_ARCADE_MOUSEEVENT_HPP
