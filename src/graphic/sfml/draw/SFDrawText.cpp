//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawText.cpp
//

#include "SFDrawText.hpp"

sf::Font consolasFont = sf::Font();

arc::SFDrawText::SFDrawText(std::shared_ptr<IDraw> parent, const arc::Texture &texture,
	const VertexF &pos, const VertexF &size,
	const std::string &content) :
	SFDrawText(parent, texture, arc::RectF(pos, size), content)
{
}

arc::SFDrawText::SFDrawText(std::shared_ptr<IDraw> parent, const arc::Texture &texture,
	const RectF &rect, const std::string &content) :
	SFDraw(parent, texture, rect), _text(content, consolasFont)
{
}

arc::SFDrawText::SFDrawText(const arc::SFDrawText &ex):
	SFDraw(ex)
{
}

void arc::SFDrawText::draw() const
{
	sf::FloatRect geometry = _winGeometry();
	sf::Text text(_text);
	size_t len = text.getString().getSize();
	arc::Color color = _texture.lineColor();

	if (len == 0)
		return;
	text.setPosition(geometry.left, geometry.top);
	text.setCharacterSize((unsigned int)(geometry.width * SFML_TEXT_PADING / len));
	text.setFillColor(sf::Color(color.red(), color.green(),
		color.blue(), color.alpha()));
	_displayItem(text);
}

std::unique_ptr<arc::IDraw> arc::SFDrawText::clone()
{
	return std::make_unique<arc::SFDrawText>(*this);
}
