//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Menu.cpp
//

#include <src/std/DirectoryReader.hpp>
#include <src/graphic/shape/ShapeContainer.hpp>
#include "src/exception/Exception.hpp"
#include "MainMenu.hpp"

std::unique_ptr<arc::IGame> &arc::MainMenu::getInstance()
{
	static std::unique_ptr<arc::IGame> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new MainMenu());
	return instance;
}

std::shared_ptr<arc::IShape> arc::MainMenu::start()
{
	_initListGame();
	_initListGraphic();
	return std::shared_ptr<arc::IShape>();
}

std::shared_ptr<arc::IShape> arc::MainMenu::update(arc::EventHandler &event)
{
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	all->addChild(_displayListGraphic(arc::RectF(0, 0, 0.5, 0.5)));
	all->addChild(_displayListGame(arc::RectF(0.5, 0, 0.5, 0.5)));
	return all;
}

std::shared_ptr<arc::IShape> arc::MainMenu::_displayListGraphic(const arc::RectF &pos)
{
	std::shared_ptr m = std::make_shared<arc::ShapeRect>(nullptr,
		arc::Texture(arc::Color::Red), pos);
	float text = 0.1;

	for (std::string fileName : _listGraphic) {
		std::shared_ptr file = std::make_shared<arc::ShapeText>(m,
			Texture(arc::Color::White), RectF(0.1, text, 0.9, 0.2), fileName);
		m->addChild(file);
		text += 0.2;
	}
	return m;
}

std::shared_ptr<arc::IShape> arc::MainMenu::_displayListGame(const arc::RectF &pos)
{
	std::shared_ptr m = std::make_shared<arc::ShapeRect>(nullptr,
		arc::Texture(arc::Color::Green), pos);
	float text = 0.1;

	for (std::string fileName : _listGame) {
		std::shared_ptr file = std::make_shared<arc::ShapeText>(m,
			Texture(arc::Color::White), RectF(0.1, text, 0.9, 0.2), fileName);
		m->addChild(file);
		text += 0.2;
	}
	return m;
}

std::vector<std::string> arc::MainMenu::_initListGraphic()
{
	_listGraphic.clear();
	_listGraphic = arc::DirectoryReader(DIR_GAME).fileName();
	return _listGraphic;
}

std::vector<std::string> arc::MainMenu::_initListGame()
{
	_listGame.clear();
	_listGame = arc::DirectoryReader(DIR_GRAPHIC).fileName();
	return _listGame;
}
