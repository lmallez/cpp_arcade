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

bool arc::CacaShapeCircle::drawFromFile() const
{
	arc::RectF geo = winGeometry();
	arc::Texture texture = getTexture();
	if (texture.getFilePath().empty())
		return false;
	static std::unique_ptr<CacaImage> im = std::make_unique<CacaImage>(texture.getFilePath());

	caca_dither_bitmap(arc::CacaMainWindow::getInstance().getCanvas().get(),
				geo.pos().x(), geo.pos().y(),
				geo.size().x(), geo.size().y(),
				im->getDither(),
				im->getPixels());
	return true;
}

void arc::CacaShapeCircle::draw() const
{
	arc::RectF geo = winGeometry();
	arc::Texture texture = getTexture();

	setColor(texture.lineColor(), arc::Color::Black);
	if (drawFromFile() == true) {
		AShape::draw();
		return;
	}
	caca_draw_thin_ellipse(arc::CacaMainWindow::getInstance().getCanvas().get(),
				geo.pos().x() + geo.size().x() / 2,
				geo.pos().y() + geo.size().y() / 2,
				geo.size().x() / 2,
				geo.size().y() / 2);
	setColor(texture.bgColor(), arc::Color::Black);
	if (geo.size().x() > 1 || geo.size().y() > 1)
		caca_fill_ellipse(arc::CacaMainWindow::getInstance().getCanvas().get(),
					geo.pos().x() + geo.size().x() / 2,
					geo.pos().y() + geo.size().y() / 2,
					geo.size().x() / 2 - 1,
					geo.size().y() / 2 - 1,
					'#');
	AShape::draw();
}
