//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedShape.hpp
//

#ifndef CPP_ARCADE_ANIMATEDSHAPE_HPP
#define CPP_ARCADE_ANIMATEDSHAPE_HPP

#include <vector>
#include "src/core/corebuild/CoreClock.hpp"
#include "src/games/utils/IObject.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "AnimatedObject.hpp"

namespace arc {
	class AnimatedTexture : public AnimatedObject {
	public:
		AnimatedTexture(const std::vector<Texture> &obj, RectF pos, float update);

		std::SPTR<IShape> draw(const std::SPTR<arc::IShape> &parent) const override;
		bool collision(const RectF &obj) const override;

		void nextFrame() override;

	private:
		RectF _pos;
		std::vector<arc::Texture> _obj;
		size_t _selected;
	};
}

#endif /* CPP_ARCADE_ANIMATEDSHAPE_HPP */
