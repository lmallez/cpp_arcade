//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.cpp
//

#include "SFDraw.hpp"

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
