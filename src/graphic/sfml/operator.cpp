//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// operatorz.cpp
//

#include "operator.hpp"

template <typename T>
sf::Vector2<T> operator~(const arc::Vertex<T> &ex)
{
	return sf::Vector2<T>(ex.x(), ex.y());
}

template <typename T>
arc::Vertex<T> operator~(const sf::Vector2<T> &ex)
{
	return arc::Vertex<T>(ex.x, ex.y);
}

template <typename T>
arc::Rect<T> operator~(const sf::Rect<T> &ex)
{
	return arc::Rect<T>(ex.top, ex.left, ex.width, ex.left);
}

template <typename T>
sf::Rect<T> operator~(const arc::Rect<T> &ex)
{
	return sf::Rect<T>(ex.pos().x(), ex.pos().y,
		ex.size().x(), ex.size().y());
}
