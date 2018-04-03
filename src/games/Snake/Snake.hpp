//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Snake.hpp
//

#ifndef CPP_ARCADE_SNAKE_HPP
#define CPP_ARCADE_SNAKE_HPP

#include <vector>
#include "src/games/Controller/PlayerController.hpp"

#define START_SIZE 4

namespace arc {
	namespace snake {
		class Snake : protected PlayerController {
		public:
			Snake(const VertexS &mapSize);

			bool moveHead(const VertexS &head);
			void deleteTail();
			bool move(arc::EventHandler &event);

			void execKey(EventHandler &event) override;

			const std::vector<VertexS> &getBody() const;
			const VertexS &getHead() const;
			bool inSnake(const arc::VertexS &pos) const;
			bool
			eatFlower(const arc::VertexS &flowerPos, size_t value);

			size_t getScore() const;

		private:
			size_t _score;
			arc::VertexS _head;
			std::vector<arc::VertexS> _body;
		};
	}
}

#endif /* CPP_ARCADE_SNAKE_HPP */