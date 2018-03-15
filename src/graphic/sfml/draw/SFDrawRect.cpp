//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawRect.cpp
//

#include "SFDrawRect.hpp"

arc::SFDrawRect::SFDrawRect(std::shared_ptr<IDraw> parent, const VertexF &pos,
		const VertexF &size) :
	SFDraw(parent, pos, size)
{

}

arc::SFDrawRect::SFDrawRect(std::shared_ptr<IDraw> parent, const RectF &rect) :
	SFDraw(parent, rect)
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
