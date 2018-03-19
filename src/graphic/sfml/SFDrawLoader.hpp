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
		static const std::unique_ptr<IDrawLoader> & getInstance();
		const IDraw & load(const std::shared_ptr<IShape> t)
		const override;
	private:
		explicit SFDrawLoader();
		std::unordered_map<std::string, std::unique_ptr<arc::IDraw>> _items;
	};
}

#endif //CPP_ARCADE_SFDRAWLOADER_HPP
