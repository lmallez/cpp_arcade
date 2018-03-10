//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// operatorz.hpp
//

#ifndef CPP_ARCADE_OPERATORZ_HPP
#define CPP_ARCADE_OPERATORZ_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <src/graphic/ADraw.hpp>
#include "src/std/Rect.hpp"
#include "src/std/Vertex.hpp"

template <typename T>
sf::Vector2<T> operator=(const arc::Vertex<T> &ex) const;
template <typename T>
arc::Vertex<T> operator=(const sf::Vector2<T> &ex) const;
template <typename T>
sf::Rect<T> operator=(const arc::Rect<T> &ex) const;
template <typename T>
arc::Rect<T> operator=(const sf::Rect<T> &ex) const;

#endif /* CPP_ARCADE_OPERATORZ_HPP */