//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ship.cpp
//

#include "src/graphic/shape/ShapeContainer.hpp"
#include "Ship.hpp"
#include "ShipMissile.hpp"

arc::solarfox::Ship::Ship(const arc::VertexS &mapSize,
	const arc::VertexF &shipSize, int life) :
	PlayerController({0.001, 0.001}, arc::KeyEvent::PRESSED, true, {0, 0}, {true, arc::RectF(0, 0, 1 - shipSize.x(), 1 - shipSize.y())}),
	_life(life), _maxLife(life)
{
	_pCtrlPos = {(float)mapSize.x() / 2, (float)mapSize.y() / 2};
}

void arc::solarfox::Ship::execKey(arc::EventHandler &event)
{
	PlayerController::execKey(event);
}

arc::RectF arc::solarfox::Ship::getPos() const
{
	return arc::RectF(_pCtrlPos.x(), _pCtrlPos.y(), 0.05, 0.05);
}


std::shared_ptr<arc::IShape>
arc::solarfox::Ship::drawShip(const std::shared_ptr<arc::IShape> &parent,
	arc::RectF pos, arc::Direction dir) const
{
	std::shared_ptr ship = std::make_shared<arc::ShapeContainer>(parent, pos);

	ship->addChild(std::make_shared<arc::ShapeRect>(ship, arc::Texture(arc::Color::Blue, arc::Color::Blue), arc::RectF(0.2, 0.2, 0.6, 0.6)));
	ship->addChild(std::make_shared<arc::ShapeRect>(ship, arc::Texture(arc::Color::Red, arc::Color::Red), _getCanonSize(dir)));
	return ship;
}

std::shared_ptr<arc::IShape>
arc::solarfox::Ship::draw(const std::shared_ptr<arc::IShape> &parent) const
{
	return drawShip(parent, getPos(), _pCtrlDir);
}

arc::RectF arc::solarfox::Ship::_getCanonSize(Direction dir) const
{
	arc::RectF canonPos;
	switch (dir) {
	case UP:
		canonPos = arc::RectF(0.3, 0, 0.4, 0.4);
		break;
	case DOWN:
		canonPos = arc::RectF(0.3, 0.6, 0.4, 0.4);
		break;
	case LEFT:
		canonPos = arc::RectF(0, 0.3, 0.4, 0.4);
		break;
	case RIGHT:
		canonPos = arc::RectF(0.6, 0.3, 0.4, 0.4);
		break;
	default:
		canonPos = arc::RectF(0, 0, 0, 0);
	}
	return canonPos;
}

std::shared_ptr<arc::IShape>
arc::solarfox::Ship::drawLife(const std::shared_ptr<arc::IShape> &zone, arc::RectF pos) const
{
	std::shared_ptr lifeContainer = std::make_shared<arc::ShapeContainer>(zone, pos);
	float elemSize = 1.0f / _maxLife;
	for (int i = 0; i < _life; i++) {
		arc::RectF shipPos = arc::RectF(elemSize * i, 0, elemSize, 1);
		lifeContainer->addChild(drawShip(lifeContainer, shipPos, UP));
	}
	return lifeContainer;
}

int arc::solarfox::Ship::getLife() const
{
	return _life;
}

void arc::solarfox::Ship::setLife(int life)
{
	_life = life;
}

bool arc::solarfox::Ship::moveLife(int nb)
{
	setLife(_life + nb);
	return (_life + nb <= 0);
}

std::shared_ptr<arc::solarfox::AMissile> arc::solarfox::Ship::shot() const
{
	auto b = _pCtrlPos;
	float size = BULLET_SIZE;
	float dec = 0.5f * (std::abs(getPos().size().x()) - size);
	if (_pCtrlDir == UP || _pCtrlDir == RIGHT)
		b.moveDir(&_pCtrlDir, dec);
	else
		b.moveDir(*_pCtrlDir, dec);
	std::shared_ptr<arc::solarfox::AMissile> a = std::make_unique<arc::solarfox::ShipMissile>(b, arc::VertexF(size, size), _pCtrlDir);
	return a;
}
