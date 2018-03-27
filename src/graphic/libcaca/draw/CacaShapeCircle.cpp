/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaShapeCircle.hpp"

arc::CacaShapeCircle::CacaShapeCircle(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::VertexF &pos, float radius):
	ShapeCircle(parent, texture, pos, radius), CacaShape()
{

}

arc::CacaShapeCircle::CacaShapeCircle(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect):
	ShapeCircle(parent, texture, rect), CacaShape()
{
}

arc::CacaShapeCircle::CacaShapeCircle(const arc::ShapeCircle &shape):
	ShapeCircle(shape), CacaShape()
{
}

void arc::CacaShapeCircle::draw() const
{
	arc::RectF geo = winGeometry();
	arc::Texture texture = getTexture();

	setColor(texture.lineColor(), arc::Color::Black);
	caca_draw_thin_ellipse(arc::CacaMainWindow::getInstance().getCanvas().get(),
				geo.pos().x() + geo.size().x(),
				geo.pos().y() + geo.size().y(),
				geo.size().x(),
				geo.size().y());
	setColor(texture.bgColor(), arc::Color::Black);
	caca_fill_ellipse(arc::CacaMainWindow::getInstance().getCanvas().get(),
				geo.pos().x() + geo.size().x(),
				geo.pos().y() + geo.size().y(),
				geo.size().x() - 1,
				geo.size().y() - 1, '#');
	AShape::draw();
}
