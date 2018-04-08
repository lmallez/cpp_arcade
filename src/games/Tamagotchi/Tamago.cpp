//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Tamago.cpp
//

#include "src/graphic/shape/ShapeContainer.hpp"
#include "Tamago.hpp"
arc::tamago::Tamago::Tamago(const arc::Texture &texture, const AnimatedTexture &body):
	_head(texture), _body(body)
{
}

std::shared_ptr<arc::IShape>
arc::tamago::Tamago::draw(const std::shared_ptr<arc::IShape> &parent,
	const RectF &pos)
{
	std::SPTR tamago = std::MKS<arc::ShapeRect>(parent, arc::Texture(arc::Color::Red, arc::Color::Yellow), pos);

	_body.update();
	tamago->addChild(std::MKS<arc::ShapeRect>(parent, _head, arc::RectF(0.25, 0, 0.5, 0.5)));
	tamago->addChild(_body.draw(tamago));
	return tamago;
}

void arc::tamago::Tamago::setHead(const arc::Texture &head)
{
	_head = head;
}

void arc::tamago::Tamago::setBody(const arc::AnimatedTexture &_body)
{
	Tamago::_body = _body;
}
