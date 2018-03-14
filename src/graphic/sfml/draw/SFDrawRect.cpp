//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawRect.cpp
//

#include "SFDrawRect.hpp"

arc::SFDrawRect::SFDrawRect(const arc::VertexF &pos, const arc::VertexF &size,
	std::shared_ptr<arc::IDraw> parent):
	SFDraw(pos, size, parent)
{

}

arc::SFDrawRect::SFDrawRect(const arc::RectF &rect,
	std::shared_ptr<arc::IDraw> parent):
	SFDraw(rect, parent)
{
}

arc::SFDrawRect::SFDrawRect(const arc::SFDrawRect &ex):
	SFDraw(ex)
{
}

void arc::SFDrawRect::draw() const
{
	sf::FloatRect geometry = _winGeometry();
	sf::RectangleShape rect;

	rect.setPosition(geometry.left, geometry.top);
	rect.setSize(sf::Vector2f(geometry.width, geometry.height));
	rect.setFillColor(sf::Color::White);
	_displayItem(rect);
}

std::unique_ptr<arc::IDraw> arc::SFDrawRect::clone()
{
	return std::make_unique<arc::SFDrawRect>(*this);
}
