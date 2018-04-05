//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SolarFoxGame.cpp
//

#include "SolarFoxGame.hpp"

arc::IGame &arc::SolarFoxGame::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new SolarFoxGame();
	return *instance;
}

void arc::SolarFoxGame::freeInstance()
{
}

arc::SolarFoxGame::SolarFoxGame():
	_clock(0.02),
	_ship({1, 1}, {0.05, 0.05}, 5)
{
}

void arc::SolarFoxGame::assignKey(arc::KeyEvent::Key key,
	arc::KeyEvent::Status status, arc::SolarFoxGame::SolarFoxEvt_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_solarForEvent.insert(a);
}

void arc::SolarFoxGame::execKey(arc::EventHandler &event)
{
	SystemController::execKey(event);
	_ship.execKey(event);
	for (auto a : _solarForEvent)
		execKey(event, a.first);
}

void arc::SolarFoxGame::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	switch (_solarForEvent[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	}
}

std::shared_ptr <arc::IShape> arc::SolarFoxGame::start()
{
	srandom(time(nullptr));
	_isOver = false;
	_monster.push_back(solarfox::Monster(UP, {0.1, 0.05}));
	_monster.push_back(solarfox::Monster(LEFT, {0.1, 0.05}));
	_monster.push_back(solarfox::Monster(DOWN, {0.1, 0.05}));
	_monster.push_back(solarfox::Monster(RIGHT, {0.1, 0.05}));
	return std::make_shared<arc::ShapeContainer>();
}

std::shared_ptr <arc::IShape> arc::SolarFoxGame::update(EventHandler &event)
{
	return _isOver ? _gameOver(event) : _game(event);
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_game(arc::EventHandler &event)
{
	execKey(event);
	if (_clock.updateTime()) {
		for (auto &monster : _monster) {
			monster.move(0.01);
			if (random() % 1000 < SHOT_PROBA)
				_missile.push_back(monster.shot());
		}
		for (size_t i = 0; i < _missile.size(); i++) {
			if (!_missile[i]->move(0.01)) {
				_missile.erase(_missile.begin() + i);
				i--;
			} else if (_missile[i]->collision(_ship.getPos())) {
				_isOver = _ship.moveLife(-1);
				_missile.erase(_missile.begin() + i);
				i--;
			}
		}
	}
	return _drawGame();
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_gameOver(
	arc::EventHandler &event)
{
	arc::SystemController::execKey(event);
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.4, 0.2, 0.4), "Game Over"));
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.6, 0.1, 0.4), "Score: 0"));
	return all;
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_drawGame() const
{
	std::shared_ptr map = std::make_shared<arc::ShapeRect>(nullptr, arc::Texture(arc::Color::Red), arc::RectF(0.1, 0.1, 0.8, 0.8));

	map->addChild(_ship.drawShip(map));
	for (auto &monster : _monster)
		map->addChild(monster.draw(map));
	for (auto &missile : _missile)
		map->addChild(missile->draw(map));
	map->addChild(_ship.drawLife(map, arc::RectF(0, 1.05, 0.5, 0.07)));
	return map;
}