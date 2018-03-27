/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** CacaGraphic.cpp
*/

#include "CacaGraphic.hpp"
#include "CacaMainWindow.hpp"

std::unique_ptr<arc::IGraphic> &arc::CacaGraphic::getInstance()
{
	static std::unique_ptr<arc::IGraphic> instance = nullptr;

	if (!instance) {
		instance.reset(new CacaGraphic());
	}
	return instance;
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
}
