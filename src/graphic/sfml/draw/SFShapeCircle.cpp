//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFShapeCircle.cpp
//

#include "SFShapeCircle.hpp"

arc::SFShapeCircle::SFShapeCircle(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::VertexF &pos, float radius):
	ShapeCircle(parent, texture, pos, radius), SFShape()
{

}

arc::SFShapeCircle::SFShapeCircle(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect):
	ShapeCircle(parent, texture, rect), SFShape()
{
}

arc::SFShapeCircle::SFShapeCircle(const arc::ShapeCircle &shape):
	ShapeCircle(shape), SFShape()
{
}

void arc::SFShapeCircle::draw() const
{
	sf::FloatRect geometry = winGeometry();
	sf::CircleShape circle;

	circle.setPosition(geometry.left, geometry.top);
	circle.setRadius(0.5);
	circle.setScale(geometry.width, geometry.height);
	circle.setOutlineThickness(SFML_BORDER_SIZE);
	_colorItem(circle);
	_displayItem(circle);
}