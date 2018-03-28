//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Menu.cpp
//

#include <src/std/DirectoryReader.hpp>
#include <src/graphic/shape/ShapeContainer.hpp>
#include "MainMenu.hpp"

std::unique_ptr<arc::IGame> &arc::MainMenu::getInstance()
{
	static std::unique_ptr<arc::IGame> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new MainMenu());
	return instance;
}


void arc::MainMenu::assignKey(arc::KeyEvent::Key key, void (arc::MainMenu::*func)(arc::EventHandler &))
{
	_keyEvent.insert(std::make_pair(key, func));
}

void arc::MainMenu::execKey(arc::EventHandler &event)
{
	for (auto key : _keyEvent) {
		execKey(event, key.first);
	}
}

void arc::MainMenu::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	if (event.keyEvent().isKeyPressed(key))
		(this->*(_keyEvent[key]))(event);
}

std::shared_ptr<arc::IShape> arc::MainMenu::start()
{
	assignKey(arc::KeyEvent::LEFT, &arc::MainMenu::_moveCol);
	assignKey(arc::KeyEvent::RIGHT, &arc::MainMenu::_moveCol);
	assignKey(arc::KeyEvent::UP, &arc::MainMenu::_moveLineUp);
	assignKey(arc::KeyEvent::DOWN, &arc::MainMenu::_moveLineDown);
	assignKey(arc::KeyEvent::A, &arc::MainMenu::_selectWord);
	_initListGame();
	_initListGraphic();
	return std::shared_ptr<arc::IShape>();
}

std::shared_ptr<arc::IShape> arc::MainMenu::update(arc::EventHandler &event)
{
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	execKey(event);
	all->addChild(_displayListGraphic(arc::RectF(0, 0.4, 0.5, 0.5)));
	all->addChild(_displayListGame(arc::RectF(0.5, 0.4, 0.5, 0.5)));
	return all;
}

std::shared_ptr<arc::IShape> arc::MainMenu::_displayListGraphic(const arc::RectF &pos)
{
	std::shared_ptr m = std::make_shared<arc::ShapeRect>(nullptr,
		arc::Texture(arc::Color::Red), pos);
	size_t text = 0;

	for (std::string fileName : _listGraphic) {
		arc::Texture aled(text != _selectGraphic ? arc::Color::White : arc::Color::Green, _userPos.x() == 0 && _userPos.y() == text ? arc::Color::White : arc::Color::Transparent);
		std::shared_ptr file = std::make_shared<arc::ShapeText>(m, aled, RectF(0.1, (text + TEXT_PADDING / 2) * TEXT_PADDING, 0.9, 0.2), fileName);
		m->addChild(file);
		text++;
	}
	return m;
}

std::shared_ptr<arc::IShape> arc::MainMenu::_displayListGame(const arc::RectF &pos)
{
	std::shared_ptr m = std::make_shared<arc::ShapeRect>(nullptr,
		arc::Texture(arc::Color::Green), pos);
	size_t text = 0;

	for (std::string fileName : _listGame) {
		if (_userPos.y() < (int)(1 / (text * TEXT_PADDING))) {
			arc::Texture aled(text != _selectGame ? arc::Color::White : arc::Color::Green, _userPos.x() == 1 && _userPos.y() == text ? arc::Color::White : arc::Color::Transparent);
			std::shared_ptr file = std::make_shared<arc::ShapeText>(
				m, aled, RectF(0.1,
					(text + TEXT_PADDING / 2) * TEXT_PADDING,
					0.9, 0.2), fileName);
			m->addChild(file);
		}
		text++;
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

void arc::MainMenu::_moveCol(arc::EventHandler &event)
{
	_userPos.rx() = (_userPos.x() == 0) ? 1 : 0;
	_userPos.ry() = 0;
}

void arc::MainMenu::_moveLineUp(arc::EventHandler &event)
{
	if (_userPos.y() > 0)
		_userPos.ry()--;
}

void arc::MainMenu::_moveLineDown(arc::EventHandler &event)
{
	if ((_userPos.x() == 0 && _userPos.y() < _listGraphic.size())
		|| (_userPos.x() == 1 && _userPos.y() < _listGame.size()))
		_userPos.ry()++;
}

void arc::MainMenu::_selectWord(arc::EventHandler &event)
{
	if (_userPos.x() == 0) {
		std::cout << "aled a" << std::endl;
		_selectGame = _userPos.y();
	} else if (_userPos.x() == 1) {
		std::cout << "aled b" << std::endl;
		_selectGraphic = _userPos.y();
	}
}