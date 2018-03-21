/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** tests_basic_full_loader.cpp
*/

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include <src/core/loader/GameLoader.hpp>
#include "src/graphic/IShape.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/core/loader/LibLoader.hpp"

int main(int ac, char **av)
{
	std::unique_ptr<arc::IGraphic> &graphicLib = arc::SFGraphic::getInstance();
	const arc::IShapeLoader &shapeLoader = graphicLib->getShapeLoader();

	std::cout << "Load Game: " << av[1] << std::endl;
	arc::GameLoader gameLoader(av[1]);
	std::unique_ptr<arc::IGame> &game = gameLoader.getIGame();
	std::cout << "Done" << std::endl;

	auto tempEvt = arc::EventHandler();

	game->start()->convert(shapeLoader)->draw();
	graphicLib->display();
	while (1) {
		game->update(tempEvt)->convert(shapeLoader)->draw();
		graphicLib->display();
	}
}