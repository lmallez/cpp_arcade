//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawText.cpp
//

#include "SFShapeText.hpp"

sf::Font consolasFont;

arc::SFShapeText::SFShapeText(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect,
	const std::string &text):
	ShapeText(parent, texture, rect, text), SFShape()
{
}

arc::SFShapeText::SFShapeText(const arc::ShapeText &shape):
	ShapeText(shape), SFShape()
{
}

void arc::SFShapeText::draw() const
{
	sf::FloatRect geometry = winGeometry();
	sf::Text text(getText(), consolasFont);
	size_t len = text.getString().getSize();
	arc::Color color = _texture.lineColor();

	if (len == 0)
		return;
	text.setPosition(geometry.left, geometry.top);
	text.setCharacterSize((unsigned int)(geometry.width * SFML_TEXT_PADING / len));
	text.setFillColor(sf::Color(color.r(), color.g(), color.b(), color.a()));
	_displayItem(text);
}
