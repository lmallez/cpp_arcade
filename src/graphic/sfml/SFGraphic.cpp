//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.cpp
//

#include <SFML/Graphics/Drawable.hpp>
#include "SFGraphic.hpp"
#include "SFMainWindow.hpp"

std::unique_ptr<arc::IGraphic> &arc::SFGraphic::getInstance()
{
	static std::unique_ptr<arc::IGraphic> instance = nullptr;

	if (!instance)
		instance.reset(new SFGraphic());
	return instance;
}

void arc::SFGraphic::display() const
{
	arc::SFMainWindow::getInstance().display();
}