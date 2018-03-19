//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeCircle.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_ShapeCircle_HPP
#define CPP_ARCADE_ShapeCircle_HPP

#include "AShape.hpp"
#include "src/std/Rect.hpp"

namespace arc
{

	class ShapeCircle : public virtual arc::AShape
	{
	public:
		ShapeCircle(const arc::Vertex<float> & = {0, 0}, float =
		0);
		ShapeCircle(const arc::ShapeCircle &);
		std::unique_ptr<arc::IShape> clone() const override;
		arc::Vertex<float> getOrigin() const;
		float getRadius() const;
		void setOrigin(const arc::Vertex<float> &);
		void setRadius(float);
	private:
		arc::Vertex<float> _origin;
		float _radius;
	};

}

#endif //CPP_ARCADE_ShapeCircle_HPP
