//
// EPITECH PROJECT, 2018
// cpp_arcade - Vertex.cpp
// File description:
// Created by Faudil Puttilli
//

#include "Vertex.hpp"
#include "Rect.hpp"

template <typename T>
arc::Vertex<T>::Vertex() :
	_x(0), _y(0)
{
}

template <typename T>
arc::Vertex<T>::Vertex(T x, T y) :
	_x(x), _y(y)
{
}

template <typename T>
arc::Vertex<T>::Vertex(const Vertex &cpy) :
	_x(cpy.x()), _y(cpy.y())
{
}

template <typename T>
T arc::Vertex<T>::x() const
{
	return _x;
}

template <typename T>
T arc::Vertex<T>::y() const
{
	return _y;
}

template <typename T>
T &arc::Vertex<T>::rx()
{
	return _x;
}

template <typename T>
T &arc::Vertex<T>::ry()
{
	return _y;
}

template <typename T>
arc::Vertex<T>& arc::Vertex<T>::operator=(const Vertex<T> &other)
{
	this->_x = other.x();
	this->_y = other.y();
	return *this;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator+(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x += other.x();
	res._y += other.y();
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator-(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x -= other.x();
	res._y -= other.y();
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator/(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x /= other.x();
	res._y /= other.y();
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator*(const Vertex<T> &other) const
{
	arc::Vertex res(*this);

	res._x *= other.x();
	res._y *= other.y();
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator+(T other) const
{
	arc::Vertex res(*this);

	res._x += other;
	res._y += other;
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator-(T other) const
{
	arc::Vertex res(*this);

	res._x -= other;
	res._y -= other;
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator*(T other) const
{
	arc::Vertex res(*this);

	res._x *= other;
	res._y *= other;
	return res;
}

template <typename T>
arc::Vertex<T> arc::Vertex<T>::operator/(T other) const
{
	arc::Vertex res(*this);

	res._x /= other;
	res._y /= other;
	return res;
}

template class arc::Vertex<int>;
template class arc::Vertex<size_t>;
template class arc::Vertex<float>;
template class arc::Vertex<double>;