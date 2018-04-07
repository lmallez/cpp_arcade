//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedShape.cpp
//

#include "src/exception/Exception.hpp"
#include "AnimatedShape.hpp"

arc::AnimatedShape::AnimatedShape(
	const std::vector<std::SPTR<arc::IShape>> &obj, size_t update):
	AnimatedObject(update)
{
	if (obj.empty())
		throw arc::Exception("AnimatedShape", "Invalid Object");
}

std::SPTR<arc::IShape>
arc::AnimatedShape::draw(const std::SPTR<arc::IShape> &parent[[maybe_unused]]) const
{
	return _obj[_selected];
}

bool arc::AnimatedShape::collision(const arc::RectF &obj) const
{
	return _obj[_selected]->getGeometry().isCollide(obj);
}

void arc::AnimatedShape::nextFrame()
{
	_selected++;
	if (_selected > _obj.size())
		_selected = 0;
}
