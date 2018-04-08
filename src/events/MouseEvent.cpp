//
// EPITECH PROJECT, 2018
// cpp_arcade - MouseEvent.cpp
// File description:
// Created by Faudil Puttilli
//

#include "MouseEvent.hpp"
#include <cstring>

arc::MouseEvent::MouseEvent() :
	_pos(0, 0)
{
	std::memset(_btns, false, BUTTON_NUMBER);
	std::memset(_oldSts, false, BUTTON_NUMBER);
}

arc::Vertex<float> arc::MouseEvent::getPos() const
{
	return _pos;
}

void arc::MouseEvent::setPos(arc::Vertex<float> pos)
{
	_pos = pos;
}

void arc::MouseEvent::setButtonReleased(arc::MouseEvent::MouseButton key)
{
	_btns[key] = false;
}

void arc::MouseEvent::setButtonPressed(arc::MouseEvent::MouseButton key)
{
	_btns[key] = true;
}

bool arc::MouseEvent::isButtonPressed(arc::MouseEvent::MouseButton key)
{
	return _btns[key];
}

bool arc::MouseEvent::isButtonjustPressed(arc::MouseEvent::MouseButton key)
{
	return _btns[key] && !_oldSts[key];
}

void arc::MouseEvent::makeOld()
{
	for (int i = 0; i < BUTTON_NUMBER; i++) {
		_oldSts[i] = _btns[i];
	}
}
