/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaShapeText.hpp"

arc::CacaShapeText::CacaShapeText(std::SPTR<arc::IShape> parent,
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
	arc::Texture texture = getTexture();

	if (len == 0)
		return;
	setColor(texture.lineColor(), texture.bgColor());
	caca_printf(arc::CacaMainWindow::getInstance().getCanvas().get(),
		    geo.pos().x(), geo.pos().y(), "%SPTR", text.c_str());
	AShape::draw();
}
