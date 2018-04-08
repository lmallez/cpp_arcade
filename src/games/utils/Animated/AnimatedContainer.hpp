//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedContainer.hpp
//

#ifndef CPP_ARCADE_ANIMATEDCONTAINER_HPP
#define CPP_ARCADE_ANIMATEDCONTAINER_HPP

#include <vector>
#include "src/games/utils/IObject.hpp"
#include "src/core/corebuild/CoreClock.hpp"
#include "AnimatedObject.hpp"

namespace arc {
	class AnimatedContainer : public AnimatedObject {
	public:
		AnimatedContainer(const std::vector<std::SPTR<IObject>> &obj,
				size_t update);

		std::SPTR<IShape>
		draw(const std::SPTR<arc::IShape> &parent) const override;
		bool collision(const RectF &obj) const override;
		void nextFrame() override;

	private:
		std::vector<std::SPTR<IObject>> _obj;
		size_t _selected;
	};
}

#endif /* CPP_ARCADE_ANIMATEDCONTAINER_HPP */
