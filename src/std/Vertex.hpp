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

		T getX() const;
		T getY() const;
		T &getrX();
		T &getrY();
		Vertex &operator=(const Vertex &);
		Vertex operator+(const Vertex &) const;
		Vertex operator-(const Vertex &) const;
		Vertex operator*(const Vertex &) const;
		Vertex operator/(const Vertex &) const;
		Vertex operator+(T) const;
		Vertex operator-(T) const;
		Vertex operator*(T) const;
		Vertex operator/(T) const;

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
