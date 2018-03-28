//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// EventHandler.hpp
//

#ifndef CPP_ARCADE_EVENTHANDLER_HPP
#define CPP_ARCADE_EVENTHANDLER_HPP

#include "KeyEvent.hpp"
#include "MouseEvent.hpp"

namespace arc {
	class EventHandler {
	public:
		EventHandler() = default;
		KeyEvent &keyEvent();
		MouseEvent &mouseEvent();
	private:
		KeyEvent _keyEvent;
		MouseEvent _mouseEvent;
	};
}

#endif /* CPP_ARCADE_EVENTHANDLER_HPP */