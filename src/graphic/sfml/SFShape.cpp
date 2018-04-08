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
	arc::RectF pos = winPos() * arc::SFMainWindow::getInstance().getSize();

	return sf::FloatRect(pos.pos().x(), pos.pos().y(),
		pos.size().x(), pos.size().y());
}

void arc::SFShape::_colorItem(sf::Shape &item) const
{
	const arc::Texture &texture = getTexture();
	std::string filePath = texture.getFilePath();
	arc::Color l = texture.lineColor();
	arc::Color bg = texture.bgColor();

	item.setOutlineColor(sf::Color(l.r(), l.g(), l.b(), l.a()));
	if (texture.getFilePath().empty()) {
		item.setFillColor(sf::Color(bg.r(), bg.g(), bg.b(), bg.a()));
	}
	else {
		if (!arc::SFMainWindow::getInstance().TextureInCache
			(texture.getFilePath()))
			arc::SFMainWindow::getInstance().
				addTexture(texture.getFilePath());
		item.setTexture(arc::SFMainWindow::getInstance().
			getTextureCache(texture.getFilePath()).get(), false);
	}
}

void arc::SFShape::_displayItem(const sf::Drawable &item) const
{
	arc::SFMainWindow::getInstance().draw(item);
}
