/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaShape.hpp"
#include "CacaMainWindow.hpp"

arc::CacaShape::CacaShape()
{
}

arc::RectF arc::CacaShape::winGeometry() const
{
	arc::RectF pos = winPos()
		* arc::CacaMainWindow::getInstance().getSize();

	return arc::RectF(pos.pos().x(), pos.pos().y(),
		pos.size().x(), pos.size().y());
}

void arc::CacaShape::setColor(const arc::Color &c1, const arc::Color &c2) const
{
	uint16_t fg = ((c1.a() / 16) & 0xF) << 12 | ((c1.r() / 16) & 0xF) << 8
		| ((c1.g() / 16) & 0xF) << 4 | ((c1.b() / 16) & 0xF);
	uint16_t bg = ((c2.a() / 16) & 0xF) << 12 | ((c2.r() / 16) & 0xF) << 8
		| ((c2.g() / 16) & 0xF) << 4 | ((c2.b() / 16) & 0xF);
	caca_set_color_argb(arc::CacaMainWindow::getInstance().getCanvas().get(),
			    fg, bg);
}

//void arc::CacaShape::_colorItem(sf::Shape &item) const
//{
//	arc::Texture texture = getTexture();
//	arc::Color l = texture.lineColor();
//	arc::Color bg = texture.bgColor();
//
//	item.setFillColor(sf::Color(bg.r(), bg.g(), bg.b(), bg.a()));
//	item.setOutlineColor(sf::Color(l.r(), l.g(), l.b(), l.a()));
//}
//
//void arc::CacaShape::_displayItem(const sf::Drawable &item) const
//{
//	arc::CacaMainWindow::getInstance().draw(item);
//}
