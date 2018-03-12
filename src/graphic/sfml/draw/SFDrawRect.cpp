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
	sf::Rect geometry = ~winPos();
	sf::RectangleShape rect;

	rect.setPosition(sf::Vector2<float>(geometry.top, geometry.left));
	rect.setSize(sf::Vector2<float>(geometry.width, geometry.height));
	SFGraphic::initialize()->draw(rect);
}

std::unique_ptr<arc::IDraw> arc::SFDrawRect::clone()
{
	return std::make_unique<arc::SFDrawRect>(*this);
}
