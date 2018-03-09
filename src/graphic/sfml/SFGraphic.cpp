//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.cpp
//

#include "SFGraphic.hpp"

std::unique_ptr<arc::SFGraphic> &arc::SFGraphic::initialize()
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
	_window = std::make_unique<sf::Window>();
	_window->create(sf::VideoMode(size.x(), size.y()), WNAME);
	if (!_window)
		throw arc::Exception("SFWindow", "Can't creat Win");
}

arc::VertexI arc::SFGraphic::getSize() const
{
	return VertexI(_window->getSize().x, _window->getSize().y);
}
