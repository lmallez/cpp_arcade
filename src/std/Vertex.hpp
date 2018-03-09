//
// EPITECH PROJECT, 2018
// cpp_arcade - Vertex.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_VERTEX_HPP
#define CPP_ARCADE_VERTEX_HPP

#include <iostream>

namespace arc
{
	template <class T>
	class Vertex
	{
	public:
		Vertex<T>();
		Vertex<T>(const Vertex<T> &);
		Vertex<T>(T x, T y);
		~Vertex<T>() = default;

		T x() const;
		T y() const;
		T &rx();
		T &ry();
		template <typename U>
		Vertex &operator=(const Vertex<U> &);
		template <typename U>
		Vertex operator+(const Vertex<U> &) const;
		template <typename U>
		Vertex operator-(const Vertex<U> &) const;
		template <typename U>
		Vertex operator*(const Vertex<U> &) const;
		template <typename U>
		Vertex operator/(const Vertex<U> &) const;
		template <typename U>
		Vertex operator+(U) const;
		template <typename U>
		Vertex operator-(U) const;
		template <typename U>
		Vertex operator*(U) const;
		template <typename U>
		Vertex operator/(U) const;

	private:
		T _x;
		T _y;
	};

	typedef Vertex<size_t> VertexS;
	typedef Vertex<int> VertexI;
	typedef Vertex<float> VertexF;
	typedef Vertex<double> VertexD;
}

#endif //CPP_ARCADE_VERTEX_HPP
