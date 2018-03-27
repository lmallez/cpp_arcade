/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** test_basic_game.cpp
*/

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include "src/graphic/IShape.hpp"
#include "src/games/BasicGame/BasicGame.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"

int main()
{
	std::unique_ptr<arc::IGraphic> &graphicLib = arc::SFGraphic::getInstance();
	const arc::IShapeLoader &shapeLoader = graphicLib->getShapeLoader();

	std::unique_ptr<arc::IGame> &game = arc::BasicGame::getInstance();

	auto tempEvt = arc::EventHandler();

	game->start()->convert(shapeLoader)->draw();
	graphicLib->display();
	while (1) {
		game->update(tempEvt)->convert(shapeLoader)->draw();
		graphicLib->display();
	}
}