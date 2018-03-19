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
#include <src/graphic/AGraphic.hpp>
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"

namespace arc {
	class SFGraphic : public AGraphic {
	public:
		static std::unique_ptr<SFGraphic> &initialize();
		~SFGraphic();

		VertexF getSize() const;
		void display() const;
		void drawItem(const sf::Drawable &toDraw);

	private:
		explicit SFGraphic(VertexS size = VertexS(400, 400));
		std::unique_ptr<sf::RenderWindow> _window;
	};
}

#endif /* CPP_ARCADE_GRAPHICSF_HPP */