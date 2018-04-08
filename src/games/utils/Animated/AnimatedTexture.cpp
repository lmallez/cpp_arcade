//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedShape.cpp
//

#include "src/exception/Exception.hpp"
#include "AnimatedTexture.hpp"

arc::AnimatedTexture::AnimatedTexture(const std::vector<Texture> &obj, arc::RectF pos,
		float update) :
	AnimatedObject(update), _obj(obj), _pos(pos), _selected(0)
{
}

std::SPTR<arc::IShape>
arc::AnimatedTexture::draw(const std::SPTR<arc::IShape> &parent) const
{
	if (_obj.empty())
		throw arc::Exception("Anim(atedTexture", "Invalid Object");
	return std::MKS<arc::ShapeRect>(parent, _obj[_selected], _pos);
}

bool arc::AnimatedTexture::collision(const arc::RectF &obj) const
{
	return _pos.isCollide(obj);
}

void arc::AnimatedTexture::nextFrame()
{
	_selected++;
	if (_selected >= _obj.size())
		_selected = 0;
}
