//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// test_sfml_shape.cpp
//

#include <memory>
#include <SFML/Graphics/Font.hpp>
#include <src/graphic/sfml/draw/SFShapeCircle.hpp>
#include <src/graphic/sfml/SFShapeLoader.hpp>
#include "src/graphic/sfml/draw/SFShapeRect.hpp"
#include "src/graphic/sfml/draw/SFShapeText.hpp"

extern sf::Font consolasFont;

int main()
{
	std::unique_ptr<arc::SFGraphic> &aled = arc::SFGraphic::getInstance();
	arc::RectF center(0.25, 0.25, 0.5, 0.5);
	arc::RectF full(0.1, 0.1, 0.8, 0.8);
	arc::Texture basic(arc::Color::Blue, arc::Color::Red);
	auto jpp = arc::SFShapeLoader();

	consolasFont.loadFromFile("../assets/Consolas.ttf");

	std::shared_ptr s1 = std::make_shared<arc::ShapeCircle>(nullptr, basic, center);
	std::shared_ptr s2 = std::make_shared<arc::ShapeRect>(s1, basic, full);
	std::shared_ptr s3 = std::make_shared<arc::ShapeText>(s1, basic, full, "ALED");
	auto s12 = s1->convert(jpp);
	auto s22 = s2->convert(jpp);
	auto s32 = s3->convert(jpp);

	s12->draw();
	s22->draw();
	s32->draw();
	aled->display();
	while (1) {}
}