//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLDrawText.cpp
//

#include "SDLShapeText.hpp"

arc::SDLShapeText::SDLShapeText(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect,
	const std::string &text):
	ShapeText(parent, texture, rect, text), SDLShape()
{
}

arc::SDLShapeText::SDLShapeText(const arc::ShapeText &shape):
	ShapeText(shape), SDLShape()
{
}

void arc::SDLShapeText::draw() const
{
	arc::RectF geo = winGeometry();
	gfxPrimitivesSetFont(nullptr, 42, 42);
	stringColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
		    (Sint16) geo.pos().x(), (Sint16) geo.pos().y(),
		getText().c_str(), _texture.bgColor().values());
}
