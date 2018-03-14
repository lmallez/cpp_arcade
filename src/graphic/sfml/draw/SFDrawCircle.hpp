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
			const VertexF &pos = VertexF(0, 0),
			const size_t &radius = 0,
			std::shared_ptr<IDraw> parent = nullptr);
		explicit SFDrawCircle(
			const VertexF &pos = VertexF(0, 0),
			const VertexF &size = VertexF(0, 0),
			std::shared_ptr<IDraw> parent = nullptr);
		explicit SFDrawCircle(const RectF &rect,
			std::shared_ptr<IDraw> parent = nullptr);
		SFDrawCircle(const SFDrawCircle &ex);
		~SFDrawCircle() = default;

		virtual void draw() const override;
		virtual std::unique_ptr<IDraw> clone() override;
	};
}

#endif /* CPP_ARCADE_SFDRAWCIRCLE_HPP */