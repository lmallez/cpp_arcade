//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreLoader.cpp
//

#include <src/games/Menu/MainMenu.hpp>
#include "CoreBuild.hpp"

arc::CoreBuild::CoreBuild(const std::string &lib, const std::string &game):
	_clock(CLOCK_TIME)
{
	if (!lib.empty())
		setGraphic(lib);
	if (!game.empty())
		setGame(game);
}

bool arc::CoreBuild::setGraphic(const std::string &name)
{
	return _loaderGraphic.load(name);
}

bool arc::CoreBuild::setGame(const std::string &name)
{
	return _loaderGame.load(name);
}

void arc::CoreBuild::start()
{
	if (!_loaderGame.getIGame() || !_loaderGraphic.getIGraphic())
		throw arc::Exception("run", "Invalid Game or Graphic");
	_loaderGame.getIGame()->start()->convert(_loaderGraphic.getIGraphic()->getShapeLoader())->draw();
	_loaderGraphic.getIGraphic()->display();
	/* Update _event */
}

void arc::CoreBuild::update()
{
	if (!_loaderGame.getIGame() || !_loaderGraphic.getIGraphic())
		throw arc::Exception("run", "Invalid Game or Graphic");
	_loaderGame.getIGame()->update(_event)->convert(_loaderGraphic.getIGraphic()->getShapeLoader())->draw();
	_loaderGraphic.getIGraphic()->display();
	/* Update _event */
}

void arc::CoreBuild::run()
{
	start();
	while (1) {/* Condition d'arret ?? */
		update();
		_clock.waitTime();
	}
}

void arc::CoreBuild::menu()
{
	arc::MainMenu::getInstance()->start();
	while (1) {
		arc::MainMenu::getInstance()->update(_event)->convert(_loaderGraphic.getIGraphic()->getShapeLoader())->draw();
		_loaderGraphic.getIGraphic()->display();
		_clock.waitTime();
	}
}
