//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AnimatedObject.hpp
//

#ifndef CPP_ARCADE_ANIMATEDOBJECT_HPP
#define CPP_ARCADE_ANIMATEDOBJECT_HPP

#include "src/core/corebuild/CoreClock.hpp"
#include "src/games/utils/IObject.hpp"

namespace arc {
	class AnimatedObject : virtual public IObject {
	public:
	AnimatedObject(size_t update);

	virtual void nextFrame() = 0;
	void update();

	private:
		CoreClock _clock;
		size_t selected;
	};
}

#endif /* CPP_ARCADE_ANIMATEDOBJECT_HPP */