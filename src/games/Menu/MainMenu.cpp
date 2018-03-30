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

arc::MainMenu::MainMenu():
	SystemGame()
{
	assignKey(arc::KeyEvent::RETURN, arc::KeyEvent::JUSTPRESSED, &arc::MainMenu::_pressedStart);
	assignKey(arc::KeyEvent::LEFT, arc::KeyEvent::JUSTPRESSED, &arc::MainMenu::_moveCol);
	assignKey(arc::KeyEvent::RIGHT, arc::KeyEvent::JUSTPRESSED, &arc::MainMenu::_moveCol);
	assignKey(arc::KeyEvent::UP, arc::KeyEvent::JUSTPRESSED, &arc::MainMenu::_moveUp);
	assignKey(arc::KeyEvent::DOWN, arc::KeyEvent::JUSTPRESSED, &arc::MainMenu::_moveDown);

	_startButton = std::make_shared<arc::ShapeRect>(nullptr, arc::Texture(), arc::RectF(0.1, 0.85, 0.8, 0.1));
	auto a = std::make_shared<arc::ShapeText>(_startButton, arc::Texture(arc::Color::Red), arc::RectF(0.4, 0.4, 0.2, 0.2), "START");
	_startButton->addChild(a);
}

void arc::MainMenu::assignKey(arc::KeyEvent::Key key, arc::KeyEvent::Status status, MainMenuEvent_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_keyEvent.insert(a);
}

void arc::MainMenu::execKey(arc::EventHandler &event)
{
	arc::SystemGame::execKey(event);
	for (auto key : _keyEvent) {
		arc::MainMenu::execKey(event, key.first);
	}
}

void arc::MainMenu::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	switch (_keyEvent[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	}
}

std::shared_ptr<arc::IShape> arc::MainMenu::start()
{
	return std::shared_ptr<arc::IShape>();
}

std::shared_ptr<arc::IShape> arc::MainMenu::update(arc::EventHandler &event)
{
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	auto title = std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::Cyan), arc::RectF(0.1, 0.1, 0.8, 0.3), "Arcade // fodil loui tngi pd");
	execKey(event);
	all->addChild(_displayListGraphic(event, arc::RectF(0.05, 0.3, 0.4, 0.5)));
	all->addChild(_displayListGame(event, arc::RectF(0.55, 0.3, 0.4, 0.5)));
	all->addChild(_displayStartButton(event));
	all->addChild(title);
	return all;
}

std::shared_ptr<arc::IShape> arc::MainMenu::_displayStartButton(EventHandler &event)
{
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(), event.gameEvent().getListGames().size());

	arc::Texture texture(arc::Color::Red, _userPos.y() >= maxLine ? arc::Color::White : arc::Color::Magenta);
	_startButton->setTexture(texture);
	return _startButton;
}

arc::Texture
arc::MainMenu::_getListTexture(size_t pos, size_t selected, size_t col)
{
	return arc::Texture (
		selected == pos ? arc::Color::Yellow : arc::Color::White,
		_userPos.x() == col && _userPos.y() == pos ? arc::Color::White : arc::Color::Transparent
	);
}

std::shared_ptr<arc::IShape> arc::MainMenu::_displayListGraphic(EventHandler &event, const arc::RectF &pos)
{
	std::shared_ptr m = std::make_shared<arc::ShapeRect>(nullptr, arc::Texture(arc::Color::Red), pos);
	size_t text = 0;
	std::vector<std::string> list = event.gameEvent().getListGraphics();

	for (std::string fileName : list) {
		arc::Texture texture = _getListTexture(text, event.gameEvent().getPosGraphic(), 0);
		auto file = std::make_shared<arc::ShapeText>(m, texture, RectF(0.1, (float)(text * 0.2 + 0.1), 0.8, 0.2), fileName);
		m->addChild(file);
		text++;
	}
	return m;
}

std::shared_ptr<arc::IShape> arc::MainMenu::_displayListGame(EventHandler &event, const arc::RectF &pos)
{
	std::shared_ptr m = std::make_shared<arc::ShapeRect>(nullptr, arc::Texture(arc::Color::Green), pos);
	size_t text = 0;
	std::vector<std::string> list = event.gameEvent().getListGames();

	for (std::string fileName : list) {
		arc::Texture texture = _getListTexture(text, event.gameEvent().getPosGame(), 1);
		auto file = std::make_shared<arc::ShapeText>(m, texture, RectF(0.1, (float)(text * 0.2 + 0.1), 0.8, 0.2), fileName);
		m->addChild(file);
		text++;
	}
	return m;
}

void arc::MainMenu::_pressedStart(arc::EventHandler &event)
{
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(), event.gameEvent().getListGames().size());

	if (_userPos.y() >= maxLine)
		event.gameEvent().setMenu(false);
	else {
		if (_userPos.x() == 0 && _userPos.y() < event.gameEvent().getListGraphics().size()) {
			event.gameEvent().setGraphic(_userPos.y());
		} else if (_userPos.x() == 1 && _userPos.y() < event.gameEvent().getListGames().size()) {
			event.gameEvent().setGame(_userPos.y());
		}
	}
}

void arc::MainMenu::_moveCol(arc::EventHandler &event[[maybe_unused]])
{
	_userPos.rx() = (_userPos.x() == 0) ? 1 : 0;
}

void arc::MainMenu::_moveUp(arc::EventHandler &event[[maybe_unused]])
{
	if (_userPos.ry() > 0)
		_userPos.ry()--;
}

void arc::MainMenu::_moveDown(arc::EventHandler &event)
{
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(), event.gameEvent().getListGames().size());

	if (_userPos.ry() < maxLine + 1)
		_userPos.ry()++;
}
