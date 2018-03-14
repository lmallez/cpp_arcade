//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawCircle.cpp
//

#include "SFDrawCircle.hpp"

arc::SFDrawCircle::SFDrawCircle(const arc::VertexF &pos, const size_t &radius,
	std::shared_ptr<arc::IDraw> parent):
	SFDraw(arc::VertexF(pos.x() - radius / 2, pos.y() - radius / 2),
		arc::VertexF(radius, radius), parent)
{
}

arc::SFDrawCircle::SFDrawCircle(const arc::VertexF &pos,
	const arc::VertexF &size, std::shared_ptr<arc::IDraw> parent):
	SFDraw(pos, size, parent)
{
}

arc::SFDrawCircle::SFDrawCircle(const arc::RectF &rect,
	std::shared_ptr<arc::IDraw> parent):
	SFDraw(rect, parent)
{
}

arc::SFDrawCircle::SFDrawCircle(const arc::SFDrawCircle &ex):
	SFDraw(ex)
{
}

void arc::SFDrawCircle::draw() const
{
	sf::FloatRect geometry = _winGeometry();
	sf::CircleShape circle;

	circle.setPosition(geometry.left, geometry.top);
	circle.setRadius(0.5);
	circle.setScale(geometry.width, geometry.height);
	circle.setFillColor(sf::Color::Yellow);
	_displayItem(circle);
}

std::unique_ptr<arc::IDraw> arc::SFDrawCircle::clone()
{
}
