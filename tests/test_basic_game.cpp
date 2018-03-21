/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** test_basic_game.cpp
*/

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include "src/graphic/IShape.hpp"
#include "src/games/BasicGame.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/graphic/sfml/SFShapeLoader.hpp"

extern sf::Font consolasFont;

int main()
{
	consolasFont.loadFromFile("../assets/Consolas.ttf");

	arc::BasicGame game;
	std::unique_ptr<arc::IGraphic> &aled = arc::SFGraphic::getInstance();
	const arc::IShapeLoader &jpp = aled->getShapeLoader();
	auto oskour = arc::EventHandler();

	game.start()->convert(jpp)->draw();
	aled->display();
	while (1) {
		game.update(oskour)->convert(jpp)->draw();
		aled->display();
	}
}