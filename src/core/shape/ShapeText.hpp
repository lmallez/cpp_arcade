//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeText.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_SHAPETEXT_HPP
#define CPP_ARCADE_SHAPETEXT_HPP

#include "AShape.hpp"

namespace arc
{

	class ShapeText : public virtual arc::AShape
	{
	public:
		ShapeText(const arc::Vertex<float> & = {0, 0},
			  const std::string & = "");
		ShapeText(const arc::ShapeText &);
		std::unique_ptr<IDraw>
		convert(std::unique_ptr<IShapeLoader> &) override;
		std::unique_ptr<arc::IShape> clone() const override;
		arc::Vertex<float> getPos() const;
		std::string getText() const;
	private:
		arc::Vertex<float> _pos;
		std::string _text;
	};

}

#endif //CPP_ARCADE_SHAPETEXT_HPP
