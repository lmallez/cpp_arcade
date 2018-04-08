//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLDrawText.cpp
//

#include "SDLShapeText.hpp"

arc::SDLShapeText::SDLShapeText(std::SPTR<arc::IShape> parent,
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
	SDL_Rect geo = winGeometry();
	gfxPrimitivesSetFont(nullptr, 42, 42);
	boxColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
		 geo.x, geo.y, geo.w + geo.x, geo.h + geo.y, _texture.bgColor()
			 .values());
	stringColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
		    (Sint16) geo.x, (Sint16) geo.y,
		getText().c_str(), _texture.lineColor().values());
	AShape::draw();
}
