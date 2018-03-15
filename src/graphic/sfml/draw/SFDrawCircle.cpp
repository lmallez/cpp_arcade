//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawCircle.cpp
//

#include "SFDrawCircle.hpp"

arc::SFDrawCircle::SFDrawCircle(std::shared_ptr<IDraw> parent, const VertexF &pos,
		const size_t &radius) :
	SFDraw(parent, arc::VertexF(pos.x() - radius / 2, pos.y() - radius / 2),
		arc::VertexF(radius, radius))
{
}

arc::SFDrawCircle::SFDrawCircle(std::shared_ptr<IDraw> parent, const VertexF &pos,
		const VertexF &size) :
	SFDraw(parent, pos, size)
{
}

arc::SFDrawCircle::SFDrawCircle(std::shared_ptr<IDraw> parent, const RectF &rect)
	:
	SFDraw(parent, rect)
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
	return std::make_unique<arc::SFDrawCircle>(*this);
}
