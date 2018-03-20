//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.cpp
//

#include <SFML/Graphics/Drawable.hpp>
#include "SFGraphic.hpp"

std::unique_ptr<arc::SFGraphic> &arc::SFGraphic::getInstance()
{
	static std::unique_ptr<arc::SFGraphic> instance = nullptr;

	if (!instance)
		instance.reset(new SFGraphic());
	return instance;
}

arc::SFGraphic::~SFGraphic()
{
	_window->close();
}

arc::SFGraphic::SFGraphic(arc::VertexS size)
{
	_window = std::make_unique<sf::RenderWindow>();
	_window->create(sf::VideoMode((int)size.x(), (int)size.y()), WNAME);
	if (!_window->isOpen())
		throw arc::Exception("SFWindow", "Can't open Win");
}

arc::VertexF arc::SFGraphic::getSize() const
{
	return VertexF(_window->getSize().x, _window->getSize().y);
}

void arc::SFGraphic::display() const
{
	_window->display();
	_window->clear(sf::Color::Black);
}

void arc::SFGraphic::drawItem(const sf::Drawable &toDraw)
{
	_window->draw(toDraw);
}