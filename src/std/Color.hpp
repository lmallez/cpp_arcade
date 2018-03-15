//
// EPITECH PROJECT, 2018
// cpp_arcade - Color.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_COLOR_HPP
#define CPP_ARCADE_COLOR_HPP

#include <iostream>

namespace arc {

	union uintVal {
		uint64_t _all;
		uint8_t _part[4];
	};

	class Color
	{
	public:
		Color(uint8_t  = 0, uint8_t  = 0, uint8_t = 0, uint8_t = 255);
		Color(const Color &);
		Color(uint64_t);
		uint8_t red() const;
		uint8_t green() const;
		uint8_t blue() const;
		uint8_t alpha() const;
		uint64_t values() const;
	private:
		uintVal _color;
	};
}


#endif //CPP_ARCADE_COLOR_HPP
