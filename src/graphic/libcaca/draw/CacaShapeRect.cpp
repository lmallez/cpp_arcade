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
	arc::Texture texture = getTexture();

	setColor(texture.bgColor(), arc::Color::Black);
	if (geo.size().x() > 2 || geo.size().y() > 2)
		caca_fill_box(arc::CacaMainWindow::getInstance().getCanvas().get(),
					geo.pos().x() + 1,
					geo.pos().y() + 1,
					geo.size().x() - 2,
					geo.size().y() - 2, '#');
	setColor(texture.lineColor(), arc::Color::Black);
	caca_draw_thin_box(arc::CacaMainWindow::getInstance().getCanvas().get(),
				geo.pos().x(),
				geo.pos().y(),
				geo.size().x(),
				geo.size().y());
	AShape::draw();
}
