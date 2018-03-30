//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.cpp
//

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include "SFGraphic.hpp"
#include "SFMainWindow.hpp"

extern sf::Font consolasFont;

arc::IGraphic & arc::SFGraphic::getInstance()
{
	static std::unique_ptr<arc::IGraphic> instance = nullptr;

	if (!instance) {
		consolasFont.loadFromFile("../assets/Consolas.ttf");
		instance.reset(new SFGraphic());
	}
	return *instance;
}

void arc::SFGraphic::display() const
{
	arc::SFMainWindow::getInstance().display();
}

const arc::IShapeLoader &arc::SFGraphic::getShapeLoader() const
{
	return _loader;
}

void arc::SFGraphic::catchEvent(arc::EventHandler &handler)
{
	arc::SFMainWindow::getInstance().pollEvent(handler);
}

void arc::SFGraphic::close()
{
	arc::SFMainWindow::getInstance().close();
}
