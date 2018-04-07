//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Monster.cpp
//

#include <random>
#include <memory>
#include "Monster.hpp"
#include "MonsterMissile.hpp"

arc::solarfox::Monster::Monster(arc::Direction dir, arc::VertexF size):
	_dir(dir), _size(size), _upDown(true)
{
	_pos = (float)(random() % 10) / (float)10;
	_upDown = (bool)(random());
}

std::SPTR<arc::IShape>
arc::solarfox::Monster::draw(const std::SPTR<arc::IShape> &parent) const
{
	return std::MKS<arc::ShapeRect>(parent, arc::Texture(arc::Color::Magenta, arc::Color::Red), _getPos());
}

void arc::solarfox::Monster::move(float speed)
{
	if (_pos >= 1 || _pos <= 0)
		_upDown = !_upDown;
	_pos = !_upDown ? (_pos + speed) : (_pos - speed);
}

std::SPTR<arc::solarfox::AMissile> arc::solarfox::Monster::shot() const
{
	std::SPTR<arc::solarfox::AMissile> a = std::MKU<arc::solarfox::MonsterMissile>(_getPos().pos(), arc::VertexF(0.05, 0.05), _dir);
	return a;
}

arc::RectF arc::solarfox::Monster::_getPos() const
{
	arc::RectF monsterPos;
	float pos = _pos * (1 - _size.x());

	switch (_dir) {
	case UP:
		monsterPos = arc::RectF(pos, 0, _size.x(), _size.y());
		break;
	case LEFT:
		monsterPos = arc::RectF(0, pos, _size.y(), _size.x());
		break;
	case DOWN:
		pos = 1 - pos;
		monsterPos = arc::RectF(pos, 1, -_size.x(), -_size.y());
		break;
	case RIGHT:
		pos = 1 - pos;
		monsterPos = arc::RectF(1, pos, -_size.y(), -_size.x());
		break;
	default:
		monsterPos = arc::RectF(0, 0, 0, 0);
	}
	return monsterPos;
}
