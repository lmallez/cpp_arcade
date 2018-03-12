//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeLoader.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_SHAPELOADER_HPP
#define CPP_ARCADE_SHAPELOADER_HPP

#include <algorithm>
#include <unordered_map>
#include "IShape.hpp"
#include "ShapeCircle.hpp"
#include "ShapeRect.hpp"
#include "ShapeText.hpp"


namespace arc
{
	class ShapeLoader
	{
	public:
		ShapeLoader &getInstance();
		std::unique_ptr<IShape> loadShape(const std::string &);
	private:
		ShapeLoader();
		std::unordered_map<std::string,
			std::unique_ptr<arc::IShape>> _inst;
	};

}

#endif //CPP_ARCADE_SHAPELOADER_HPP
