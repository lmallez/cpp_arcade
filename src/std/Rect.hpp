//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Rect.hpp
//

#ifndef CPP_ARCADE_RECT_HPP
#define CPP_ARCADE_RECT_HPP

#include "Vertex.hpp"

namespace arc {
	template <typename T>
	class Rect {
	public:
		Rect<T>(const Rect <T> &rect);
		Rect<T>(const Vertex <T> &pos, const Vertex <T> &size);
		explicit Rect<T>(T x = 0, T y = 0, T w = 0, T h = 0);
		~Rect<T>() = default;

		Vertex<T> pos() const;
		Vertex<T> size() const;
		Vertex<T> &rpos();
		Vertex<T> &rsize();

		Rect<T> &operator=(const Rect<T> &other);

		Rect<T> operator*(const Rect<T> &other) const;

		Rect<T> operator+(const Vertex<T> &other) const;
		Rect<T> operator-(const Vertex<T> &other) const;
		Rect<T> operator*(const Vertex<T> &other) const;
		Rect<T> operator/(const Vertex<T> &other) const;

		Rect<T> operator+(T other) const;
		Rect<T> operator-(T other) const;
		Rect<T> operator*(T other) const;
		Rect<T> operator/(T other) const;

		Vertex<T> topLeft() const;
		Vertex<T> topRight() const;
		Vertex<T> botLeft() const;
		Vertex<T> botRight() const;

		bool isInside(const Vertex <T> &other) const;
		bool isInside(const Rect <T> &other) const;
		bool isCollide(const Rect <T> &other) const;

	private:
		Vertex<T> _pos;
		Vertex<T> _size;
	};

	typedef Rect<int> RectI;
	typedef Rect<float> RectF;
	typedef Rect<double> RectD;
	typedef Rect<size_t> RectS;
}

#endif /* CPP_ARCADE_RECT_HPP */