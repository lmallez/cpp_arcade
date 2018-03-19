//
// EPITECH PROJECT, 2018
// cpp_arcade - IDrawLoader.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_IDRAWLOADER_HPP
#define CPP_ARCADE_IDRAWLOADER_HPP

#include "IDraw.hpp"
#include <unordered_map>
#include <src/core/shape/IShape.hpp>

namespace arc {
	class IDrawLoader {
	public:
		virtual const IDraw & load(const std::shared_ptr<IShape>)
		const = 0;
	};
}

#endif //CPP_ARCADE_IDRAWLOADER_HPP
