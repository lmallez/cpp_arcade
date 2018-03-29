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
	std::memset(_btns, false, KEY_NUMBER);
	std::memset(_oldSts, false, KEY_NUMBER);
}

bool arc::KeyEvent::isKeyPressed(arc::KeyEvent::Key key)
{
	return _btns[key];
}

void arc::KeyEvent::setKeyPressed(arc::KeyEvent::Key key)
{
	if (key == Key::UNKNOWN || key >= KEY_NUMBER)
		throw arc::Exception("Key assignation", "Bad key value");
	_oldSts[key] = _btns[key];
	_btns[key] = true;
}

void arc::KeyEvent::setKeyState(arc::KeyEvent::Key key, bool isPressed)
{
	if (key == Key::UNKNOWN || key > KEY_NUMBER)
		throw arc::Exception("Key assignation", "Bad key value");
	_oldSts[key] = _btns[key];
	_btns[key] = isPressed;
}

void arc::KeyEvent::setKeyReleased(arc::KeyEvent::Key key)
{
	if (key == Key::UNKNOWN || key >= KEY_NUMBER)
		throw arc::Exception("Key assignation", "Bad key value");
	_oldSts[key] = _btns[key];
	_btns[key] = false;
}

bool arc::KeyEvent::isKeyjustPressed(arc::KeyEvent::Key key)
{
	return _btns[key] && !_oldSts[key];
}

bool arc::KeyEvent::isKeyjustReleased(arc::KeyEvent::Key key)
{
	return !_btns[key] && _oldSts[key];
}

void arc::KeyEvent::makeOld()
{
	for (int i = 0; i < KEY_NUMBER; i++)
		_oldSts[i] = _btns[i];
}
