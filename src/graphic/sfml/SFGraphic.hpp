//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.hpp
//

#ifndef CPP_ARCADE_GRAPHICSF_HPP
#define CPP_ARCADE_GRAPHICSF_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <src/graphic/IShapeLoader.hpp>
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"
#include "SFShapeLoader.hpp"

namespace arc {
	class SFGraphic : public virtual IGraphic {
	public:
		static std::unique_ptr<IGraphic> &getInstance();
		void display() const;

		virtual const IShapeLoader & getShapeLoader() const override;

		virtual void catchEvent(arc::EventHandler &handler) override;

	private:
		arc::SFShapeLoader _loader;
	};
}

#endif /* CPP_ARCADE_GRAPHICSF_HPP */