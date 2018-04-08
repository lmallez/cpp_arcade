//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// WolfGame.cpp
//

#include <cmath>
#include <src/graphic/shape/ShapeContainer.hpp>
#include <src/graphic/shape/ShapeText.hpp>
#include "WolfGame.hpp"

arc::IGame &arc::WolfGame::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new WolfGame();
	return *instance;
}

arc::WolfGame::WolfGame():
	_mapMgr(WOLF_ASSETS_DIR + "/map")
{
	assignKey(KeyEvent::Z, KeyEvent::PRESSED, &arc::WolfGame::_moveUp);
	assignKey(KeyEvent::Q, KeyEvent::PRESSED, &arc::WolfGame::_moveLeft);
	assignKey(KeyEvent::S, KeyEvent::PRESSED, &arc::WolfGame::_moveDown);
	assignKey(KeyEvent::D, KeyEvent::PRESSED, &arc::WolfGame::_moveRight);
}

void arc::WolfGame::assignKey(arc::KeyEvent::Key key,
	arc::KeyEvent::Status status, arc::WolfGame::WolfEvt_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_wolfEvent.insert(a);
}

void arc::WolfGame::execKey(arc::EventHandler &event)
{
	SystemController::execKey(event);
	for (auto key : _wolfEvent) {
		execKey(event, key.first);
	}
}

void arc::WolfGame::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	switch (_wolfEvent[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_wolfEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_wolfEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_wolfEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_wolfEvent[key].second))(event);
		break;
	}
}

std::shared_ptr<arc::IShape> arc::WolfGame::start()
{
	float largRay = 1.0f / NB_RAY;
	for (size_t i = 0; i < NB_RAY; i++) {
		float angle = atanf(((float)i - NB_RAY / 2.0f) / NB_RAY);
		_ray.push_back(std::MKS<arc::wolf::Ray>(angle, i, largRay));
	}
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	return all;
}

std::shared_ptr<arc::IShape> arc::WolfGame::update(arc::EventHandler &event)
{
	execKey(event);
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	for (auto &ray : _ray) {
		ray->castMath(_player.getPos(), _player.getAngle(), _mapMgr.getMap());
		all->addChild(ray->draw(all));
	}
	return all;
}

void arc::WolfGame::_moveUp(arc::EventHandler &event[[maybe_unused]])
{
	if (_player.canMove(_mapMgr.getMap(), SPEED))
		_player.move(SPEED);
}

void arc::WolfGame::_moveDown(arc::EventHandler &event[[maybe_unused]])
{
	if (_player.canMove(_mapMgr.getMap(), -SPEED))
		_player.move(-SPEED);
}

void arc::WolfGame::_moveLeft(arc::EventHandler &event[[maybe_unused]])
{
	_player.rotate(-SPEED);
}

void arc::WolfGame::_moveRight(arc::EventHandler &event[[maybe_unused]])
{
	_player.rotate(SPEED);
}
