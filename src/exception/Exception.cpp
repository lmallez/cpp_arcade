//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ArcExecption.cpp
//

#include "Exception.hpp"

arc::Exception::Exception(
	const std::string &context,
	const std::string &message)
{
	_error = context + ": "  + message;
}

const char *arc::Exception::what() const throw()
{
	return _error.c_str();
}
