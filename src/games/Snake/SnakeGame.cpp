//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SnakeGame.cpp
//

#include <src/graphic/shape/ShapeContainer.hpp>
#include <variant>
#include "SnakeGame.hpp"

arc::IGame & arc::SnakeGame::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new SnakeGame();
	return *instance;
}

void arc::SnakeGame::freeInstance()
{
}

void arc::SnakeGame::assignKey(arc::KeyEvent::Key key, arc::KeyEvent::Status status, arc::SnakeGame::SnakeGame_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_snakeEvent.insert(a);
}

void arc::SnakeGame::execKey(arc::EventHandler &event)
{
	PlayerController::execKey(event);
	SystemController::execKey(event);
	for (auto key : _snakeEvent) {
		execKey(event, key.first);
	}
}

void arc::SnakeGame::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	switch (_snakeEvent[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_snakeEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_snakeEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_snakeEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_snakeEvent[key].second))(event);
		break;
	}
}

std::shared_ptr<arc::IShape> arc::SnakeGame::start()
{
	return _drawSnake();
}

std::shared_ptr<arc::IShape> arc::SnakeGame::update(arc::EventHandler &event)
{
	execKey(event);
	if (_clock.updateTime()) {
		_move(event);
	}
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();
	all->addChild(_drawSnake());
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0, 0.1, 0.4), "Score: " + std::to_string(_score)));
	return all;
}

arc::SnakeGame::SnakeGame():
	PlayerController({0, 0}, arc::KeyEvent::JUSTPRESSED, {0, 0}, {true, arc::RectF(0, 0, MAP_SIZE, MAP_SIZE)}),
	_map(arc::RectF(0.1, 0.1, 0.8, 0.8)),
	_snake(arc::VertexS(0, 0)),
	_clock(0.1)
{
	srandom(time(nullptr));
	_genFlower();
}

std::shared_ptr<arc::IShape> arc::SnakeGame::_drawSnake() const
{
	arc::Texture texture = Texture(arc::Color::Red);
	std::shared_ptr s = std::make_shared<arc::ShapeRect>(nullptr, texture, _map);
	auto body = _snake.getBody();
	arc::VertexF partSize(_map.size().x() / MAP_SIZE, _map.size().y() / MAP_SIZE);
	texture = Texture(arc::Color::Blue, arc::Color::Blue);

	for (const arc::VertexS &bodyPart : body) {
		arc::RectF size({bodyPart.x() * partSize.x(), bodyPart.y() * partSize.y()}, partSize);
		s->addChild(std::make_shared<arc::ShapeRect>(s, texture, size));
	}
	const arc::VertexS &bodyPart = _snake.getHead();
	RectF size(bodyPart.x() * partSize.x(), bodyPart.y() * partSize.y(), partSize.x(), partSize.y());
	s->addChild(std::make_shared<arc::ShapeRect>(s, texture, size));
	RectF flowerSize(_flowerPos.x() * partSize.x(), _flowerPos.y() * partSize.y(), partSize.x(), partSize.y());
	s->addChild(std::make_shared<arc::ShapeCircle>(s, texture, flowerSize));
	return s;
}

bool arc::SnakeGame::_eatFlower()
{
	if (_pCtrlPos.x() == _flowerPos.x() && _pCtrlPos.y() == _flowerPos.y()) {
		_genFlower();
		_score += 1;
		return true;
	}
	return false;
}

void arc::SnakeGame::_genFlower()
{
	do {
		_flowerPos.rx() = (size_t)(random() % MAP_SIZE);
		_flowerPos.ry() = (size_t)(random() % MAP_SIZE);
	} while (!_snake.inSnake(_flowerPos));
}

void arc::SnakeGame::_move(arc::EventHandler &event)
{
	_moveDir(event, {false, NONE}, {true, {1, 1}});
	if (_pCtrlHaveMove) {
		if (!_snake.move({(size_t)_pCtrlPos.x(), (size_t)_pCtrlPos.y()}, _eatFlower()))
			_score -= 2;
	} else
		_score -= 1;
	_clock.updateTime();
}
