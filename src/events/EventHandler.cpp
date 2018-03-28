//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// EventHandler.cpp
//

#include "EventHandler.hpp"

arc::KeyEvent &arc::EventHandler::keyEvent() {
	return _keyEvent;
}

arc::MouseEvent &arc::EventHandler::mouseEvent() {
	return _mouseEvent;
}
