/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaShapeRect.hpp"

arc::CacaShapeRect::CacaShapeRect(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect) :
	ShapeRect(parent, texture, rect), CacaShape()
{
}

arc::CacaShapeRect::CacaShapeRect(const arc::ShapeRect &shape):
	ShapeRect(shape), CacaShape()
{
}

void arc::CacaShapeRect::draw() const
{
	arc::RectF geo = winGeometry();

	caca_draw_thin_box(arc::CacaMainWindow::getInstance().getCanvas().get(),
				geo.pos().x(),
				geo.pos().y(),
				geo.size().x(),
				geo.size().y());
	AShape::draw();
}
