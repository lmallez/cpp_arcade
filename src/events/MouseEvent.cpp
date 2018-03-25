//
// EPITECH PROJECT, 2018
// cpp_arcade - MouseEvent.cpp
// File description:
// Created by Faudil Puttilli
//

#include "MouseEvent.hpp"

arc::MouseEvent::MouseEvent() :
	_pos(0, 0), _buttonClicked(arc::MouseEvent::NONE)
{
}

arc::Vertex<float> arc::MouseEvent::getPos() const
{
	return _pos;
}

void arc::MouseEvent::setPos(arc::Vertex<float> pos)
{
	_pos = pos;
}

arc::MouseEvent::MouseButton arc::MouseEvent::getButtonPressed() const
{
	return _buttonClicked;
}

void arc::MouseEvent::setButtonPressed(arc::MouseEvent::MouseButton btnClicked)
{
	_buttonClicked = btnClicked;
}
