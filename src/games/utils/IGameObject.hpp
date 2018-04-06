//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// IGameObject.hpp
//

#ifndef CPP_ARCADE_IGAMEOBJECT_HPP
#define CPP_ARCADE_IGAMEOBJECT_HPP

#include <memory>
#include "src/graphic/IShape.hpp"

namespace arc {
	class IGameObject {
	public:
		virtual std::UPTR<IGameObject> clone() = 0;
		virtual std::SPTR<IShape> draw(std::SPTR<IShape> parent) = 0;
	};
}

#endif /* CPP_ARCADE_IGAMEOBJECT_HPP */