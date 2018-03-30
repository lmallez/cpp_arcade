//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicGame.cpp
//

#include "BasicGame.hpp"

arc::IGame &arc::BasicGame::getInstance()
{
	static arc::IGame *instance = nullptr;

	if (!instance)
		instance = (new BasicGame());
	return *instance;
}

arc::BasicGame::BasicGame():
	playerPos(RectF(0, 0, 0.1, 0.1))
{
}

std::shared_ptr<arc::IShape> arc::BasicGame::start()
{
	arc::Texture basic(arc::Color::Red, arc::Color::Blue);

	std::shared_ptr s1 = std::make_shared<arc::ShapeCircle>(nullptr, basic, playerPos);
	/*std::shared_ptr s2 = std::make_shared<arc::ShapeCircle>(s1, basic, playerPos);
	s1->addChild(s2);*/
	frame = 0;
	return s1;
}

std::shared_ptr<arc::IShape> arc::BasicGame::update(EventHandler &event)
{
	arc::Texture basic(arc::Color::Red, arc::Color::Blue);
	playerPos.rsize() = playerPos.size() + playerPos.size() * 0.001;
	frame++;

	execKey(event);
	std::shared_ptr s1 = std::make_shared<arc::ShapeCircle>(nullptr, basic, playerPos);
	std::shared_ptr s2 = std::make_shared<arc::ShapeText>(s1,
		arc::Texture(arc::Color::Yellow), RectF(0.5, 0.5, 0.25, 0.25), std::to_string(frame));
	std::shared_ptr s3 = std::make_shared<arc::ShapeRect>(s1,
		arc::Texture(arc::Color::Red, arc::Color::Cyan), RectF(0.1, 0.2, 0.25, 0.25));
	std::shared_ptr s4 = std::make_shared<arc::ShapeRect>(s1,
		arc::Texture(arc::Color::Red, arc::Color::Cyan), RectF(0.9 - 0.25, 0.2, 0.25, 0.25));
	std::shared_ptr s5 = std::make_shared<arc::ShapeRect>(s1,
		arc::Texture(arc::Color::Red, arc::Color::Black), RectF(0.1, 0.6, 0.75, 0.25));
	s1->addChild(s2);
	s1->addChild(s3);
	s1->addChild(s4);
	s1->addChild(s5);
	return s1;
}
