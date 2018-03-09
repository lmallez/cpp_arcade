//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.cpp
//

#include "SFDraw.hpp"

arc::SFDraw::SFDraw(std::unique_ptr<arc::IDraw> parent)
{
	_parent = parent.get();
}

arc::SFDraw::~SFDraw()
{
}

std::unique_ptr<arc::IDraw> arc::SFDraw::getParent() const
{
	return _parent;
}

std::vector<std::unique_ptr<arc::IDraw>> arc::SFDraw::getChild() const
{
	return _child;
}

void arc::SFDraw::addChild(std::unique_ptr<arc::IDraw> child)
{
	_child.push_back(child);
}

arc::VertexI arc::SFDraw::getPos() const
{
	if (!_parent)
		return VertexI(
			SFGraphic::initialize()->getSize().x() * _pos.x(),
			SFGraphic::initialize()->getSize().y() * _pos.y());
	return _parent->getPos() * _pos;
}
