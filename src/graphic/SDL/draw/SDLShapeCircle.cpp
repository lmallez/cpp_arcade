//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShapeCircle.cpp
//

#include <src/graphic/SDL/SDLMainWindow.hpp>
#include "SDLShapeCircle.hpp"

arc::SDLShapeCircle::SDLShapeCircle(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::VertexF &pos, float radius):
	ShapeCircle(parent, texture, pos, radius)
{

}

arc::SDLShapeCircle::SDLShapeCircle(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect):
	ShapeCircle(parent, texture, rect)
{
}

arc::SDLShapeCircle::SDLShapeCircle(const arc::ShapeCircle &shape):
	ShapeCircle(shape)
{
}

void arc::SDLShapeCircle::draw() const
{
	arc::RectF geo = winGeometry();

	aaellipseColor(arc::SDLMainWindow::getInstance().getRenderer().get(),
		       (Sint16) geo.pos().x(), (Sint16) geo.pos().y(),
		       (Sint16) geo.size().x(), (Sint16) geo.size().y(),
		       _texture.bgColor().values());
}