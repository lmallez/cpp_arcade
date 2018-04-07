//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.hpp
//

#ifndef CPP_ARCADE_GRAPHICSF_HPP
#define CPP_ARCADE_GRAPHICSF_HPP

#include <SDL2/SDL_ttf.h>
#include <src/graphic/IShapeLoader.hpp>
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"
#include "SDLShapeLoader.hpp"

namespace arc {
	class SDLGraphic : public virtual IGraphic {
	public:
		static IGraphic & getInstance(bool destroy = false);
		void display() const;

		virtual const IShapeLoader & getShapeLoader() const override;

		virtual void catchEvent(arc::EventHandler &handler) override;
		virtual void close() override;

	private:
		arc::SDLShapeLoader _loader;
	};
}

#endif /* CPP_ARCADE_GRAPHICSF_HPP */