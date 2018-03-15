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
		explicit Color(uint8_t = 0, uint8_t = 0, uint8_t = 0,
			uint8_t = 255);
		explicit Color(uint64_t);
		Color(const Color &);
		uint8_t red() const;
		uint8_t green() const;
		uint8_t blue() const;
		uint8_t alpha() const;
		uint64_t values() const;

		static const Color Black;
		static const Color White;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Yellow;
		static const Color Magenta;
		static const Color Cyan;
		static const Color Transparent;
	private:
		uintVal _color;
	};
}


#endif //CPP_ARCADE_COLOR_HPP
