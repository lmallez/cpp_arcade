//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ship.cpp
//

#include "src/graphic/shape/ShapeContainer.hpp"
#include "Ship.hpp"

arc::solarfox::Ship::Ship(const arc::VertexS &mapSize,
		const arc::VertexF &shipSize) :
	PlayerController({0.005, 0.005}, arc::KeyEvent::PRESSED, true, {0, 0}, {true, arc::RectF(0, 0, 1 - shipSize.x(), 1 - shipSize.y())})
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
arc::solarfox::Ship::draw(std::shared_ptr<arc::IShape> map) const
{
	std::shared_ptr ship = std::make_shared<arc::ShapeContainer>(map, getPos());

	ship->addChild(std::make_shared<arc::ShapeRect>(ship, arc::Texture(arc::Color::Blue, arc::Color::Blue), arc::RectF(0.2, 0.2, 0.6, 0.6)));
	ship->addChild(std::make_shared<arc::ShapeRect>(ship, arc::Texture(arc::Color::Red, arc::Color::Red), _getCanonSize()));
	return ship;
}

arc::RectF arc::solarfox::Ship::_getCanonSize() const
{
	arc::RectF canonPos;
	switch (_pCtrlDir) {
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
