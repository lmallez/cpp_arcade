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
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"

namespace arc {
	class SFGraphic : public virtual IGraphic {
	public:
		static std::unique_ptr<IGraphic> &getInstance();
		void display() const;
	};
}

#endif /* CPP_ARCADE_GRAPHICSF_HPP */