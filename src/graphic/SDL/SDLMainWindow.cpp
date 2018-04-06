//
// EPITECH PROJECT, 2018
// cpp_arcade - SDLMainWindow.cpp
// File description:
// Created by Faudil Puttilli
//

#include <src/std/Color.hpp>
#include "SDLMainWindow.hpp"
#include <SDL2/SDL2_gfxPrimitives.h>

arc::SDLMainWindow &arc::SDLMainWindow::getInstance()
{
	static std::UPTR<SDLMainWindow> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new SDLMainWindow(arc::VertexI(700, 700)));
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
	_render.reset(SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED));
}

void arc::SDLMainWindow::setWindowSize(size_t x, size_t y)
{
	SDL_SetWindowSize(_window.get(), x, y);
}

void arc::SDLMainWindow::close()
{
	SDL_DestroyWindow(_window.get());
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
//	std::cout << "zzzz" << std::endl;
	SDL_RenderPresent(_render.get());
	SDL_SetRenderDrawColor(_render.get(), 0, 0, 0, 0xFF);
	SDL_RenderClear(_render.get());
}

void arc::SDLMainWindow::pollEvent(EventHandler &evtHandler)
{
}

bool arc::SDLMainWindow::TextureInCache(const std::string &str) const
{
	return _textureCache.find(str) != _textureCache.end();
}

std::SPTR<SDL_Texture> arc::SDLMainWindow::getTextureCache(
	const std::string &str)
const
{
	return nullptr;
}

std::UPTR<SDL_Renderer, void (&)(SDL_Renderer *)> & arc::SDLMainWindow::getRenderer()
{
	return _render;
}


void arc::SDLMainWindow::addTexture(const std::string &filePath)
{
}
