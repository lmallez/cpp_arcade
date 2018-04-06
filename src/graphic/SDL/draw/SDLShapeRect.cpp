//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShapeRect.cpp
//

#include "SDLShapeRect.hpp"

arc::SDLShapeRect::SDLShapeRect(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect) :
	ShapeRect(parent, texture, rect), SDLShape()
{
}

arc::SDLShapeRect::SDLShapeRect(const arc::ShapeRect &shape):
	ShapeRect(shape), SDLShape()
{
}

void arc::SDLShapeRect::draw() const
{
	RectF geo = winGeometry();
	boxColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
		 (Sint16)geo.pos().x(), (Sint16) geo.pos().y(),
		 (Sint16) geo.size().x(), (Sint16) geo.size().y(),
	_texture.bgColor().values());
}