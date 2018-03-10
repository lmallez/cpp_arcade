//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFGraphic.hpp
//

#ifndef CPP_ARCADE_GRAPHICSF_HPP
#define CPP_ARCADE_GRAPHICSF_HPP

#include <SFML/Window.hpp>
#include <SFML/System/Vector2.hpp>
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"

namespace arc {
	class SFGraphic : public virtual IGraphic {
	public:
		static std::unique_ptr<SFGraphic> &initialize();
		~SFGraphic();

		VertexI getSize() const;
	private:
		explicit SFGraphic(VertexS size = VertexS(100, 100));
		std::unique_ptr<sf::Window> _window;
	};
}

#endif /* CPP_ARCADE_GRAPHICSF_HPP */