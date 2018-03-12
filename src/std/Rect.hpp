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

		template <typename U>
		Rect &operator=(const Rect<U> &other);

		template <typename U>
		Rect &operator*(const Rect<U> &other) const;

		template <typename U>
		Rect operator+(const Vertex<U> &other) const;
		template <typename U>
		Rect operator-(const Vertex<U> &other) const;
		template <typename U>
		Rect operator*(const Vertex<U> &other) const;
		template <typename U>
		Rect operator/(const Vertex<U> &other) const;

		template <typename U>
		Rect operator+(U other) const;
		template <typename U>
		Rect operator-(U other) const;
		template <typename U>
		Rect operator*(U other) const;
		template <typename U>
		Rect operator/(U other) const;


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