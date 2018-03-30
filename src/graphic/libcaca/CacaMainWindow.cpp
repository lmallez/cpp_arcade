/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaMainWindow.hpp"

std::unordered_map<char, arc::KeyEvent::Key> arc::CacaMainWindow::_keyMapUTF = {
	{'a', arc::KeyEvent::A},
	{'A', arc::KeyEvent::A},
	{'b', arc::KeyEvent::B},
	{'B', arc::KeyEvent::B},
	{'c', arc::KeyEvent::C},
	{'C', arc::KeyEvent::C},
	{'d', arc::KeyEvent::D},
	{'D', arc::KeyEvent::D},
	{'e', arc::KeyEvent::E},
	{'E', arc::KeyEvent::E},
	{'f', arc::KeyEvent::F},
	{'F', arc::KeyEvent::F},
	{'g', arc::KeyEvent::G},
	{'G', arc::KeyEvent::G},
	{'h', arc::KeyEvent::H},
	{'H', arc::KeyEvent::H},
	{'i', arc::KeyEvent::I},
	{'I', arc::KeyEvent::I},
	{'j', arc::KeyEvent::J},
	{'J', arc::KeyEvent::J},
	{'k', arc::KeyEvent::K},
	{'K', arc::KeyEvent::K},
	{'l', arc::KeyEvent::L},
	{'L', arc::KeyEvent::L},
	{'m', arc::KeyEvent::M},
	{'M', arc::KeyEvent::M},
	{'n', arc::KeyEvent::N},
	{'N', arc::KeyEvent::N},
	{'o', arc::KeyEvent::O},
	{'O', arc::KeyEvent::O},
	{'p', arc::KeyEvent::P},
	{'P', arc::KeyEvent::P},
	{'q', arc::KeyEvent::Q},
	{'Q', arc::KeyEvent::Q},
	{'r', arc::KeyEvent::R},
	{'R', arc::KeyEvent::R},
	{'s', arc::KeyEvent::S},
	{'S', arc::KeyEvent::S},
	{'t', arc::KeyEvent::T},
	{'T', arc::KeyEvent::T},
	{'u', arc::KeyEvent::U},
	{'U', arc::KeyEvent::U},
	{'v', arc::KeyEvent::V},
	{'V', arc::KeyEvent::V},
	{'w', arc::KeyEvent::W},
	{'W', arc::KeyEvent::W},
	{'x', arc::KeyEvent::X},
	{'X', arc::KeyEvent::X},
	{'y', arc::KeyEvent::Y},
	{'Y', arc::KeyEvent::Y},
	{'z', arc::KeyEvent::Z},
	{'Z', arc::KeyEvent::Z},
	{'1', arc::KeyEvent::NUM1},
	{'&', arc::KeyEvent::NUM1},
	{'2', arc::KeyEvent::NUM2},
	{233, arc::KeyEvent::NUM2},
	{'3', arc::KeyEvent::NUM3},
	{34, arc::KeyEvent::NUM3},
	{'4', arc::KeyEvent::NUM4},
	{39, arc::KeyEvent::NUM4},
	{'5', arc::KeyEvent::NUM5},
	{40, arc::KeyEvent::NUM5},
	{'6', arc::KeyEvent::NUM6},
	{45, arc::KeyEvent::NUM6},
	{'7', arc::KeyEvent::NUM7},
	{232, arc::KeyEvent::NUM7},
	{'8', arc::KeyEvent::NUM8},
	{95, arc::KeyEvent::NUM8},
	{'9', arc::KeyEvent::NUM9},
	{231, arc::KeyEvent::NUM9},
	{'0', arc::KeyEvent::NUM0},
	{224, arc::KeyEvent::NUM0},
	{13, arc::KeyEvent::RETURN},
};

std::unordered_map<char, arc::KeyEvent::Key> arc::CacaMainWindow::_keyMapCH = {
	{CACA_KEY_UP, arc::KeyEvent::UP},
	{CACA_KEY_DOWN, arc::KeyEvent::DOWN},
	{CACA_KEY_LEFT, arc::KeyEvent::LEFT},
	{CACA_KEY_RIGHT, arc::KeyEvent::RIGHT}
};

arc::CacaMainWindow &arc::CacaMainWindow::getInstance()
{
	static std::unique_ptr<arc::CacaMainWindow> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new CacaMainWindow(arc::VertexI(700 / 7, 700 / 14)));
	return *instance;
}

arc::CacaMainWindow::CacaMainWindow(arc::VertexI size) :
	_canvas(nullptr, caca_free_canvas),
	_window(nullptr, caca_free_display)
{
	_canvas.reset(caca_create_canvas(size.x(), size.y()));
	_window.reset(caca_create_display(_canvas.get()));

	if (_window == nullptr)
		throw arc::Exception("Caca Graphic", "Can't open the Main "
						     "Window");
}

void arc::CacaMainWindow::setWindowSize(size_t x, size_t y)
{
	caca_set_canvas_size(_canvas.get(), x, y);
}

std::unique_ptr<caca_canvas, int (*)(caca_canvas_t*)>
&arc::CacaMainWindow::getCanvas()
{
	return _canvas;
}

void arc::CacaMainWindow::close()
{
	caca_free_display(_window.get());
	caca_free_canvas(_canvas.get());
}

arc::VertexF arc::CacaMainWindow::getSize() const
{
	if (_window != nullptr)
		return VertexF(caca_get_display_width(_window.get()),
			caca_get_display_height(_window.get()));
	return {0, 0};
}

void arc::CacaMainWindow::display()
{
	caca_refresh_display(_window.get());
	caca_set_color_argb(_canvas.get(),
		0xFFFF, 0xF000);
	caca_clear_canvas(_canvas.get());
}

void arc::CacaMainWindow::pollEvent(arc::EventHandler &evtHandler)
{
	caca_event_type evtType;
	caca_event_t evt;

	evtHandler.keyEvent().makeOld();
	while (caca_get_event(_window.get(), CACA_EVENT_ANY, &evt, 140)) {
		evtType = caca_get_event_type(&evt);
		switch (evtType) {
		case CACA_EVENT_KEY_PRESS:
			evtHandler.keyEvent().setKeyPressed(_keyMapUTF[caca_get_event_key_utf32(&evt)]);
			evtHandler.keyEvent().setKeyPressed(_keyMapCH[caca_get_event_key_ch(&evt)]);
			break;
		case CACA_EVENT_KEY_RELEASE:
			evtHandler.keyEvent().setKeyReleased(_keyMapUTF[caca_get_event_key_utf32(&evt)]);
			break;
		default:
			break;
		}
	}
}
