//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicGame.cpp
//

#include "BasicGame.hpp"

arc::BasicGame::BasicGame():
	playerPos(RectF(0, 0, 0.1, 0.1))
{
}

std::shared_ptr<arc::IShape> arc::BasicGame::start()
{
	arc::Texture basic(arc::Color::Blue, arc::Color::Red);

	std::shared_ptr s1 = std::make_shared<arc::ShapeCircle>(nullptr, basic, playerPos);
	std::shared_ptr s2 = std::make_shared<arc::ShapeCircle>(s1, basic, playerPos);
	s1->addChild(s2);
	return s1;
}

std::shared_ptr<arc::IShape> arc::BasicGame::update(EventHandler &event)
{
	arc::Texture basic(arc::Color::Blue, arc::Color::Red);
	playerPos.rsize() = playerPos.size() + playerPos.size() * 0.0001;

	std::shared_ptr s1 = std::make_shared<arc::ShapeCircle>(nullptr, basic, playerPos);
	std::shared_ptr s2 = std::make_shared<arc::ShapeText>(s1, arc::Texture(arc::Color::Yellow), RectF(0.5, 0.5, 0.25, 0.25), "aled");
	std::shared_ptr s3 = std::make_shared<arc::ShapeRect>(s1, arc::Texture(arc::Color::Cyan, arc::Color::Red), RectF(0.1, 0.4, 0.25, 0.25));
	s1->addChild(s2);
	s1->addChild(s3);
	return s1;
}
