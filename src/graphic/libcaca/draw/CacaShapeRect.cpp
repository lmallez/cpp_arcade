/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaShapeRect.hpp"

arc::CacaShapeRect::CacaShapeRect(std::SPTR<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect) :
	ShapeRect(parent, texture, rect), CacaShape()
{
}

arc::CacaShapeRect::CacaShapeRect(const arc::ShapeRect &shape):
	ShapeRect(shape), CacaShape()
{
}

bool arc::CacaShapeRect::drawFromFile() const
{
	arc::RectF geo = winGeometry();
	arc::Texture texture = getTexture();
	if (texture.getFilePath().empty())
		return false;
	CacaMainWindow &win = arc::CacaMainWindow::getInstance();
	CacaImage *im;
	if (!win.TextureInCache(texture.getFilePath())) {
		im = new CacaImage(texture.getFilePath());
		win.addTexture(texture.getFilePath(), im);
	} else {
		im = win.getTextureCache(texture.getFilePath());
	}

	caca_dither_bitmap(arc::CacaMainWindow::getInstance().getCanvas().get(),
				geo.pos().x(), geo.pos().y(),
				geo.size().x(), geo.size().y(),
				im->getDither(),
				im->getPixels());
	return true;
}

void arc::CacaShapeRect::draw() const
{
	arc::RectF geo = winGeometry();
	arc::Texture texture = getTexture();

	setColor(texture.bgColor(), arc::Color::Black);
	if (drawFromFile() == true) {
		AShape::draw();
		return;
	}
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
