/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** CacaGraphic.cpp
*/

#include "CacaGraphic.hpp"
#include "CacaMainWindow.hpp"

arc::IGraphic & arc::CacaGraphic::getInstance(bool destroy)
{
	static std::UPTR<arc::IGraphic> instance = nullptr;

	if (!instance) {
		instance.reset(new CacaGraphic());
	}
	if (destroy)
		instance.reset(nullptr);
	return *instance;
}

void arc::CacaGraphic::display() const
{
	arc::CacaMainWindow::getInstance().display();
}

const arc::IShapeLoader &arc::CacaGraphic::getShapeLoader() const
{
	return _loader;
}

void arc::CacaGraphic::catchEvent(arc::EventHandler &handler)
{
	arc::CacaMainWindow::getInstance().pollEvent(handler);
}

void arc::CacaGraphic::close()
{
	arc::CacaMainWindow::getInstance().close();
}
