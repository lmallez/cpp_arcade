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

arc::SnakeGame::SnakeGame():
	_map(arc::RectF(0.1, 0.1, 0.8, 0.8)),
	_snake(arc::VertexS(MAP_SIZE, MAP_SIZE)),
	_clock(0.1),
	_score(0)
{
	assignKey(arc::KeyEvent::SPACE, arc::KeyEvent::JUSTPRESSED, &arc::SnakeGame::_move);
	srandom(time(nullptr));
	_genFlower();
}

void arc::SnakeGame::assignKey(arc::KeyEvent::Key key, arc::KeyEvent::Status status, arc::SnakeGame::SnakeEvt_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_snakeEvent.insert(a);
}

void arc::SnakeGame::execKey(arc::EventHandler &event)
{
	_snake.execKey(event);
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
	_score = 0;
	_isOver = false;
	return _drawSnake();
}

std::shared_ptr<arc::IShape> arc::SnakeGame::update(arc::EventHandler &event)
{
	return _isOver ? _gameOver(event) : _game(event);
}

std::shared_ptr<arc::IShape> arc::SnakeGame::_gameOver(EventHandler &event)
{
	arc::SystemController::execKey(event);
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.4, 0.2, 0.4), "Game Over"));
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.6, 0.1, 0.4), "Score: " + std::to_string(_score)));
	return all;
}

std::shared_ptr<arc::IShape> arc::SnakeGame::_game(EventHandler &event)
{
	execKey(event);
	if (_clock.updateTime()) {
		_move(event);
		if (_specialFlower.second != 0)
			_specialFlower.second--;
		else if (random() % 100 <= SPECIAL_FLOWER_RATE)
			_genSpecialFlower();
	}
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();
	all->addChild(_drawSnake());
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0, 0.1, 0.4), "Score: " + std::to_string(_score)));
	return all;
}

std::shared_ptr<arc::IShape> arc::SnakeGame::_drawSnake() const
{
	arc::Texture texture = Texture(arc::Color::Red);
	std::shared_ptr s = std::make_shared<arc::ShapeRect>(nullptr, texture, _map);
	auto body = _snake.getBody();
	arc::VertexF partSize(1.0 / (MAP_SIZE + 1), 1.0 / (MAP_SIZE + 1));
	texture = Texture(arc::Color::Blue, arc::Color::Blue);

	for (const arc::VertexS &bodyPart : body) {
		arc::RectF size({bodyPart.x() * partSize.x(), bodyPart.y() * partSize.y()}, partSize);
		s->addChild(std::make_shared<arc::ShapeRect>(s, texture, size));
	}
	const arc::VertexS &bodyPart = _snake.getHead();
	RectF size(bodyPart.x() * partSize.x(), bodyPart.y() * partSize.y(), partSize.x(), partSize.y());
	s->addChild(std::make_shared<arc::ShapeRect>(s, arc::Texture(arc::Color::Blue, arc::Color::Cyan), size));
	RectF flowerSize(_flowerPos.x() * partSize.x(), _flowerPos.y() * partSize.y(), partSize.x(), partSize.y());
	s->addChild(std::make_shared<arc::ShapeCircle>(s, texture, flowerSize));
	if (_specialFlower.second > 0) {
		RectF flowerSpecialSize(_specialFlower.first.x() * partSize.x(), _specialFlower.first.y() * partSize.y(), partSize.x(), partSize.y());
		s->addChild(std::make_shared<arc::ShapeCircle>(s, arc::Texture(arc::Color::Yellow, arc::Color::Yellow), flowerSpecialSize));
	}
	return s;
}

void arc::SnakeGame::_genFlower()
{
	do {
		_flowerPos.rx() = (size_t)(random() % MAP_SIZE);
		_flowerPos.ry() = (size_t)(random() % MAP_SIZE);
	} while (_snake.inSnake(_flowerPos));
}

void arc::SnakeGame::_genSpecialFlower()
{
	do {
		_specialFlower.first.rx() = (size_t)(random() % MAP_SIZE);
		_specialFlower.first.ry() = (size_t)(random() % MAP_SIZE);
	} while (_snake.inSnake(_specialFlower.first));
	_specialFlower.second = SPECIAL_FLOWER_DURATION;
}

void arc::SnakeGame::_move(arc::EventHandler &event, arc::snake::Snake &snake)
{
	if (!snake.move(event))
		_isOver = true;
	else if (snake.eatFlower(_flowerPos, 1))
		_genFlower();
	else if (snake.eatFlower(_specialFlower.first, 3))
		_genSpecialFlower();
	else
		snake.deleteTail();
	_score = snake.getScore();
}

void arc::SnakeGame::_move(arc::EventHandler &event)
{
	_move(event, _snake);
	_clock.updateTime();
}
