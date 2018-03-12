//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawRect.cpp
//

#include "SFDrawRect.hpp"

arc::SFDrawRect::SFDrawRect(const arc::VertexS &pos, const arc::VertexS &size):
	_geometry(pos, size)
{
}

arc::SFDrawRect::SFDrawRect(const arc::RectS &rect):
	_geometry(rect)
{
}

void
arc::SFDrawRect::setGeometry(const arc::VertexS &pos, const arc::VertexS &size)
{
	_geometry = arc::Rect(pos, size);
}

void arc::SFDrawRect::setGeometry(const arc::RectS &rect)
{
	_geometry = rect;
}

arc::RectS &arc::SFDrawRect::getGeometry()
{
	return _geometry;
}

void arc::SFDrawRect::draw() const
{
	sf::Rect geometry = ~winPos();
	sf::RectangleShape rect;

	rect.setPosition(sf::Vector2<float>(geometry.top, geometry.left));
	rect.setSize(sf::Vector2<float>(geometry.width, geometry.height));
	SFGraphic::initialize()->draw(rect);
}
