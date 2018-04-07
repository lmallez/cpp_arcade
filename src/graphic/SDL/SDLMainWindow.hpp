//
// EPITECH PROJECT, 2018
// cpp_arcade - SDLMainWindow.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_SDLMAINWINDOW_HPP
#define CPP_ARCADE_SDLMAINWINDOW_HPP

#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_video.h>
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"

namespace arc
{
	class SDLMainWindow {
	public:
		static SDLMainWindow &getInstance();
		void setWindowSize(size_t x, size_t y);
		void display();
		VertexF getSize() const;
		void close();
		std::UPTR<SDL_Renderer, void (&)(SDL_Renderer *)> &
		getRenderer();
		void pollEvent(arc::EventHandler &);
		bool TextureInCache(const std::string &) const;
		std::SPTR<SDL_Texture> getTextureCache(
			const std::string &) const;
		void addTexture(const std::string &);
	private:
		explicit SDLMainWindow(VertexI = {400, 400});
		std::UPTR<SDL_Window, void (&)(SDL_Window*)> _window;
		std::UPTR<SDL_Renderer, void (&)(SDL_Renderer*)> _render;
		static std::unordered_map<SDL_Keycode,
			arc::KeyEvent::Key> _keyMap;
		static std::unordered_map<Uint8, arc::MouseEvent::MouseButton>
			_mouseMap;
		std::unordered_map<std::string, int>
			_textureCache;
	};

}

#endif //CPP_ARCADE_SDLMAINWINDOW_HPP
