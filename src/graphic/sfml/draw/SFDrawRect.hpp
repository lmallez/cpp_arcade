//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawRect.hpp
//

#ifndef CPP_ARCADE_SFDRAWRECT_HPP
#define CPP_ARCADE_SFDRAWRECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "SFDraw.hpp"
#include "src/std/Rect.hpp"
#include "src/graphic/sfml/operator.hpp"

namespace arc {
	class SFDrawRect : public SFDraw {
	public:
		explicit SFDrawRect(
			std::shared_ptr<IDraw> parent,
			const VertexF &pos,
			const VertexF &size);
		explicit SFDrawRect(
			std::shared_ptr<IDraw> parent,
			const RectF &rect);
		SFDrawRect(const SFDrawRect &ex);
		~SFDrawRect() = default;

		virtual void draw() const override;
		virtual std::unique_ptr<IDraw> clone() override;
	};
}

#endif /* CPP_ARCADE_SFDRAWRECT_HPP */