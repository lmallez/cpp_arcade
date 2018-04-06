//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShape.cpp
//

#include "SDLShape.hpp"
#include "SDLMainWindow.hpp"

arc::SDLShape::SDLShape()
{
}

arc::RectF arc::SDLShape::winGeometry() const
{
	return winPos() * arc::SDLMainWindow::getInstance().getSize();
}