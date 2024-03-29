//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeText.cpp
//

#include "ShapeText.hpp"

arc::ShapeText::ShapeText(const std::SPTR<arc::IShape> &parent,
	const arc::Texture &texture, arc::RectF geometry,
	const std::string &text):
	AShape(parent, texture, geometry), _text(text)
{
}

arc::ShapeText::ShapeText(const arc::ShapeText &ex):
	AShape(ex), _text(ex.getText())
{
}

void arc::ShapeText::setText(const std::string &text)
{
	_text = text;
}

const std::string &arc::ShapeText::getText() const
{
	return _text;
}

std::UPTR<arc::IShape>
arc::ShapeText::convert(const arc::IShapeLoader &loader) const
{
	return loader.load(*this);
}
