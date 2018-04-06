//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShapeRect.cpp
//

#include "SDLShapeRect.hpp"

arc::SDLShapeRect::SDLShapeRect(std::SPTR<arc::IShape> parent,
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

	Sint16 x, y, sx, sy;

	x = (Sint16) geo.pos().x();
	y = (Sint16) geo.pos().y();
	sx = (Sint16) geo.size().x();
	sy = (Sint16) geo.size().y();
	boxColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
	x, y, sx + x, sy + y,
	_texture.bgColor().values());
	boxColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
		 x, y, sx + x, sy + y,
		 _texture.bgColor().values());
	rectangleColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
		 x, y, sx + x, sy + y,
		 _texture.lineColor().values());
	AShape::draw();
}