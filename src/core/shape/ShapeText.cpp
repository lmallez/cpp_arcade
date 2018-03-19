//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeText.cpp
// File description:
// Created by Faudil Puttilli
//

#include "ShapeText.hpp"

arc::ShapeText::ShapeText(const arc::Vertex<float> &pos,const
	arc::Vertex<float> &size, const std::string &txt)
: 	_type("text"), _pos(pos), _size(size), _text(txt)
{
}

arc::ShapeText::ShapeText(const arc::ShapeText &cpy) :
	_type("text"), _pos(cpy.getPos()), _text(cpy.getText())
{
}

arc::Vertex<float> arc::ShapeText::getPos() const
{
	return _pos;
}

std::string arc::ShapeText::getText() const
{
	return _text;
}

std::unique_ptr<arc::IDraw> arc::ShapeText::convert(
	std::unique_ptr<IShapeLoader> &)
{
	return nullptr;
}

std::unique_ptr<arc::IShape> arc::ShapeText::clone() const
{
	return std::make_unique<arc::ShapeText>(*this);
}

arc::Vertex<float> arc::ShapeText::getSize() const
{
	return _size;
}
