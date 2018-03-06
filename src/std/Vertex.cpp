//
// EPITECH PROJECT, 2018
// cpp_arcade - Vertex.cpp
// File description:
// Created by Faudil Puttilli
//

#include "Vertex.hpp"

template class arc::Vertex<int>;
template class arc::Vertex<size_t>;
template class arc::Vertex<float>;
template class arc::Vertex<double>;

template <typename T>
arc::Vertex<T>::Vertex() :
_x(0),
_y(0)
{}

template <typename T>
arc::Vertex<T>::Vertex(T x, T y) :
_x(x),
_y(y)
{}

template <typename T>
arc::Vertex<T>::Vertex(const Vertex &cpy) :
_x(cpy.getX()),
_y(cpy.getY())
{}

template <typename T>
T arc::Vertex<T>::getX() const
{
	return _x;
}

template <typename T>
T arc::Vertex<T>::getY() const
{
	return _y;
}

template <typename T>
T &arc::Vertex<T>::getrX()
{
	return _x;
}

template <typename T>
T &arc::Vertex<T>::getrY()
{
	return _y;
}

template <typename T>
arc::Vertex<T>& arc::Vertex<T>::operator=(const Vertex<T> &other)
{
	this->_x = other.getX();
	this->_y = other.getY();
	return *this;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator+(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x += other.getX();
	res._y += other.getY();
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator-(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x -= other.getX();
	res._y -= other.getY();
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator/(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x /= other.getX();
	res._y /= other.getY();
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator*(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x *= other.getX();
	res._y *= other.getY();
	return res;
}