//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.hpp
//

#ifndef CPP_ARCADE_SFDRAW_HPP
#define CPP_ARCADE_SFDRAW_HPP

#include <vector>
#include "src/graphic/ADraw.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/std/Vertex.hpp"

namespace arc {
	class SFDraw : public ADraw {
	public:
		virtual RectI winPos() const override;

	protected:
		VertexF _pos;
		VertexF _size;
	};
}

#endif /* CPP_ARCADE_SFDRAW_HPP */