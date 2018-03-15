//
// EPITECH PROJECT, 2018
// cpp_arcade - AShape.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_ASHAPE_HPP
#define CPP_ARCADE_ASHAPE_HPP

#include <vector>
#include <src/std/Color.hpp>
#include "IShape.hpp"

namespace arc
{

	class AShape : public virtual arc::IShape
	{
	public:
		arc::IShape &getChild(size_t id) override;
		arc::IShape &operator[](size_t id) override;
		bool operator!() const;
		size_t getChildNbr() const override;
		void addChild(std::unique_ptr<IShape>) override;
		void operator<<(std::unique_ptr<IShape>) override;
		arc::Texture getTexture() const override;
		void setTexture(const arc::Texture &) override;
	protected:
		arc::Texture _texture;
		std::vector<std::shared_ptr<arc::IShape>> _children;
	};

}

#endif //CPP_ARCADE_ASHAPE_HPP
