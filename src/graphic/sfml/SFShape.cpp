//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFShape.cpp
//

#include "SFShape.hpp"
#include "SFMainWindow.hpp"

arc::SFShape::SFShape()
{
}

sf::FloatRect arc::SFShape::winGeometry() const
{
	arc::RectF pos = winPos() * arc::SFGraphic::getInstance()->getSize();

	return sf::FloatRect(pos.pos().x(), pos.pos().y(),
		pos.size().x(), pos.size().y());
}

void arc::SFShape::_colorItem(sf::Shape &item) const
{
	arc::Texture texture = getTexture();
	arc::Color l = texture.lineColor();
	arc::Color bg = texture.bgColor();

	item.setFillColor(sf::Color(bg.r(), bg.g(), bg.b(), bg.a()));
	item.setOutlineColor(sf::Color(l.r(), l.g(), l.b(), l.a()));
}

void arc::SFShape::_displayItem(const sf::Drawable &item) const
{
	arc::SFMainWindow::getInstance().draw(item);
}