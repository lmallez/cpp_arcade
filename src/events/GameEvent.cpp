//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// GameEvent.cpp
//

#include "src/std/DirectoryReader.hpp"
#include "GameEvent.hpp"

arc::GameEvent::GameEvent()
{
	loadListGames();
	loadListGraphics();
}

std::vector<std::string> arc::GameEvent::loadListGames()
{
	_listGames.clear();
	_listGames = arc::DirectoryReader(DIR_GAME).fileName();
	return _listGames;
}

std::vector<std::string> arc::GameEvent::loadListGraphics()
{
	_listGraphics.clear();
	_listGraphics = arc::DirectoryReader(DIR_GRAPHIC).fileName();
	return _listGraphics;
}

const std::vector <std::string> &arc::GameEvent::getListGames() const
{
	return _listGames;
}

const std::vector <std::string> &arc::GameEvent::getListGraphics() const
{
	return _listGraphics;
}

const std::pair<std::string, bool> &arc::GameEvent::getReloadGame() const
{
	return _reloadGame;
}

void
arc::GameEvent::setReloadGame(const std::pair<std::string, bool> &reloadGame)
{
	_reloadGame.first = reloadGame.first;
	_reloadGame.second = reloadGame.second;
}

void arc::GameEvent::setReloadGame(const std::string &first, bool second)
{
	_reloadGame.first = first;
	_reloadGame.second = second;
}

const std::pair<std::string, bool> &arc::GameEvent::getReloadGraphic() const
{
	return _reloadGraphic;
}

void arc::GameEvent::setReloadGraphic(
	const std::pair<std::string, bool> &reloadGraphic)
{
	_reloadGraphic.first = reloadGraphic.first;
	_reloadGraphic.second = reloadGraphic.second;
}

void arc::GameEvent::setReloadGraphic(const std::string &first, bool second)
{
	_reloadGraphic.first = first;
	_reloadGraphic.second = second;
}

bool arc::GameEvent::isMenu() const
{
	return menu;
}

void arc::GameEvent::setMenu(bool menu)
{
	GameEvent::menu = menu;
}

bool arc::GameEvent::isExit() const
{
	return exit;
}

void arc::GameEvent::setExit(bool exit)
{
	GameEvent::exit = exit;
}
