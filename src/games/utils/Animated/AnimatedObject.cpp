//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedObject.cpp
//

#include "AnimatedObject.hpp"

arc::AnimatedObject::AnimatedObject(float update):
	_clock(update)
{
}

void arc::AnimatedObject::update()
{
	if (_clock.updateTime())
		nextFrame();
}
