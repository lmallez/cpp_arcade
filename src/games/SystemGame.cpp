//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SystemGame.cpp
//

#include "SystemGame.hpp"

arc::SystemGame::SystemGame()
{
}

void
arc::SystemGame::assignKey(arc::KeyEvent::Key key,
	arc::SystemGame::systemGame_t func)
{
	auto a = std::make_pair(key, std::make_pair(arc::KeyEvent::Status::PRESSED, func));
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
	}
}

void arc::SystemGame::_prevGame(arc::EventHandler &event)
{
	std::pair reloadGame = event.gameEvent().getReloadGame();
	std::vector listGames = event.gameEvent().getListGames();
	auto b = std::find(listGames.begin(), listGames.end(), reloadGame.first);
	long a = std::distance(listGames.begin(), b);

	a = ((unsigned long)a == 0) ? (listGames.size() - 1) : (a - 1);
	event.gameEvent().setReloadGame(listGames[a], true);
}

void arc::SystemGame::_restartGame(arc::EventHandler &event)
{
	std::pair reloadGame = event.gameEvent().getReloadGame();

	event.gameEvent().setReloadGame(reloadGame.first, true);
}

void arc::SystemGame::_nextGame(arc::EventHandler &event)
{
	std::pair reloadGame = event.gameEvent().getReloadGame();
	std::vector listGames = event.gameEvent().getListGames();
	long a = std::distance(listGames.begin(), std::find(listGames.begin(), listGames.end(), reloadGame.first));

	a = ((unsigned long)a == listGames.size() - 1) ? 0 : (a + 1);
	event.gameEvent().setReloadGame(listGames[a], true);
}

void arc::SystemGame::_prevGraphic(arc::EventHandler &event)
{
	std::pair reloadGraphic = event.gameEvent().getReloadGraphic();
	std::vector listGraphics = event.gameEvent().getListGraphics();
	long a = std::distance(listGraphics.begin(), std::find(listGraphics.begin(), listGraphics.end(), reloadGraphic.first));

	a = ((unsigned long)a == 0) ? (listGraphics.size() - 1) : (a - 1);
	event.gameEvent().setReloadGame(listGraphics[a], true);
}

void arc::SystemGame::_nextGraphic(arc::EventHandler &event)
{
	std::pair reloadGraphic = event.gameEvent().getReloadGraphic();
	std::vector listGraphics = event.gameEvent().getListGraphics();
	long a = std::distance(listGraphics.begin(), std::find(listGraphics.begin(), listGraphics.end(), reloadGraphic.first));

	a = ((unsigned long)a == listGraphics.size() - 1) ? 0 : (a + 1);
	event.gameEvent().setReloadGame(listGraphics[a], true);
}

void arc::SystemGame::_backMenu(arc::EventHandler &event)
{
	event.gameEvent().setMenu(true);
}

void arc::SystemGame::_exit(arc::EventHandler &event)
{
	event.gameEvent().setExit(true);
}
