//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreLoader.cpp
//

#include "src/games/Menu/MainMenu.hpp"
#include "CoreBuild.hpp"

arc::CoreBuild::CoreBuild(const std::string &lib, const std::string &game):
	_menu(true), _event(lib, game), _clock(CLOCK_TIME)
{
	setGraphic(lib);
	if (!game.empty())
		setGame(game);
}

arc::CoreBuild::~CoreBuild()
{
}

bool arc::CoreBuild::setGraphic(const std::string &name)
{
	if (!!_loaderGraphic) {
		_loaderGraphic.getIGraphic().close();
		_loaderGraphic.unload();
	}
	return _loaderGraphic.load(name);
}

bool arc::CoreBuild::setGame(const std::string &name)
{
	bool status;

	if (!!_loaderGame) {
		_loaderGame.unload();
	}
	status = _loaderGame.load(name);
	if (status)
		start();
	return status;
}

void arc::CoreBuild::updateGraphic()
{
	auto &reloadGraphic = _event.gameEvent().getReloadGraphic();

	if (reloadGraphic.second) {
		setGraphic(std::string(DIR_GRAPHIC) + "/"
			+ reloadGraphic.first);
		reloadGraphic.second = false;
	}
}

void arc::CoreBuild::updateGame()
{
	auto &reloadGame = _event.gameEvent().getReloadGame();

	if (reloadGame.second) {
		setGame(std::string(DIR_GAME) + "/" + reloadGame.first);
		reloadGame.second = false;
	}
}

bool arc::CoreBuild::_checkEvent(arc::GameEvent &event)
{
	_menu = event.isMenu();
	if (!_menu) {
		updateGraphic();
		updateGame();
	}
	return event.isExit();
}

void arc::CoreBuild::start()
{
	_loaderGame.getIGame().start()->convert(_loaderGraphic.getIGraphic().
					getShapeLoader())->draw();
	_loaderGraphic.getIGraphic().display();
}

void arc::CoreBuild::update()
{
	_loaderGame.getIGame().update(_event)->convert(_loaderGraphic.
						getIGraphic().
						getShapeLoader())->draw();
	_loaderGraphic.getIGraphic().display();
	_loaderGraphic.getIGraphic().catchEvent(_event);
}

void arc::CoreBuild::menu()
{
	arc::MainMenu::getInstance().update(_event)->convert(_loaderGraphic.
						getIGraphic().
						getShapeLoader())->draw();
	_loaderGraphic.getIGraphic().display();
	_loaderGraphic.getIGraphic().catchEvent(_event);
}

void arc::CoreBuild::run()
{
	arc::MainMenu::getInstance();
	while (!_checkEvent(_event.gameEvent())) {
		_menu ? menu() : update();
		_clock.waitTime();
	}
	_loaderGame.unload();
	_loaderGraphic.unload();
}
