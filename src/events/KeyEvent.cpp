//
// EPITECH PROJECT, 2018
// cpp_arcade - KeyEvent.cpp
// File description:
// Created by Faudil Puttilli
//


#include <src/exception/Exception.hpp>
#include "KeyEvent.hpp"

arc::KeyEvent::KeyEvent()
{
	std::memset(_btns, false, 38);
}

bool arc::KeyEvent::isKeyPressed(arc::KeyEvent::Key key)
{
	return _btns[key];
}

void arc::KeyEvent::setKeyPressed(arc::KeyEvent::Key key)
{
	if (key == Key::UNKNOWN || key >= 38)
		throw arc::Exception("Key assignation", "Bad key value");
	_btns[key] = true;
}

void arc::KeyEvent::setKeyState(arc::KeyEvent::Key key, bool isPressed)
{
	if (key == Key::UNKNOWN || key > 38)
		throw arc::Exception("Key assignation", "Bad key value");
	_btns[key] = isPressed;
}

void arc::KeyEvent::setKeyReleased(arc::KeyEvent::Key key)
{
	if (key == Key::UNKNOWN || key >= 38)
		throw arc::Exception("Key assignation", "Bad key value");
	_btns[key] = false;
}
