//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Tamago.cpp
//

#include "src/graphic/shape/ShapeContainer.hpp"
#include "Tamago.hpp"
#include "TamagotchiGame.hpp"

arc::tamago::Tamago::Tamago(const arc::Texture &texture, const AnimatedTexture &body):
	_head(texture), _body(body)
{
	_loveText = arc::Texture(TAMAGO_ASSETS_DIR + "/love.png");
}

std::shared_ptr<arc::IShape>
arc::tamago::Tamago::draw(const std::shared_ptr<arc::IShape> &parent,
	const RectF &pos)
{
	std::SPTR tamago = std::MKS<arc::ShapeContainer>(parent, pos);

	moveHeart();
	tamago->addChild(_body.draw(tamago));
	for (auto &heart : _love) {
		tamago->addChild(std::MKS<arc::ShapeRect>(tamago, _loveText, arc::RectF(heart, {0.2, 0.2})));
	}
	tamago->addChild(std::MKS<arc::ShapeRect>(tamago, _head, arc::RectF(0.2, 0.05, 0.7, 0.7)));
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

void arc::tamago::Tamago::moveHeart()
{
	for (size_t i = 0; i < _love.size(); i++) {
		_love[i].ry() -= 0.0001;
		if (_love[i].ry() < -0.5f && random() % 3 > 1) {
			_love.erase(_love.begin() + i);
			i--;
		}
	}
}

void arc::tamago::Tamago::feelInLove()
{
	arc::VertexF newHeart;

	newHeart.rx() = (float)(random() % 100) / 100.0f;
	newHeart.ry() = 0.2;
	_love.push_back(newHeart);
}

void arc::tamago::Tamago::dance()
{
	_body.update();
}

void arc::tamago::Tamago::setSpeed(float speed)
{
	_body.setSpeed(speed);
}
