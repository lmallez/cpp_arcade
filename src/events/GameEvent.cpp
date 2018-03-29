//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// GameEvent.cpp
//

#include <iostream>
#include "src/std/DirectoryReader.hpp"
#include "GameEvent.hpp"

arc::GameEvent::GameEvent()
{
	loadListGraphics();
	loadListGames();
	setGraphic();
	setGame();
	_reloadGraphic.second = false;
	_menu = true;
	_exit = false;
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

void arc::GameEvent::prevGame()
{
	if (_posGame == 0)
		_posGame = _listGames.size() - 1;
	else
		_posGame--;
	setGame();
}

void arc::GameEvent::nextGame()
{
	if (_posGame == _listGames.size() - 1)
		_posGame = 0;
	else
		_posGame++;
	setGame();
}

void arc::GameEvent::setGame()
{
	_reloadGame.first = _listGames[_posGame];
	_reloadGame.second = true;
}

void arc::GameEvent::setGame(size_t pos)
{
	if (_listGames.size() > pos)
		throw arc::Exception("setGame", "Invalid index for lib");
	_posGame = pos;
	setGame();
}

void arc::GameEvent::prevGraphic()
{
	if (_posGraphic == 0)
		_posGraphic = _listGraphics.size() - 1;
	else
		_posGraphic--;
	setGraphic();
}

void arc::GameEvent::nextGraphic()
{
	if (_posGraphic == _listGraphics.size() - 1)
		_posGraphic = 0;
	else
		_posGraphic++;
	setGraphic();
}

void arc::GameEvent::setGraphic()
{
	_reloadGraphic.first = _listGraphics[_posGraphic];
	_reloadGraphic.second = true;
}

void arc::GameEvent::setGraphic(size_t pos)
{
	if (_listGraphics.size() > pos)
		throw arc::Exception("setGraphic", "Invalid index for lib");
	_posGraphic = pos;
	setGraphic();
}

const std::vector <std::string> &arc::GameEvent::getListGames() const
{
	return _listGames;
}

const std::vector <std::string> &arc::GameEvent::getListGraphics() const
{
	return _listGraphics;
}

bool arc::GameEvent::isMenu() const
{
	return _menu;
}

void arc::GameEvent::setMenu(bool menu)
{
	GameEvent::_menu = menu;
}

bool arc::GameEvent::isExit() const
{
	return _exit;
}

void arc::GameEvent::setExit(bool exit)
{
	GameEvent::_exit = exit;
}

std::pair<std::string, bool> &arc::GameEvent::getReloadGame()
{
	return _reloadGame;
}

std::pair<std::string, bool> &arc::GameEvent::getReloadGraphic()
{
	return _reloadGraphic;
}
