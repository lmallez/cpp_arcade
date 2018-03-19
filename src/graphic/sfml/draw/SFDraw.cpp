//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.cpp
//

#include <SFML/Graphics/Shape.hpp>
#include "SFDraw.hpp"

arc::SFDraw::SFDraw(std::shared_ptr<IDraw> parent, const Texture &texture,
	const RectF &geometry) :
	ADraw(parent, texture, geometry)
{
}

arc::SFDraw::SFDraw(const arc::ADraw &ex):
	ADraw(ex.getParent(), ex.getTexture(), ex.getGeometry())
{
}

arc::RectF arc::SFDraw::winPos() const
{
	RectF pos;
	RectF parentPos;

	if (!_parent) {
		pos = _geometry * arc::SFGraphic::initialize()->getSize();
	} else {
		parentPos = _parent->winPos();
		pos.rpos() = parentPos.pos() +
			_geometry.pos() * parentPos.size();
		pos.rsize() = _geometry.size() * parentPos.size();
	}
	return pos;
}

sf::FloatRect arc::SFDraw::_winGeometry() const
{
	arc::RectF pos = winPos();
	sf::FloatRect geometry(pos.pos().x(), pos.pos().y(),
		pos.size().x(), pos.size().y());

	return geometry;
}

void arc::SFDraw::_displayItem(const sf::Drawable &item) const
{
	SFGraphic::initialize()->draw(item);
}

void arc::SFDraw::_colorItem(sf::Shape &item) const
{
	arc::Color fill = _texture.bgColor();
	arc::Color line = _texture.lineColor();

	item.setFillColor(sf::Color(fill.red(), fill.green(),
		fill.blue(), fill.alpha()));
	item.setOutlineColor(sf::Color(line.red(), line.green(),
		line.blue(), line.alpha()));
}
