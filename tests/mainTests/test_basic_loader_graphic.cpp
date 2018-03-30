/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** test_basic_loader.cpp
*/

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include "src/graphic/IShape.hpp"
#include "src/games/BasicGame/BasicGame.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/core/loader/LibLoader.hpp"

int main(int ac, char **av)
{
	std::cout << "Load Graphic Library: " << av[1] << std::endl;
	arc::LibLoader GraphicLoader(av[1]);
	std::unique_ptr<arc::IGraphic> &graphicLib = GraphicLoader.getIGraphic();
	const arc::IShapeLoader &shapeLoader = graphicLib->getShapeLoader();
	std::cout << "Done" << std::endl;

	const std::unique_ptr<arc::IGame> &game = arc::BasicGame::getInstance();

	auto oskour = arc::EventHandler(<#initializer#>, <#initializer#>);

	game->start()->convert(shapeLoader)->draw();
	graphicLib->display();
	while (1) {
		game->update(oskour)->convert(shapeLoader)->draw();
		graphicLib->display();
	}
}