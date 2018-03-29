//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreLoader.cpp
//

#include <src/games/Menu/MainMenu.hpp>
#include "CoreBuild.hpp"

arc::CoreBuild::CoreBuild(const std::string &lib, const std::string &game):
	_clock(CLOCK_TIME), _menu(true)
{
	setGraphic(lib);
}

bool arc::CoreBuild::setGraphic(const std::string &name)
{
	_loaderGraphic.unload();
	return _loaderGraphic.load(name);
}

bool arc::CoreBuild::setGame(const std::string &name)
{
	bool status;

	_loaderGame.unload();
	status = _loaderGame.load(name);
	if (status)
		start();
	return status;
}

void arc::CoreBuild::setGraphic()
{
	std::pair<std::string, bool> &reloadGraphic = _event.gameEvent().getReloadGraphic();
	if (reloadGraphic.second) {
		setGraphic(std::string(DIR_GRAPHIC) + "/" + reloadGraphic.first);
		reloadGraphic.second = false;
	}
}

void arc::CoreBuild::setGame()
{
	std::pair<std::string, bool> &reloadGame = _event.gameEvent().getReloadGame();
	if (reloadGame.second) {
		setGame(std::string(DIR_GAME) + "/" + reloadGame.first);
		reloadGame.second = false;
	}
}

bool arc::CoreBuild::_checkEvent(arc::GameEvent &event)
{
	setGraphic();
	setGame();
	_menu = event.isMenu();
	return event.isExit();
}

void arc::CoreBuild::start()
{
	if (!_loaderGame.getIGame() || !_loaderGraphic.getIGraphic())
		throw arc::Exception("run", "Invalid Game or Graphic");
	_loaderGame.getIGame()->start()->convert(_loaderGraphic.getIGraphic()->getShapeLoader())->draw();
	_loaderGraphic.getIGraphic()->display();
}

void arc::CoreBuild::update()
{
	if (!_loaderGame.getIGame() || !_loaderGraphic.getIGraphic())
		throw arc::Exception("run", "Invalid Game or Graphic");
	_loaderGame.getIGame()->update(_event)->convert(_loaderGraphic.getIGraphic()->getShapeLoader())->draw();
	_loaderGraphic.getIGraphic()->display();
	_loaderGraphic.getIGraphic()->catchEvent(_event);
}

void arc::CoreBuild::menu()
{
	arc::MainMenu::getInstance()->update(_event)->convert(_loaderGraphic.getIGraphic()->getShapeLoader())->draw();
	_loaderGraphic.getIGraphic()->display();
	_loaderGraphic.getIGraphic()->catchEvent(_event);
}

void arc::CoreBuild::run()
{
	while (!_checkEvent(_event.gameEvent())) {
		_menu ? menu() : update();
		_clock.waitTime();
	}
}
