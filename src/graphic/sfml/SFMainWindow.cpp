//
// EPITECH PROJECT, 2018
// cpp_arcade - SFMainWindow.cpp
// File description:
// Created by Faudil Puttilli
//

#include "SFMainWindow.hpp"

arc::SFMainWindow &arc::SFMainWindow::getInstance()
{
	std::unique_ptr<SFMainWindow> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new SFMainWindow());
	return *instance;
}

arc::SFMainWindow::SFMainWindow(arc::VertexI size) :
	_window(
		std::make_unique<sf::RenderWindow>
			(sf::VideoMode((int)size.x(), (int)size.y()), WNAME))
{
	if (!_window->isOpen())
		throw arc::Exception("SF Graphic", "Can't open the Main "
			"Window");
}


void arc::SFMainWindow::setWindowSize(size_t x, size_t y)
{
	_window->setSize(sf::Vector2u((unsigned)x, (unsigned)y));
}

void arc::SFMainWindow::draw(const sf::Drawable &toDraw)
{
	_window->draw(toDraw);
}

void arc::SFMainWindow::close()
{
	_window->close();
}

arc::VertexF arc::SFMainWindow::getSize() const
{
	return VertexF(_window->getSize().x, _window->getSize().x);
}