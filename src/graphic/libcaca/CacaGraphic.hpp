/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** CacaGraphic.hpp
*/

#ifndef CPP_ARCADE_GRAPHICCACA_HPP
#define CPP_ARCADE_GRAPHICCACA_HPP

#include <caca.h>
#include "src/graphic/IShapeLoader.hpp"
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"
#include "CacaShapeLoader.hpp"

namespace arc {
	class CacaGraphic : public virtual IGraphic {
	public:
		static IGraphic & getInstance();
		void display() const;

		virtual const IShapeLoader & getShapeLoader() const override;

		virtual void catchEvent(arc::EventHandler &handler) override;

		virtual void close() override;
	private:
		arc::CacaShapeLoader _loader;
	};
}

#endif /* CPP_ARCADE_GRAPHICCACA_HPP */
