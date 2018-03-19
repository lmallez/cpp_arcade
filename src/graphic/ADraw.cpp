//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ADraw.cpp
//

#include <src/exception/Exception.hpp>
#include "ADraw.hpp"

arc::ADraw::ADraw(std::shared_ptr<IDraw> parent,
	const arc::Texture &texture,
	const RectF &geometry)
{
	_geometry = geometry;
	_parent = parent;
	_texture = texture;
}

const std::shared_ptr<arc::IDraw> &arc::ADraw::getParent() const
{
	return _parent;
}

arc::IDraw &arc::ADraw::getChild(size_t pos)
{
	if (pos >= _children.size())
		throw arc::Exception("IDraw", "Invalid pos Child");
	return *(_children[pos]);
}

void arc::ADraw::addChild(std::unique_ptr<arc::IDraw> child)
{
	_children.push_back(std::move(child));
}

size_t arc::ADraw::nbChild() const
{
	return _children.size();
}

arc::RectF arc::ADraw::getGeometry() const
{
	return _geometry;
}

arc::RectF &arc::ADraw::getrGeometry()
{
	return _geometry;
}

void arc::ADraw::setGeometry(const arc::RectF &rect)
{
	_geometry = rect;
}

arc::IDraw &arc::ADraw::operator[](size_t pos)
{
	return getChild(pos);
}

void arc::ADraw::setTexture(const arc::Texture &texture)
{
	_texture = texture;
}

arc::Texture arc::ADraw::getTexture() const
{
	return _texture;
}

arc::Texture &arc::ADraw::getrTexture()
{
	return _texture;
}

arc::RectF &arc::ADraw::operator*()
{
	return getrGeometry();
}
