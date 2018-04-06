//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SystemController.cpp
//

#include <src/games/Menu/MainMenu.hpp>
#include "SystemController.hpp"

arc::SystemController::SystemController()
{
	assignKey(arc::KeyEvent::Key::NUM1, arc::KeyEvent::JUSTPRESSED, &arc::SystemController::_prevGame);
	assignKey(arc::KeyEvent::Key::NUM2, arc::KeyEvent::JUSTPRESSED, &arc::SystemController::_restartGame);
	assignKey(arc::KeyEvent::Key::NUM3, arc::KeyEvent::JUSTPRESSED, &arc::SystemController::_nextGame);
	assignKey(arc::KeyEvent::Key::NUM4, arc::KeyEvent::JUSTPRESSED, &arc::SystemController::_prevGraphic);
	assignKey(arc::KeyEvent::Key::NUM5, arc::KeyEvent::JUSTPRESSED, &arc::SystemController::_nextGraphic);
	assignKey(arc::KeyEvent::Key::NUM9, arc::KeyEvent::JUSTPRESSED, &arc::SystemController::_backMenu);
	assignKey(arc::KeyEvent::Key::NUM0, arc::KeyEvent::JUSTPRESSED, &arc::SystemController::_exit);
}

void
arc::SystemController::assignKey(arc::KeyEvent::Key key, arc::KeyEvent::Status status, arc::SystemController::systemController_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_systemKey.insert(a);
}

void arc::SystemController::execKey(arc::EventHandler &event)
{
	for (auto pair : _systemKey) {
		arc::SystemController::execKey(event, pair.first);
	}
}

void arc::SystemController::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
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

void arc::SystemController::_prevGame(arc::EventHandler &event)
{
	std::cout << "prevGame" << std::endl;
	event.gameEvent().prevGame();
}

void arc::SystemController::_restartGame(arc::EventHandler &event)
{
	std::cout << "restartGame" << std::endl;
	event.gameEvent().setGame();
}

void arc::SystemController::_nextGame(arc::EventHandler &event)
{
	std::cout << "nextGame" << std::endl;
	event.gameEvent().nextGame();
}

void arc::SystemController::_prevGraphic(arc::EventHandler &event)
{
	std::cout << "prevGraphic" << std::endl;
	event.gameEvent().prevGraphic();
}

void arc::SystemController::_nextGraphic(arc::EventHandler &event)
{
	std::cout << "nextGraphic" << std::endl;
	event.gameEvent().nextGraphic();
}

void arc::SystemController::_backMenu(arc::EventHandler &event)
{
	std::cout << "backMenu" << std::endl;
	event.gameEvent().setMenu(true);
}

void arc::SystemController::_startGame(arc::EventHandler &event)
{
	std::cout << "startGame" << std::endl;
	event.gameEvent().setMenu(false);
}

void arc::SystemController::_exit(arc::EventHandler &event)
{
	std::cout << "exit" << std::endl;
	event.gameEvent().setExit(true);
}
