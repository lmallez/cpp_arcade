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

arc::RectI arc::SFDraw::winPos() const
{
	RectI pos;
	RectF temp;

	if (!_parent) {
		temp = _geometry * arc::SFGraphic::initialize()->getSize();
		pos = RectI(
			(int)temp.pos().x(),
			(int)temp.pos().y(),
			(int)temp.size().x(),
			(int)temp.size().y());
	} else
		pos = _parent->winPos() * getGeometry();
	return pos;
}
