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
		explicit SFDraw(const RectF &geometry,
			std::shared_ptr<IDraw> parent = nullptr);
		explicit SFDraw(const VertexF &pos, const VertexF &size,
			std::shared_ptr<IDraw> parent = nullptr);
		SFDraw(const ADraw &ex);
		virtual RectI winPos() const override;
	};
}

#endif /* CPP_ARCADE_SFDRAW_HPP */