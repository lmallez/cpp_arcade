//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedContainer.cpp
//

#include "src/exception/Exception.hpp"
#include "AnimatedContainer.hpp"

arc::AnimatedContainer::AnimatedContainer(
	const std::vector<std::SPTR<arc::IObject>> &obj,
	size_t update):
	AnimatedObject(update), _obj(obj), _selected(0)
{
	if (obj.empty())
		throw arc::Exception("AnimatedContainer", "Invalid Object");
}

std::SPTR <arc::IShape>
arc::AnimatedContainer::draw(const std::SPTR <arc::IShape> &parent) const
{
	return _obj[_selected]->draw(parent);
}

bool arc::AnimatedContainer::collision(const RectF &obj) const
{
	return _obj[_selected]->collision(obj);
}

void arc::AnimatedContainer::nextFrame()
{
	_selected++;
	if (_selected > _obj.size())
		_selected = 0;
}
