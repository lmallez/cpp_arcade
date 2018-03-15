//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawCircle.hpp
//

#ifndef CPP_ARCADE_SFDRAWCIRCLE_HPP
#define CPP_ARCADE_SFDRAWCIRCLE_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include "SFDraw.hpp"
#include "src/std/Rect.hpp"
#include "src/graphic/sfml/operator.hpp"

namespace arc {
	class SFDrawCircle : public SFDraw {
	public:
		explicit SFDrawCircle(
			std::shared_ptr<IDraw> parent,
			const Texture &texture,
			const VertexF &pos,
			const size_t &radius);
		explicit SFDrawCircle(
			std::shared_ptr<IDraw> parent,
			const Texture &texture,
			const VertexF &pos,
			const VertexF &size);
		explicit SFDrawCircle(
			std::shared_ptr<IDraw> parent,
			const Texture &texture,
			const RectF &rect);
		SFDrawCircle(const SFDrawCircle &ex);
		~SFDrawCircle() = default;

		virtual void draw() const override;
		virtual std::unique_ptr<IDraw> clone() override;
	};
}

#endif /* CPP_ARCADE_SFDRAWCIRCLE_HPP */