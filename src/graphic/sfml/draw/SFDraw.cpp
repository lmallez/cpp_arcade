//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.cpp
//

#include "SFDraw.hpp"

arc::SFDraw::SFDraw(const RectF &geometry, std::shared_ptr<arc::IDraw> parent):
	ADraw(geometry, parent)
{
}

arc::SFDraw::SFDraw(const VertexF &pos, const VertexF &size,
	std::shared_ptr<arc::IDraw> parent):
	ADraw(arc::RectF(pos, size), parent)
{
}

arc::SFDraw::SFDraw(const arc::ADraw &ex):
	ADraw(ex.getGeometry(), ex.getParent())
{
}

arc::RectF arc::SFDraw::winPos() const
{
	RectF pos;

	if (!_parent) {
		pos = _geometry * arc::SFGraphic::initialize()->getSize();
	} else
		pos = _parent->winPos() * getGeometry();
	return pos;
}

void arc::SFDraw::displayItem(const sf::Drawable &item) const
{
	SFGraphic::initialize()->draw(item);
}
