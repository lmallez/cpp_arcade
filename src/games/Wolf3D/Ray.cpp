//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ray.cpp
//

#include <cmath>
#include <src/graphic/shape/ShapeContainer.hpp>
#include "Ray.hpp"
#include "WolfGame.hpp"

arc::wolf::Ray::Ray(float angle, size_t pos, float larg):
	_angle(angle), _pos(pos), _larg(larg)
{
}

arc::VertexF arc::wolf::Ray::castMath(const VertexF &playPos, float angle,
	const Map &map)
{
	arc::VertexF rayDir(
		cosf(_angle + angle),
		sinf(_angle + angle));
	arc::VertexF deltaDist(
		sqrtf(1 + powf(rayDir.y(), 2) / powf(rayDir.x(), 2)),
		sqrtf(1 + powf(rayDir.x(), 2) / powf(rayDir.y(), 2)));
	arc::VertexF sideDist(
		rayDir.x() < 0 ?
			(playPos.x() - (int)playPos.x()) * deltaDist.x() :
			((int)playPos.x() + 1 - playPos.x()) * deltaDist.x(),
		rayDir.y() < 0 ?
			(playPos.y() - (int)playPos.y()) * deltaDist.y() :
			((int)playPos.y() + 1 - playPos.y()) * deltaDist.y());
	arc::VertexF step(rayDir.x() < 0 ? -1 : 1, rayDir.y() < 0 ? -1 : 1);
	arc::VertexF rayPos = playPos;

	while (map.isOnMap((int)rayPos.x(), (int)rayPos.y())
		&& map.findOnMap((int)rayPos.x(), (int)rayPos.y()) == 0) {
		if (sideDist.x() < sideDist.y()) {
			sideDist.rx() += deltaDist.x();
			rayPos.rx() += step.x();
			_side = false;
		} else {
			sideDist.ry() += deltaDist.y();
			rayPos.ry() += step.y();
			_side = true;
		}
	}
	if (!_side)
		_dist = ((int)rayPos.x() - playPos.x() + (1 - step.x()) / 2) / rayDir.x();
	else
		_dist = ((int)rayPos.y() - playPos.y() + (1 - step.y()) / 2) / rayDir.y();
	_dist = _dist * cosf(_angle);
	return rayPos;
}

std::shared_ptr<arc::IShape>
arc::wolf::Ray::draw(const std::SPTR<arc::IShape> &parent) const
{
	float size = 1 / _dist;
	float pos = 0.5f - size / 2;
	arc::Texture texture = _side ?
		arc::Texture(arc::Color::Blue, arc::Color::Blue) :
		arc::Texture(arc::Color::White, arc::Color::White);
	auto a = std::MKS<arc::ShapeRect>(parent, texture, arc::RectF(_larg * _pos, pos, _larg, size));
	return a;
}

bool arc::wolf::Ray::collision(const arc::RectF &obj[[maybe_unused]]) const
{
	return false;
}
