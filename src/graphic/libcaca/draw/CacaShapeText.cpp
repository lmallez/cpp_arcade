/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaShapeText.hpp"

arc::CacaShapeText::CacaShapeText(std::shared_ptr<arc::IShape> parent,
	const arc::Texture &texture, const arc::RectF &rect,
	const std::string &text):
	ShapeText(parent, texture, rect, text), CacaShape()
{
}

arc::CacaShapeText::CacaShapeText(const arc::ShapeText &shape):
	ShapeText(shape), CacaShape()
{
}

void arc::CacaShapeText::draw() const
{
	arc::RectF geo = winGeometry();
	std::string text = getText();
	size_t len = text.length();

	if (len == 0)
		return;
	caca_printf(arc::CacaMainWindow::getInstance().getCanvas().get(),
		    geo.pos().x(), geo.pos().y(), "%s\n", text.c_str());
	AShape::draw();
}
