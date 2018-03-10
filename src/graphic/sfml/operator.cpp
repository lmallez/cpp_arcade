//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// operatorz.cpp
//

#include "operator.hpp"

template <typename T>
sf::Vector2<T> operator=(const arc::Vertex<T> &ex) const {
	return sf::Vector2(ex.x(), ex.y());
}

template <typename T>
arc::Vertex<T> operator=(const sf::Vector2<T> &ex) const {
	return arc::Vertex(ex.x, ex.y);
}

template <typename T>
arc::Rect<T> operator=(const sf::Rect<T> &ex) const {
	return arc::Rect(ex.top, ex.left, ex.width, ex.left);
}

template <typename T>
sf::Rect<T> operator=(const arc::Rect<T> &ex) const {
	return sf::Rect(ex.pos().x(), ex.pos().y,
		ex.size().x(), ex.size().y());
}