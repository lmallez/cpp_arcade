//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedObject.cpp
//

#include "AnimatedObject.hpp"

arc::AnimatedObject::AnimatedObject(size_t update):
	_clock(update)
{
}

void arc::AnimatedObject::update()
{
	if (_clock.updateTime())
		nextFrame();
}
