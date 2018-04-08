//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShapeCircle.cpp
//

#include <src/graphic/SDL/SDLMainWindow.hpp>
#include "SDLShapeCircle.hpp"

arc::SDLShapeCircle::SDLShapeCircle(std::SPTR<arc::IShape> parent,
	const arc::Texture &texture, const arc::VertexF &pos, float radius):
	ShapeCircle(parent, texture, pos, radius), SDLShape()
{
}

arc::SDLShapeCircle::SDLShapeCircle(std::SPTR<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect):
	ShapeCircle(parent, texture, rect), SDLShape()
{
}

arc::SDLShapeCircle::SDLShapeCircle(const arc::ShapeCircle &shape):
	ShapeCircle(shape), SDLShape()
{
}

void arc::SDLShapeCircle::draw() const
{
	SDLMainWindow &mainWin = arc::SDLMainWindow::getInstance();
	SDL_Rect geo = winGeometry();
	geo.x = geo.x + geo.w / 2;
	geo.y = geo.y + geo.h / 2;
	geo.w = geo.w / 2;
	geo.h = geo.h / 2;
	aaellipseColor(mainWin.getRenderer().get(),
		       geo.x, geo.y, geo.w, geo.h,
		       _texture.lineColor().values());
	if (_texture.getFilePath().empty()) {
		filledEllipseColor(mainWin.getRenderer().get(),
				   geo.x, geo.y, geo.w, geo.h,
				   _texture.bgColor().values());
	} else {
		SDL_Texture *texture = SDLShape::getTexture(
			_texture.getFilePath());
		geo.w *= 2;
		geo.h *= 2;
		geo.x -= geo.w / 2;
		geo.y -= geo.h / 2;
		SDL_RenderCopy(mainWin.getRenderer().get(), texture, nullptr,
			       &geo);
	}
	AShape::draw();
}
