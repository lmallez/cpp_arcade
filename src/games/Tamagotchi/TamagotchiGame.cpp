//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// TamagotchiGame.cpp
//

#include "src/graphic/shape/ShapeContainer.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "TamagotchiGame.hpp"

arc::IGame &arc::TamagotchiGame::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new TamagotchiGame();
	return *instance;
}


std::shared_ptr <arc::IShape> arc::TamagotchiGame::start()
{
	_tamago.feelInLove();
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	return all;
}

std::shared_ptr <arc::IShape> arc::TamagotchiGame::update(EventHandler &event)
{
	execKey(event);
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	arc::Rect tamagoPos = arc::RectF(0.1, 0.4, 0.5, 0.5);
	all->addChild(_tamago.draw(all, tamagoPos));
	if (tamagoPos.isInside(event.mouseEvent().getPos()))
		_love++;
	else
		_love = 0;
	_tamago.setSpeed(_love * 0.0001 < 1 ? 1 - _love * 0.0001 : 0);
	if (_love > 0 && _love % 1000 == 0)
		_tamago.feelInLove();
	_tamago.dance();
	arc::RectF buttonPos(0.6, 0.4, 0.3, 0.2);
	all->addChild(_drawButton(all, buttonPos));
	if (buttonPos.isInside(event.mouseEvent().getPos()))
		_size++;
	if (!_hasGrowth && _size > 10)
		_tamago.setHead(arc::Texture(TAMAGO_ASSETS_DIR + "/old_ramage.png"));
	return all;
}

arc::TamagotchiGame::TamagotchiGame():
	_tamago(arc::Texture(), arc::AnimatedTexture({}, arc::RectF(), 1))
{
	srandom(time(nullptr));
	arc::AnimatedTexture body = arc::AnimatedTexture({
		arc::Texture(TAMAGO_ASSETS_DIR + "/body1.png"),
		arc::Texture(TAMAGO_ASSETS_DIR + "/body2.png"),
		arc::Texture(TAMAGO_ASSETS_DIR + "/body3.png"),
		arc::Texture(TAMAGO_ASSETS_DIR + "/body2.png")
	}, arc::RectF(0, 0.5, 1, 0.5), 0.1);
	_tamago.setBody(body);
	_tamago.setHead(arc::Texture(TAMAGO_ASSETS_DIR + "/young_ramage.png"));
}

std::shared_ptr<arc::IShape>
arc::TamagotchiGame::_drawButton(const std::shared_ptr<arc::IShape> &parent,
	const arc::RectF &pos) const
{
	std::SPTR all = std::MKS<arc::ShapeContainer>(parent);

	all->addChild(std::MKS<arc::ShapeRect>(all,
		arc::Texture(arc::Color::Red, arc::Color::Red),
		pos));
	all->addChild(std::MKS<arc::ShapeText>(all,
		arc::Texture(arc::Color::Blue),
		pos, "MANGER " + std::to_string(_size) + std::to_string(_love)));
	return all;
}
