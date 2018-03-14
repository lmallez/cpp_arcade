//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Rect.cpp
//

#include <zconf.h>
#include "Rect.hpp"

template <typename T>
arc::Rect<T>::Rect(const Rect<T> &rect):
	_pos(rect.pos()), _size(rect.size())
{
}

template <typename T>
arc::Rect<T>::Rect(const Vertex <T> &pos, const Vertex <T> &size):
	_pos(pos), _size(size)
{
}

template <typename T>
arc::Rect<T>::Rect(T x, T y, T w, T h):
	_pos(arc::Vertex<T>(x, y)), _size(arc::Vertex<T>(w, h))
{
}

template <typename T>
arc::Vertex<T> arc::Rect<T>::pos() const
{
	return _pos;
}

template <typename T>
arc::Vertex <T> arc::Rect<T>::size() const
{
	return _size;
}

template <typename T>
arc::Vertex <T> &arc::Rect<T>::rpos()
{
	return _pos;
}

template <typename T>
arc::Vertex <T> &arc::Rect<T>::rsize()
{
	return _size;
}

template <typename T>
arc::Rect<T> &arc::Rect<T>::operator=(const arc::Rect<T> &other)
{
	this->_pos = other.pos();
	this->_size = other.size();
	return *this;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator*(const arc::Rect<T> &other) const
{
	arc::Rect<T> res(*this);

	res._pos = res._pos * other.pos();
	res._size = res._size * other.size();
	return res;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator*(const arc::Vertex<T> &other) const
{
	arc::Rect res(*this);

	res._pos = res._pos * other;
	res._size = res._size * other;
	return res;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator/(const arc::Vertex<T> &other) const
{
	arc::Rect res(*this);

	res._pos = res._pos + other / res._size;
	res._size = res._size / other;
	return res;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator*(T other) const
{
	arc::Rect res(*this);

	res._pos = res._pos;
	res._size = res._size * other;
	return res;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator/(T other) const
{
	arc::Rect res(*this);

	res._pos = res._pos;
	res._size = res._size / other;
	return res;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator+(const arc::Vertex<T> &other) const
{
	arc::Rect res(*this);

	res._pos = res._pos + other;
	res._size = res._size;
	return res;}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator-(const arc::Vertex<T> &other) const
{
	arc::Rect res(*this);

	res._pos = res._pos - other;
	res._size = res._size;
	return res;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator+(T other) const
{
	arc::Rect res(*this);

	res._pos = res._pos + other;
	res._size = res._size;
	return res;
}

template <typename T>
arc::Rect<T> arc::Rect<T>::operator-(T other) const
{
	arc::Rect res(*this);

	res._pos = res._pos - other;
	res._size = res._size;
	return res;
}

template class arc::Rect<size_t>;
template class arc::Rect<int>;
template class arc::Rect<float>;
template class arc::Rect<double>;