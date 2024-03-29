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

extern std::UPTR<sf::Font> consolasFont;

arc::IGraphic & arc::SFGraphic::getInstance(bool destroy)
{
	static std::UPTR<arc::IGraphic> instance = nullptr;

	if (!instance) {
		consolasFont.reset(new sf::Font());
		consolasFont->loadFromFile(ASSETS_DIR + "/Consolas.ttf");
		instance.reset(new SFGraphic());
	}
	if (destroy) {
		consolasFont.reset(nullptr);
		instance.reset(nullptr);
	}
	return *instance;
}

arc::SFGraphic::~SFGraphic()
{
	SFMainWindow::getInstance(true);
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
