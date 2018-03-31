//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Snake.hpp
//

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP

#include <vector>

namespace arc {
	namespace snake {
		class Snake {
		public:
			Snake(const VertexS &pos);

			bool move(const VertexS &head, bool increase);
			const std::vector<VertexS> &getBody() const;
			const VertexS &getHead() const;
			bool inSnake(const arc::VertexS &head) const;

		private:
			size_t _len;
			arc::VertexS _head;
			std::vector<arc::VertexS> _body;
		};
	}
}

#endif /* CPP_ARCADE_SNAKE_HPP */