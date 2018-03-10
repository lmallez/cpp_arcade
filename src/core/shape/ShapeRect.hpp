//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeRect.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_SHAPERECT_HPP
#define CPP_ARCADE_SHAPERECT_HPP

#include <src/std/Rect.hpp>
#include "AShape.hpp"

namespace arc
{

	class ShapeRect : public virtual arc::AShape
	{
	public:
		ShapeRect();
		explicit ShapeRect(const arc::Rect<float> &);
		ShapeRect(const arc::ShapeRect &);
		std::unique_ptr<IDraw>
		convert(std::unique_ptr<IShapeLoader> &) override;
		std::unique_ptr<arc::IShape> clone() const override;
		arc::Rect<float> getGeometry() const;
		void setGeometry(const arc::Rect<float> &);
	private:
		arc::Rect<float> _geometry;
	};

}

#endif //CPP_ARCADE_SHAPERECT_HPP
