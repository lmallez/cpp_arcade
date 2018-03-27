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
	arc::RectF aled = winPos();
	arc::RectF pos = winPos() * arc::CacaMainWindow::getInstance().getSize();

	return arc::RectF(pos.pos().x() / 10, pos.pos().y() / 20,
		pos.size().x() / 10, pos.size().y() / 20);
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
