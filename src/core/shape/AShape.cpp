//
// EPITECH PROJECT, 2018
// cpp_arcade - AShape.cpp
// File description:
// Created by Faudil Puttilli
//

#include "AShape.hpp"

arc::IShape &arc::AShape::operator[](size_t id)
{
	return getChild(id);
}

arc::IShape& arc::AShape::getChild(size_t id)
{
	return *_children[id];
}

bool arc::AShape::operator!() const
{
	return _children.size() == 0;
}

size_t arc::AShape::getChildNbr() const
{
	return _children.size();
}

void arc::AShape::addChild(std::unique_ptr<IShape> child)
{
	_children.push_back(std::move(child));
}

void arc::AShape::operator<<(std::unique_ptr<IShape> child)
{
	addChild(std::move(child));
}

arc::Texture arc::AShape::getTexture() const
{
	return _texture;
}

void arc::AShape::setTexture(const arc::Texture &texture)
{
	_texture = texture;
}

std::string arc::AShape::getType() const
{
	return _type;
}
