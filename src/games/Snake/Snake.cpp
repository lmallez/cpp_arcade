//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Snake.cpp
//

#include <src/std/Vertex.hpp>
#include <src/exception/Exception.hpp>
#include "Snake.hpp"

arc::snake::Snake::Snake(const VertexS &mapSize):
	PlayerController({0, 0}, arc::KeyEvent::JUSTPRESSED, false, {0, 0}, {true, arc::RectF(0, 0, mapSize.x(), mapSize.y())}),
	_score(0),
	_head(mapSize / 2)
{
	_pCtrlDir = RIGHT;
	_pCtrlPos = {(float)_head.x(), (float)_head.y()};
	for (size_t i = START_SIZE; i > 0; i--) {
		_body.push_back(arc::VertexS(_head.x() - i, _head.y()));
	}
}

bool arc::snake::Snake::moveHead(const arc::VertexS &head)
{
	if (inSnake(head))
		return false;
	_body.push_back(_head);
	_head = head;
	return true;
}

void arc::snake::Snake::execKey(EventHandler &event)
{
	PlayerController::execKey(event);
}

void arc::snake::Snake::deleteTail()
{
	if (_pCtrlHaveMove) {
		if (_body.size() == 0)
			throw arc::Exception("snake", "Snake size is 0");
		_body.erase(_body.begin());
	}
}


const std::vector<arc::VertexS> &arc::snake::Snake::getBody() const
{
	return _body;
}

const arc::VertexS &arc::snake::Snake::getHead() const
{
	return _head;
}

bool arc::snake::Snake::inSnake(const arc::VertexS &pos) const
{
	for (const arc::VertexS &a : _body) {
		if (a.x() == pos.x() && a.y() == pos.y())
			return true;
	}
	return false;
}

bool arc::snake::Snake::move(arc::EventHandler &event)
{
	_moveDir(event, {false, NONE}, {true, {1, 1}});
	if (!moveHead({(size_t)_pCtrlPos.x(), (size_t)_pCtrlPos.y()}))
		return false;
	return (_pCtrlHaveMove || _pCtrlDir == NONE);
}

bool arc::snake::Snake::eatFlower(const arc::VertexS &flowerPos)
{
	if (_pCtrlPos.x() == flowerPos.x() && _pCtrlPos.y() == flowerPos.y()) {
		_score += 1;
		return true;
	}
	return false;
}

size_t arc::snake::Snake::getScore() const
{
	return _score;
}
