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
	_ship({1, 1}, {0.05, 0.05}, 10),
	_mapManager("../assets/solarfox"),
	_scoreboard("solarfox")
{
	assignKey(arc::KeyEvent::SPACE, arc::KeyEvent::JUSTPRESSED, &arc::SolarFoxGame::_shot);
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
	_object = _mapManager.initMap(0);
	_score = 0;
	_scoreboard.initScores();
	return std::make_shared<arc::ShapeContainer>();
}

std::shared_ptr <arc::IShape> arc::SolarFoxGame::update(EventHandler &event)
{
	return _isOver ? _gameOver(event) : _game(event);
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_game(arc::EventHandler &event)
{
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	execKey(event);
	if (_clock.updateTime()) {
		for (auto &monster : _monster) {
			monster.move(0.01);
			if (random() % 1000 < SHOT_PROBA)
				_monsterShot.push_back(monster.shot());
		}
		_monsterMissileMove();
		_playerMissileMove();
		if (_object.empty()) {
			_isOver = _mapManager.lastLvl();
			if (!_isOver)
				_object = _mapManager.nextMap();
		}
	}
	all->addChild(_drawGame());
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.1, 0, 0.1, 0.4), "Score: " + std::to_string(_score)));
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.5, 0, 0.1, 0.4), ("HightScore: " + std::to_string(_scoreboard.getHightScore().second)) + " " + _scoreboard.getHightScore().first));
	if (_isOver)
		_scoreboard.addScore(event.gameEvent().playerName(), (int)_score);
	return all;
}

void arc::SolarFoxGame::_monsterMissileMove()
{
	for (size_t i = 0; i < _monsterShot.size(); i++) {
		if (!_monsterShot[i]->move(0.01)) {
			deleteMissile(_monsterShot, i);
			i--;
		} else if (_monsterShot[i]->collision(_ship.getPos())) {
			_isOver = _ship.moveLife(-1);
			deleteMissile(_monsterShot, i);
			i--;
		}
	}
}

void arc::SolarFoxGame::_playerMissileMove()
{
	for (size_t i = 0; i < _playerShot.size(); i++) {
		if (!_playerShot[i] || !_playerShot[i]->move(0.01)) {
			deleteMissile(_playerShot, i);
			i--;
		} else if (_checkObject(_playerShot[i])) {
			deleteMissile(_playerShot, i);
			i--;
		}
	}
}

bool arc::SolarFoxGame::_checkObject(const std::shared_ptr<arc::solarfox::AMissile> &shot)
{
	for (size_t i = 0; i < _object.size(); i++)
		if (_object[i]->collision(shot->getPos())) {
			if (_object[i]->getHealth() <= 0) {
				deleteMissile(_object, i);
				_score += 1;
				return true;
			}
		}
	return false;
}

template <typename T>
void arc::SolarFoxGame::deleteMissile(
	std::vector<std::shared_ptr<T>> &vec, size_t id)
{
	if (id > vec.size())
		throw arc::Exception("SolarFox", "Invalid Missile");
	vec[id].reset();
	vec.erase(vec.begin() + id);
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_gameOver(
	arc::EventHandler &event)
{
	arc::SystemController::execKey(event);
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.4, 0.2, 0.4), "Game Over"));
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.6, 0.1, 0.4), "Score: " + std::to_string(_score)));
	return all;
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_drawGame() const
{
	std::shared_ptr map = std::make_shared<arc::ShapeRect>(nullptr, arc::Texture(arc::Color::Red), arc::RectF(0.1, 0.1, 0.8, 0.8));

	for (auto &monster : _monster)
		map->addChild(monster.draw(map));
	for (auto &missile : _monsterShot)
		map->addChild(missile->draw(map));
	for (auto &missile : _playerShot)
		map->addChild(missile->draw(map));
	for (auto &obj : _object)
		map->addChild(obj->draw(map));
	map->addChild(_ship.drawShip(map));
	map->addChild(_ship.drawLife(map, arc::RectF(0, 1.05, 0.5, 0.07)));
	return map;
}

void arc::SolarFoxGame::_shot(arc::EventHandler &event[[maybe_unused]])
{
	_playerShot.push_back(_ship.shot());
}
