/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** test_basic_loader.cpp
*/

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include "src/graphic/IShape.hpp"
#include "src/games/BasicGame.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/core/loader/LibLoader.hpp"

int main(int ac, char **av)
{
	arc::LibLoader basic_lic(av[1]);
	arc::BasicGame game;
	arc::EventHandler oskour = arc::EventHandler();
	std::unique_ptr<arc::IGraphic> &aled = basic_lic.getIGraphic();
	const arc::IShapeLoader &jpp = aled->getShapeLoader();

	game.start()->convert(jpp)->draw();
	aled->display();
	while (1) {
		game.update(oskour)->convert(jpp)->draw();
		aled->display();
	}
}