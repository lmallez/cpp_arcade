//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ArcExecption.hpp
//

#ifndef CPP_ARCADE_ARCEXECPTION_HPP
#define CPP_ARCADE_ARCEXECPTION_HPP

#include <bits/exception.h>
#include <string>

namespace arc {
	class Exception : public std::exception {
	public:
		explicit Exception(
			const std::string &context = "Undefined",
			const std::string &message = "Unknown Error");
		~Exception() = default;

		virtual const char *what() const throw() override;

	private:
		std::string _error;
	};
}

#endif /* CPP_ARCADE_ARCEXECPTION_HPP */