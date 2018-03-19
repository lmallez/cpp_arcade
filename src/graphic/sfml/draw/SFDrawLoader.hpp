//
// EPITECH PROJECT, 2018
// cpp_arcade - SFDrawLoader.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_SFDRAWLOADER_HPP
#define CPP_ARCADE_SFDRAWLOADER_HPP

#include <src/graphic/IDrawLoader.hpp>

namespace arc {

	class SFDrawLoader : public virtual arc::IDrawLoader
	{
	public:
		std::unique_ptr<IDraw> load(const arc::IShape &t)
		const override;
	private:
		std::unordered_map<std::string, arc::IDraw> _items;
	};
}


#endif //CPP_ARCADE_SFDRAWLOADER_HPP
