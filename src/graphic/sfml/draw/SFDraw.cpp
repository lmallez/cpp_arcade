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
	RectF parentPos;

	if (!_parent) {
		pos = _geometry * arc::SFGraphic::initialize()->getSize();
	} else {
		parentPos = _parent->winPos();
		pos.rpos() = parentPos.pos() +
			_geometry.pos() * parentPos.size();
		pos.rsize() = _geometry.size() * parentPos.size();
	}
	return pos;
}


sf::FloatRect arc::SFDraw::_winGeometry() const
{
	arc::RectF pos = winPos();
	sf::FloatRect geometry(pos.pos().x(), pos.pos().y(), pos.size().x(), pos.size().y());

	return geometry;
}

void arc::SFDraw::_displayItem(const sf::Drawable &item) const
{
	SFGraphic::initialize()->draw(item);
}
