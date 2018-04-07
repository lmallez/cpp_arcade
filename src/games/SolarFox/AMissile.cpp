//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AMissile.cpp
//

#include "AMissile.hpp"

arc::solarfox::AMissile::AMissile(arc::VertexF pos, arc::VertexF size,
	arc::Direction dir, float speed, float range):
	AMissile(arc::RectF(pos, size), dir, speed, range)
{
}

arc::solarfox::AMissile::AMissile(arc::RectF rect, arc::Direction dir,
	float speed, float range):
	_pos(rect), _dir(dir), _range(range), _speed(speed)
{
}

arc::RectF arc::solarfox::AMissile::getPos() const
{
	arc::RectF p;

	switch (_dir) {
	case UP:
		p = arc::RectF(_pos.pos(), {_pos.size().x(), _pos.size().y()});
		break;
	case LEFT:
		p = arc::RectF(_pos.pos(), {_pos.size().y(), _pos.size().x()});
		break;
	case DOWN:
		p = arc::RectF(_pos.pos(), {_pos.size().x(), _pos.size().y()});
		break;
	case RIGHT:
		p = arc::RectF(_pos.pos(), {_pos.size().y(), _pos.size().x()});
		break;
	default:
		break;
	}
	return p;
}

bool arc::solarfox::AMissile::move()
{
	return move(_speed);
}

bool arc::solarfox::AMissile::move(float speed)
{
	_dist += speed;
	_pos.rpos().moveDir(_dir, speed);
	return _dist < _range;
}

bool arc::solarfox::AMissile::collision(const arc::RectF &obj) const
{
	return getPos().isCollide(obj);
}
