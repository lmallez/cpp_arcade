//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AShape.cpp
//

#include "src/exception/Exception.hpp"
#include "AShape.hpp"

arc::AShape::AShape(std::SPTR<IShape> parent,
	const arc::Texture &texture,
	const RectF &geometry):
	_parent(parent), _geometry(geometry), _texture(texture)
{
}

arc::AShape::AShape(const arc::IShape &ex):
	AShape(ex.getParent(), ex.getTexture(), ex.getGeometry())
{
}

const std::SPTR<arc::IShape> &arc::AShape::getParent() const
{
	return _parent;
}

arc::IShape &arc::AShape::getChild(size_t pos) const
{
	if (pos >= _children.size())
		throw arc::Exception("IShape", "Invalid pos Child");
	return *(_children[pos]);
}

void arc::AShape::addChild(std::UPTR<arc::IShape> child)
{
	_children.push_back(std::move(child));
}

void arc::AShape::addChild(std::SPTR<arc::IShape> child)
{
	_children.push_back(std::move(child));
}

size_t arc::AShape::nbChild() const
{
	return _children.size();
}

const arc::Texture &arc::AShape::getTexture() const
{
	return _texture;
}

const arc::RectF &arc::AShape::getGeometry() const
{
	return _geometry;
}

void arc::AShape::setTexture(const arc::Texture &texture)
{
	_texture = texture;
}

void arc::AShape::setGeometry(const arc::RectF &geometry)
{
	_geometry = geometry;
}

arc::IShape &arc::AShape::operator[](size_t pos) const
{
	return getChild(pos);
}

void arc::AShape::operator<<(std::UPTR<arc::IShape> child)
{
	addChild(std::move(child));
}

void arc::AShape::operator<<(std::SPTR<arc::IShape> child)
{
	addChild(child);
}

arc::RectF arc::AShape::winPos() const
{
	arc::RectF geo = getGeometry();
	std::SPTR<IShape> parent = getParent();
	arc::RectF parentPos;

	if (!parent)
		return geo;
	else {
		parentPos = parent->winPos();
		geo.rpos() = parentPos.pos() + geo.pos() * parentPos.size();
		geo.rsize() = geo.size() * parentPos.size();
	}
	return geo;
}

void arc::AShape::drawChild() const
{
	for (size_t i = 0; i < _children.size(); i++)
		_children[i]->draw();
}

void arc::AShape::draw() const
{
	drawChild();
}