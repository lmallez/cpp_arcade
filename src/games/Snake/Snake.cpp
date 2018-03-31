//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Snake.cpp
//

#include <src/std/Vertex.hpp>
#include "Snake.hpp"

arc::snake::Snake::Snake(const VertexS &pos)
{
	_head = pos;
}

bool arc::snake::Snake::move(const VertexS &head, bool increase)
{
	if (!inSnake(head))
		return false;
	_body.push_back(_head);
	if (!increase)
		_body.erase(_body.begin());
	_head = head;
	return true;
}

const std::vector<arc::VertexS> &arc::snake::Snake::getBody() const
{
	return _body;
}

const arc::VertexS &arc::snake::Snake::getHead() const
{
	return _head;
}

bool arc::snake::Snake::inSnake(const arc::VertexS &head) const
{
	for (const arc::VertexS &a : _body) {
		if (a.x() == head.x() && a.y() == head.y())
			return false;
	}
	return true;
}
