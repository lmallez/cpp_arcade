//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SystemGame.cpp
//

#include <src/games/Menu/MainMenu.hpp>
#include "SystemGame.hpp"

arc::SystemGame::SystemGame()
{
	assignKey(arc::KeyEvent::Key::NUM4, arc::KeyEvent::JUSTPRESSED, &arc::SystemGame::_prevGame);
	assignKey(arc::KeyEvent::Key::NUM2, arc::KeyEvent::JUSTPRESSED, &arc::SystemGame::_restartGame);
	assignKey(arc::KeyEvent::Key::NUM3, arc::KeyEvent::JUSTPRESSED, &arc::SystemGame::_nextGame);
	assignKey(arc::KeyEvent::Key::NUM4, arc::KeyEvent::JUSTPRESSED, &arc::SystemGame::_prevGraphic);
	assignKey(arc::KeyEvent::Key::NUM5, arc::KeyEvent::JUSTPRESSED, &arc::SystemGame::_nextGraphic);
	assignKey(arc::KeyEvent::Key::NUM6, arc::KeyEvent::JUSTPRESSED, &arc::SystemGame::_backMenu);
	assignKey(arc::KeyEvent::Key::NUM7, arc::KeyEvent::JUSTPRESSED, &arc::SystemGame::_exit);
}

void
arc::SystemGame::assignKey(arc::KeyEvent::Key key, arc::KeyEvent::Status status,
	arc::SystemGame::systemGame_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_systemKey.insert(a);
}

void arc::SystemGame::execKey(arc::EventHandler &event)
{
	for (auto pair : _systemKey) {
		execKey(event, pair.first);
	}
}

void arc::SystemGame::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	switch (_systemKey[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_systemKey[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_systemKey[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_systemKey[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_systemKey[key].second))(event);
		break;
	}
}

void arc::SystemGame::_prevGame(arc::EventHandler &event)
{
	std::cout << "prevGame" << std::endl;
	event.gameEvent().prevGame();
}

void arc::SystemGame::_restartGame(arc::EventHandler &event)
{
	std::cout << "restartGame" << std::endl;
	event.gameEvent().setGame();
}

void arc::SystemGame::_nextGame(arc::EventHandler &event)
{
	std::cout << "nextGame" << std::endl;
	event.gameEvent().nextGame();
}

void arc::SystemGame::_prevGraphic(arc::EventHandler &event)
{
	std::cout << "prevGraphic" << std::endl;
	event.gameEvent().prevGraphic();
}

void arc::SystemGame::_nextGraphic(arc::EventHandler &event)
{
	std::cout << "nextGraphic" << std::endl;
	event.gameEvent().nextGraphic();
}

void arc::SystemGame::_backMenu(arc::EventHandler &event)
{
	std::cout << "backMenu" << std::endl;
	event.gameEvent().setMenu(true);
}

void arc::SystemGame::_exit(arc::EventHandler &event)
{
	std::cout << "_exit" << std::endl;
	event.gameEvent().setExit(true);
}
