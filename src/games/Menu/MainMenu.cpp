//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Menu.cpp
//

#include "src/std/DirectoryReader.hpp"
#include "src/graphic/shape/ShapeContainer.hpp"
#include "src/games/utils/ScoreHandler.hpp"
#include "MainMenu.hpp"

std::unordered_map<arc::KeyEvent::Key, char> arc::MainMenu::_nameKeyMap = {
	{arc::KeyEvent::A, 'A'},
	{arc::KeyEvent::B, 'B'},
	{arc::KeyEvent::C, 'C'},
	{arc::KeyEvent::D, 'D'},
	{arc::KeyEvent::E, 'E'},
	{arc::KeyEvent::F, 'F'},
	{arc::KeyEvent::G, 'G'},
	{arc::KeyEvent::H, 'H'},
	{arc::KeyEvent::I, 'I'},
	{arc::KeyEvent::J, 'J'},
	{arc::KeyEvent::K, 'K'},
	{arc::KeyEvent::L, 'L'},
	{arc::KeyEvent::M, 'M'},
	{arc::KeyEvent::N, 'N'},
	{arc::KeyEvent::O, 'O'},
	{arc::KeyEvent::P, 'P'},
	{arc::KeyEvent::Q, 'Q'},
	{arc::KeyEvent::R, 'R'},
	{arc::KeyEvent::S, 'S'},
	{arc::KeyEvent::T, 'T'},
	{arc::KeyEvent::U, 'U'},
	{arc::KeyEvent::V, 'V'},
	{arc::KeyEvent::W, 'W'},
	{arc::KeyEvent::X, 'X'},
	{arc::KeyEvent::Y, 'Y'},
	{arc::KeyEvent::Z, 'Z'},
	{arc::KeyEvent::NUM1, '1'},
	{arc::KeyEvent::NUM2, '2'},
	{arc::KeyEvent::NUM3, '3'},
	{arc::KeyEvent::NUM4, '4'},
	{arc::KeyEvent::NUM5, '5'},
	{arc::KeyEvent::NUM6, '6'},
	{arc::KeyEvent::NUM7, '7'},
	{arc::KeyEvent::NUM8, '8'},
	{arc::KeyEvent::NUM9, '9'},
	{arc::KeyEvent::NUM0, '0'},
	{arc::KeyEvent::SPACE, ' '}
};

arc::IGame &arc::MainMenu::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new MainMenu();
	return *instance;
}

arc::MainMenu::MainMenu():
	SystemController()
{
	assignKey(arc::KeyEvent::RETURN, arc::KeyEvent::JUSTPRESSED,
			&arc::MainMenu::_pressedStart);
	assignKey(arc::KeyEvent::LEFT, arc::KeyEvent::JUSTPRESSED,
			&arc::MainMenu::_moveCol);
	assignKey(arc::KeyEvent::RIGHT, arc::KeyEvent::JUSTPRESSED,
			&arc::MainMenu::_moveCol);
	assignKey(arc::KeyEvent::UP, arc::KeyEvent::JUSTPRESSED,
			&arc::MainMenu::_moveUp);
	assignKey(arc::KeyEvent::DOWN, arc::KeyEvent::JUSTPRESSED,
			&arc::MainMenu::_moveDown);

	_nameButton = std::MKS<arc::ShapeRect>(nullptr, arc::Texture(),
					arc::RectF(0.1, 0.75, 0.8, 0.05));
	auto b = std::MKS<arc::ShapeText>(_nameButton, arc::Texture(arc::Color::Red),
					arc::RectF(0.1, 0.1, 0.8, 0.8), _name);
	_nameButton->addChild(b);
	_startButton = std::MKS<arc::ShapeRect>(nullptr, arc::Texture(),
					arc::RectF(0.1, 0.85, 0.8, 0.1));
	auto a = std::MKS<arc::ShapeText>(_startButton, arc::Texture(arc::Color::Red),
				arc::RectF(0.1, 0.1, 0.8, 0.8), "START");
	_startButton->addChild(a);
}

void arc::MainMenu::assignKey(arc::KeyEvent::Key key,
			arc::KeyEvent::Status status,
			MainMenuEvent_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_keyEvent.insert(a);
}

void arc::MainMenu::execKey(arc::EventHandler &event)
{
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(),
				event.gameEvent().getListGames().size() + 1);
	arc::SystemController::execKey(event);
	if (_userPos.y() == maxLine - 1) {
		for (auto key : _nameKeyMap) {
			if (event.keyEvent().isKeyjustPressed(key.first))
				_name += key.second;
		}
	}
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

std::SPTR<arc::IShape> arc::MainMenu::start()
{
	return std::SPTR<arc::IShape>();
}

std::SPTR<arc::IShape> arc::MainMenu::update(arc::EventHandler &event)
{
	std::SPTR all = std::MKS<arc::ShapeContainer>();

	auto title = std::MKS<arc::ShapeText>(nullptr,
					arc::Texture(arc::Color::Cyan),
					arc::RectF(0.1, 0.1, 0.8, 0.3),
					"Arcade // fodil loui tngi");
	execKey(event);
	all->addChild(_displayListGraphic(event,
					arc::RectF(0.05, 0.2, 0.4, 0.5)));
	all->addChild(_displayListGame(event,
					arc::RectF(0.55, 0.2, 0.4, 0.5)));
	all->addChild(_displayNameButton(event));
	all->addChild(_displayStartButton(event));
	all->addChild(title);
	return all;
}

std::SPTR<arc::IShape> arc::MainMenu::_displayStartButton(EventHandler &event)
{
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(),
				event.gameEvent().getListGames().size() + 1);

	arc::Texture texture(arc::Color::Red, _userPos.y() >= maxLine ? arc::Color::White : arc::Color::Cyan);
	_startButton->setTexture(texture);
	return _startButton;
}

std::SPTR<arc::IShape> arc::MainMenu::_displayNameButton(EventHandler &event)
{
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(),
				event.gameEvent().getListGames().size() + 1);

	arc::Texture texture(arc::Color::Red, _userPos.y() == maxLine - 1 ? arc::Color::White : arc::Color::Cyan);
	_nameButton->setTexture(texture);
	_nameButton->getChild(0).setText(_name);
	event.gameEvent().setPlayerName(_name);
	return _nameButton;
}

arc::Texture
arc::MainMenu::_getListTexture(size_t pos, size_t selected, size_t col)
{
	return arc::Texture (
		selected == pos ? arc::Color::Green : arc::Color::Red,
		_userPos.x() == col && _userPos.y() == pos ? arc::Color::White : arc::Color::Transparent
	);
}

std::SPTR<arc::IShape> arc::MainMenu::_displayListGraphic(EventHandler &event,
							const arc::RectF &pos)
{
	std::SPTR m = std::MKS<arc::ShapeRect>(nullptr,
					arc::Texture(arc::Color::Red), pos);
	size_t text = 0;
	std::vector<std::string> list = event.gameEvent().getListGraphics();

	for (std::string fileName : list) {
		arc::Texture texture = _getListTexture(text,
						event.gameEvent().getPosGraphic(),
						0);
		auto file = std::MKS<arc::ShapeText>(m, texture,
						RectF(0.05, (float)(text * 0.1 + 0.05), 0.9, 0.11),
						fileName);
		m->addChild(file);
		text++;
	}
	return m;
}

std::SPTR<arc::IShape> arc::MainMenu::_displayListGame(EventHandler &event,
						const arc::RectF &pos)
{
	std::SPTR m = std::MKS<arc::ShapeRect>(nullptr, arc::Texture(arc::Color::Green), pos);
	size_t text = 0;
	std::vector<std::string> list = event.gameEvent().getListGames();

	for (std::string fileName : list) {
		arc::Texture texture = _getListTexture(text, event.gameEvent().getPosGame(), 1);
		auto file = std::MKS<arc::ShapeText>(m, texture, RectF(0.05, (float)(text * 0.20 + 0.05), 0.9, 0.10), fileName);
		m->addChild(file);
		auto scores = std::MKS<arc::ShapeText>(m, texture, RectF(0.05, (float)(text * 0.20 + 0.12), 0.9, 0.05),
						"Best scores:");
		m->addChild(scores);
		ScoreHandler SPTR;
		SPTR.setGame(SPTR.getLinkedLib(fileName));
		std::vector<std::pair<std::string, int>> sc;
		try {
			SPTR.initScores();
			sc = SPTR.getScores();
		} catch (arc::Exception e) {}
		if (sc.size() < 3) {
			sc.push_back(std::pair<std::string, int>("None", 0));
			sc.push_back(std::pair<std::string, int>("None", 0));
			sc.push_back(std::pair<std::string, int>("None", 0));
		}
		auto scores2 = std::MKS<arc::ShapeText>(m, texture, RectF(0.05, (float)(text * 0.20 + 0.17), 0.9, 0.10),
						sc[0].first + " " + std::to_string(sc[0].second) + "  " +
						sc[1].first + " " + std::to_string(sc[1].second) + "  " +
						sc[2].first + " " + std::to_string(sc[2].second));
		m->addChild(scores2);
		text++;
	}
	return m;
}

void arc::MainMenu::_pressedStart(arc::EventHandler &event)
{
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(),
				event.gameEvent().getListGames().size() + 1);

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
	size_t maxLine = std::max(event.gameEvent().getListGraphics().size(),
				event.gameEvent().getListGames().size());

	if (_userPos.ry() < maxLine + 1)
		_userPos.ry()++;
}
