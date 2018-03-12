//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// operatorz.cpp
//

#include "operator.hpp"

template <typename T>
sf::Vector2<T> &operator~(const arc::Vertex<T> &ex)
{
	sf::Vector2<T> item(ex.x(), ex.y());
	return item;
}

template <typename T>
arc::Vertex<T> &operator~(const sf::Vector2<T> &ex)
{
	arc::Vertex<T> item(ex.x, ex.y);
	return item;
}

template <typename T>
sf::Rect<T> &operator~(const arc::Rect<T> &ex)
{
	sf::Rect<T> item(ex.pos().x(), ex.pos().y(),
		ex.size().x(), ex.size().y());
	return item;
}

template <typename T>
arc::Rect<T> &operator~(const sf::Rect<T> &ex)
{
	arc::Rect<T> item(ex.top, ex.left, ex.width, ex.height);
	return item;
}