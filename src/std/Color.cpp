//
// EPITECH PROJECT, 2018
// cpp_arcade - Color.cpp
// File description:
// Created by Faudil Puttilli
//

#include "Color.hpp"

const arc::Color arc::Color::Black(0, 0, 0);
const arc::Color arc::Color::White(255, 255, 255);
const arc::Color arc::Color::Red(255, 0, 0);
const arc::Color arc::Color::Green(0, 255, 0);
const arc::Color arc::Color::Blue(0, 0, 255);
const arc::Color arc::Color::Yellow(255, 255, 0);
const arc::Color arc::Color::Magenta(255, 0, 255);
const arc::Color arc::Color::Cyan(0, 255, 255);
const arc::Color arc::Color::Transparent(0, 0, 0, 0);

arc::Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_color._part[0] = red;
	_color._part[1] = green;
	_color._part[2] = blue;
	_color._part[3] = alpha;
}

arc::Color::Color(const arc::Color &cpy)
{
	_color._all = cpy.values();
}

arc::Color::Color(uint64_t values)
{
	_color._all = values;
}

uint8_t arc::Color::r() const
{
	return _color._part[0];
}

uint8_t arc::Color::g() const
{
	return _color._part[1];
}

uint8_t arc::Color::b() const
{
	return _color._part[2];
}

uint8_t arc::Color::a() const
{
	return _color._part[3];
}

uint64_t arc::Color::values() const
{
	return _color._all;
}