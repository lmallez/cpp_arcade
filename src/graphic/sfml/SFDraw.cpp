//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.cpp
//

#include "SFDraw.hpp"

arc::RectI arc::SFDraw::winPos() const
{
	if (!_parent)
		return getGeometry() * SFGraphic::initialize()->getSize();
	_parent->winPos() * getGeometry;
}
