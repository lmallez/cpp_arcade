//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeCircle.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_ShapeCircle_HPP
#define CPP_ARCADE_ShapeCircle_HPP

#include <src/std/Rect.hpp>
#include "IShape.hpp"

namespace arc
{

	class ShapeCircle : public virtual arc::IShape
	{
	public:
		ShapeCircle(const arc::Vertex<float> & = {0, 0}, const float =
		0);
		ShapeCircle(const arc::ShapeCircle &);
		std::unique_ptr<IDraw>
		convert(std::unique_ptr<IShapeLoader> &) override;
		std::unique_ptr<arc::IShape> clone() override;
		std::unique_ptr<IShape> getChild(size_t id) override;
		std::unique_ptr<IShape> operator[](size_t id) override;
		arc::Vertex<float> getOrigin() const;
		float getRadius() const;
		void setOrigin(const arc::Vertex<float> &);
		void setRadius(const float);
	private:
		arc::Vertex<float> _origin;
		float _radius;
	};

}

#endif //CPP_ARCADE_ShapeCircle_HPP
