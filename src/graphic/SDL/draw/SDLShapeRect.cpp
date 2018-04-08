//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShapeRect.cpp
//

#include "SDLShapeRect.hpp"

arc::SDLShapeRect::SDLShapeRect(std::SPTR<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect) :
	ShapeRect(parent, texture, rect), SDLShape()
{
}

arc::SDLShapeRect::SDLShapeRect(const arc::ShapeRect &shape):
	ShapeRect(shape), SDLShape()
{
}

void arc::SDLShapeRect::draw() const
{
	SDL_Rect geo = winGeometry();
	SDLMainWindow &mainWin = arc::SDLMainWindow::getInstance();
	Sint16 x, y, sx, sy;
	x = (Sint16) geo.x;
	y = (Sint16) geo.y;
	sx = (Sint16) geo.w;
	sy = (Sint16) geo.h;
	rectangleColor(mainWin.getRenderer().get(),
		       x, y, sx + x, sy + y,
		       _texture.lineColor().values());
	if (_texture.getFilePath().empty()) {
		boxColor(mainWin.getRenderer().get(),
			 x, y, sx + x, sy + y, _texture.bgColor().values());
	} else {
		SDL_Texture *texture = SDLShape::getTexture(
			_texture.getFilePath());
		SDL_RenderCopy(mainWin.getRenderer().get(), texture, nullptr,
			       &geo);
	}
	AShape::draw();
}