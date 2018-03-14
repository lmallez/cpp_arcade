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
	arc::RectF pos = winPos();
	sf::FloatRect geometry(pos.pos().x(), pos.pos().y(),
		pos.size().x(), pos.size().y());
	sf::RectangleShape rect;

	std::cout << pos.pos().x() << " // " << pos.pos().y() << std::endl;
	std::cout << pos.size().x() << " // " << pos.size().y() << std::endl;
	rect.setPosition(sf::Vector2<float>(geometry.top, geometry.left));
	rect.setSize(sf::Vector2<float>(geometry.width, geometry.height));
	rect.setFillColor(sf::Color::White);
	displayItem(rect);
}

std::unique_ptr<arc::IDraw> arc::SFDrawRect::clone()
{
	return std::make_unique<arc::SFDrawRect>(*this);
}
