//
// EPITECH PROJECT, 2018
// cpp_arcade - SDLMainWindow.cpp
// File description:
// Created by Faudil Puttilli
//

#include "SDLMainWindow.hpp"

std::unordered_map<SDL_Keycode,
	arc::KeyEvent::Key> arc::SDLMainWindow::_keyMap = {
	{SDLK_a, arc::KeyEvent::Key::A},
	{SDLK_b, arc::KeyEvent::Key::B},
	{SDLK_c, arc::KeyEvent::Key::C},
	{SDLK_d, arc::KeyEvent::Key::D},
	{SDLK_e, arc::KeyEvent::Key::E},
	{SDLK_f, arc::KeyEvent::Key::F},
	{SDLK_g, arc::KeyEvent::Key::G},
	{SDLK_h, arc::KeyEvent::Key::H},
	{SDLK_i, arc::KeyEvent::Key::I},
	{SDLK_j, arc::KeyEvent::Key::J},
	{SDLK_k, arc::KeyEvent::Key::K},
	{SDLK_l, arc::KeyEvent::Key::L},
	{SDLK_m, arc::KeyEvent::Key::M},
	{SDLK_n, arc::KeyEvent::Key::N},
	{SDLK_o, arc::KeyEvent::Key::O},
	{SDLK_p, arc::KeyEvent::Key::P},
	{SDLK_q, arc::KeyEvent::Key::Q},
	{SDLK_r, arc::KeyEvent::Key::R},
	{SDLK_s, arc::KeyEvent::Key::S},
	{SDLK_t, arc::KeyEvent::Key::T},
	{SDLK_u, arc::KeyEvent::Key::U},
	{SDLK_v, arc::KeyEvent::Key::V},
	{SDLK_w, arc::KeyEvent::Key::W},
	{SDLK_x, arc::KeyEvent::Key::X},
	{SDLK_y, arc::KeyEvent::Key::Y},
	{SDLK_z, arc::KeyEvent::Key::Z},
	{SDLK_LEFT, arc::KeyEvent::Key::LEFT},
	{SDLK_RIGHT, arc::KeyEvent::Key::RIGHT},
	{SDLK_UP, arc::KeyEvent::Key::UP},
	{SDLK_DOWN, arc::KeyEvent::Key::DOWN},
	{SDLK_ESCAPE, arc::KeyEvent::Key::ESCAPE},
	{SDLK_SPACE, arc::KeyEvent::Key::SPACE},
	{SDLK_LSHIFT, arc::KeyEvent::Key::LSHIFT},
	{SDLK_RSHIFT, arc::KeyEvent::Key::RSHIFT},
	{SDLK_TAB, arc::KeyEvent::Key::TAB},
	{SDLK_RETURN, arc::KeyEvent::Key::RETURN},
	{SDLK_BACKSPACE, arc::KeyEvent::Key::BACKSPACE},
	{SDLK_0, arc::KeyEvent::Key::NUM0},
	{SDLK_1, arc::KeyEvent::Key::NUM1},
	{SDLK_2, arc::KeyEvent::Key::NUM2},
	{SDLK_3, arc::KeyEvent::Key::NUM3},
	{SDLK_4, arc::KeyEvent::Key::NUM4},
	{SDLK_5, arc::KeyEvent::Key::NUM5},
	{SDLK_6, arc::KeyEvent::Key::NUM6},
	{SDLK_7, arc::KeyEvent::Key::NUM7},
	{SDLK_8, arc::KeyEvent::Key::NUM8},
	{SDLK_9, arc::KeyEvent::Key::NUM9},
};

std::unordered_map<Uint8, arc::MouseEvent::MouseButton>
        arc::SDLMainWindow::_mouseMap = {
	{SDL_BUTTON_RIGHT, arc::MouseEvent::RIGHT_BUTTON},
	{SDL_BUTTON_LEFT, arc::MouseEvent::LEFT_BUTTON},
	{SDL_BUTTON_MIDDLE, arc::MouseEvent::MIDDLE_BUTTON}
};

arc::SDLMainWindow &arc::SDLMainWindow::getInstance(bool destroy)
{
	static std::UPTR<SDLMainWindow> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new SDLMainWindow(arc::VertexI(700, 700)));
	else if (instance->_window == nullptr) {
		instance->_window.reset(SDL_CreateWindow(WNAME,
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, 700,
					700, 0));
		instance->_render.
			reset(SDL_CreateRenderer(instance->_window.get(), -1,
						SDL_RENDERER_ACCELERATED));
	}
	if (destroy)
		instance.reset(nullptr);
	return *instance;
}

arc::SDLMainWindow::SDLMainWindow(arc::VertexI size) :
	_window(nullptr, SDL_DestroyWindow),
	_render(nullptr, SDL_DestroyRenderer)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_window.reset(SDL_CreateWindow(WNAME, SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, size.x(),
				size.y(), 0));
	if (!_window)
		throw arc::Exception("SDL Graphic", "Can't open the Window");
	_render.reset(SDL_CreateRenderer(_window.get(), -1,
					SDL_RENDERER_ACCELERATED));
}

arc::SDLMainWindow::~SDLMainWindow()
{
	for (auto it = _textureCache.begin(); it != _textureCache.end();
		it++) {
		SDL_DestroyTexture(it->second);
	}
}

void arc::SDLMainWindow::setWindowSize(size_t x, size_t y)
{
	SDL_SetWindowSize(_window.get(), x, y);
}

void arc::SDLMainWindow::close()
{
	_render.reset(nullptr);
	_window.reset(nullptr);
	SDL_Quit();
}

arc::VertexF arc::SDLMainWindow::getSize() const
{
	if (!_window)
		return {0, 0};
	int x;
	int y;
	SDL_GetWindowSize(_window.get(), &x, &y);
	return VertexF(x, y);
}

void arc::SDLMainWindow::display()
{
	SDL_RenderPresent(_render.get());
	SDL_SetRenderDrawColor(_render.get(), 0, 0, 0, 0xFF);
	SDL_RenderClear(_render.get());
}

arc::VertexF arc::SDLMainWindow::getRelPos() const
{
	arc::VertexF relPos;
	int x, y, w, h;
	SDL_GetMouseState(&x, &y);
	SDL_GetWindowSize(_window.get(), &w, &h);
	relPos.rx() = (float) x / w;
	relPos.ry() = (float) y / h;
	return relPos;
}

void arc::SDLMainWindow::pollEvent(EventHandler &evtHandler)
{
	SDL_Event evt;

	evtHandler.keyEvent().makeOld();
	evtHandler.mouseEvent().makeOld();
	while (SDL_PollEvent(&evt)) {
		switch (evt.type) {
		case SDL_KEYDOWN:
			evtHandler.keyEvent().setKeyPressed(_keyMap[evt.key
				.keysym.sym]);
			break;
		case SDL_KEYUP:
			evtHandler.keyEvent().setKeyReleased(_keyMap[evt.key
				.keysym.sym]);
			break;
		case SDL_MOUSEMOTION:
			evtHandler.mouseEvent().setPos(getRelPos());
			break;
		case SDL_MOUSEBUTTONDOWN:
			evtHandler.mouseEvent().setButtonPressed(
				_mouseMap[evt.button.button]);
			break;
		case SDL_MOUSEBUTTONUP:
			evtHandler.mouseEvent().setButtonReleased(
				_mouseMap[evt.button.button]);
		default:
			break;
		}
	}
}

bool arc::SDLMainWindow::TextureInCache(const std::string &str) const
{
	return _textureCache.find(str) != _textureCache.end();
}

SDL_Texture * arc::SDLMainWindow::getTextureCache(const std::string &str)
const
{
	return _textureCache.at(str);
}

std::UPTR<SDL_Renderer, void (&)(SDL_Renderer *)>
&arc::SDLMainWindow::getRenderer()
{
	return _render;
}


void arc::SDLMainWindow::addTexture(const std::string &filePath)
{
	SDL_Surface *tmp = IMG_Load(filePath.c_str());
	if (!tmp)
		throw arc::Exception("SDL", "Can't load texture : " + filePath);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(_render.get(), tmp);
	if (!texture)
		throw arc::Exception("SDL", "Can't transform suface");
	SDL_FreeSurface(tmp);
	_textureCache[filePath] = texture;
}
