//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// EventHandler.cpp
//

#include "EventHandler.hpp"

arc::EventHandler::EventHandler(
	const std::string &graphic,
	const std::string &game):
	_gameEvent(graphic, game)
{
}

arc::KeyEvent &arc::EventHandler::keyEvent()
{
	return _keyEvent;
}

arc::MouseEvent &arc::EventHandler::mouseEvent()
{
	return _mouseEvent;
}

arc::GameEvent &arc::EventHandler::gameEvent()
{
	return _gameEvent;
}
