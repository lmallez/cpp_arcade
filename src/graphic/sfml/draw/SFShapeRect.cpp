//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFShapeRect.cpp
//

#include "SFShapeRect.hpp"

arc::SFShapeRect::SFShapeRect(std::SPTR<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect) :
	ShapeRect(parent, texture, rect), SFShape()
{
}

arc::SFShapeRect::SFShapeRect(const arc::ShapeRect &shape):
	ShapeRect(shape), SFShape()
{
}

void arc::SFShapeRect::draw() const
{
	sf::FloatRect geometry = winGeometry();
	sf::RectangleShape rect;

	rect.setPosition(geometry.left, geometry.top);
	rect.setSize(sf::Vector2f(geometry.width, geometry.height));
	rect.setOutlineThickness(SFML_BORDER_SIZE * geometry.width);
	_colorItem(rect);
	_displayItem(rect);
	AShape::draw();
}