//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SystemGame.hpp
//

#ifndef CPP_ARCADE_SYSTEMGAME_HPP
#define CPP_ARCADE_SYSTEMGAME_HPP

#include <unordered_map>
#include <algorithm>
#include "IGame.hpp"


namespace arc {
	class SystemGame {
		typedef void (SystemGame::*systemGame_t)(EventHandler &event);
	public:
		SystemGame();
		virtual void assignKey(arc::KeyEvent::Key, arc::KeyEvent::Status status,
			arc::SystemGame::systemGame_t);
		virtual void execKey(EventHandler &event);
		virtual void execKey(EventHandler &event, KeyEvent::Key key);

		void _prevGame(EventHandler &event);
		void _restartGame(EventHandler &event);
		void _nextGame(EventHandler &event);
		void _prevGraphic(EventHandler &event);
		void _nextGraphic(EventHandler &event);
		void _backMenu(EventHandler &event);
		void _startGame(EventHandler &event);
		void _exit(EventHandler &event);
	private:
		std::unordered_map<KeyEvent::Key, std::pair<KeyEvent::Status, systemGame_t>> _systemKey;
	};
}


#endif /* CPP_ARCADE_SYSTEMGAME_HPP */