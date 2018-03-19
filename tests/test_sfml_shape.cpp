//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// test_sfml_shape.cpp
//

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/graphic/sfml/draw/SFDrawRect.hpp"
#include "src/graphic/sfml/draw/SFDrawCircle.hpp"
#include "src/graphic/sfml/draw/SFDrawText.hpp"
#include "src/std/Color.hpp"

extern sf::Font consolasFont;

int main(int ac, char **av)
{
	std::unique_ptr<arc::SFGraphic> &aled = arc::SFGraphic::initialize();
	arc::RectF center(0.25, 0.25, 0.5, 0.5);
	std::shared_ptr<arc::IDraw> shape1 =
		std::make_shared<arc::SFDrawCircle>(nullptr, arc::Texture(arc::Color::Blue, arc::Color::Red), center);
	std::shared_ptr<arc::IDraw> shape2 =
		std::make_shared<arc::SFDrawRect>(shape1, arc::Texture(arc::Color::Transparent, arc::Color::Yellow), center);
	std::shared_ptr<arc::IDraw> shape3 =
		std::make_shared<arc::SFDrawText>(shape2, arc::Texture(), center, "Score = 0");

	consolasFont.loadFromFile("../assets/Consolas.ttf");

	shape1->draw();
	shape2->draw();
	shape3->draw();
	aled->display();
	while (1);
}