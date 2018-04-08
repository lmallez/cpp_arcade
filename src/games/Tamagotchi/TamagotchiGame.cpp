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
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	return all;
}

std::shared_ptr <arc::IShape> arc::TamagotchiGame::update(EventHandler &event)
{
	execKey(event);
	std::SPTR all = std::MKS<arc::ShapeContainer>();
	all->addChild(_tamago.draw(all, arc::RectF(0, 0, 0.5, 0.5)));
	arc::RectF buttonPos(0.6, 0.4, 0.3, 0.2);
	all->addChild(_drawButton(all, buttonPos));
	std::cout << event.mouseEvent().getPos().x() << " " <<  event.mouseEvent().getPos().y() << std::endl;
	if (buttonPos.isInside(event.mouseEvent().getPos()))
		_size++;
	return all;
}

arc::TamagotchiGame::TamagotchiGame():
	_tamago(arc::Texture(), arc::AnimatedTexture({}, arc::RectF(), 1))
{
	arc::AnimatedTexture body = arc::AnimatedTexture({
		arc::Texture(TAMAGO_ASSETS_DIR + "/body1.png"),
		arc::Texture(TAMAGO_ASSETS_DIR + "/body2.png"),
		arc::Texture(TAMAGO_ASSETS_DIR + "/body3.png")
	}, arc::RectF(0, 0.5, 1, 0.5), 0.5);
	_tamago.setBody(body);
	_tamago.setHead(arc::Texture(TAMAGO_ASSETS_DIR + "/old_ramage.png"));
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
		pos, "MANGER " + std::to_string(_size)));
	return all;
}
