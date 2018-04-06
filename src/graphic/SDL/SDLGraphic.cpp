//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.cpp
//

#include "SDLGraphic.hpp"
#include "SDLMainWindow.hpp"

arc::IGraphic & arc::SDLGraphic::getInstance()
{
	static arc::IGraphic *instance = nullptr;

	if (!instance) {
		instance = new SDLGraphic();
	}
	return *instance;
}

void arc::SDLGraphic::display() const
{
	arc::SDLMainWindow::getInstance().display();
}

const arc::IShapeLoader &arc::SDLGraphic::getShapeLoader() const
{
	return _loader;
}

void arc::SDLGraphic::catchEvent(arc::EventHandler &handler)
{
	arc::SDLMainWindow::getInstance().pollEvent(handler);
}

void arc::SDLGraphic::close()
{
	arc::SDLMainWindow::getInstance().close();
}
