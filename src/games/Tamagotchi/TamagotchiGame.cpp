//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// TamagotchiGame.cpp
//

#include "src/graphic/shape/ShapeContainer.hpp"
#include "TamagotchiGame.hpp"

arc::IGame &arc::TamagotchiGame::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new TamagotchiGame();
	return *instance;
}


std::shared_ptr <arc::IShape> arc::TamagotchiGame::start()
{
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	return all;
}

std::shared_ptr <arc::IShape> arc::TamagotchiGame::update(EventHandler &event)
{
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	all->addChild(_tamago.draw(all, arc::RectF(0, 0, 1, 1)));
	return all;
}

arc::TamagotchiGame::TamagotchiGame():
	_tamago(arc::Texture(), arc::AnimatedTexture({}, arc::RectF(), 1))
{
	arc::AnimatedTexture body = arc::AnimatedTexture({
		arc::Texture(arc::Color::Red, arc::Color::Red),
		arc::Texture(arc::Color::Blue, arc::Color::Blue),
		arc::Texture(arc::Color::Green, arc::Color::Green)
	}, arc::RectF(0, 0.5, 1, 0.5), 0.5);
	_tamago.setBody(body);
	_tamago.setHead(arc::Texture(arc::Color::Blue, arc::Color::Yellow));
}
