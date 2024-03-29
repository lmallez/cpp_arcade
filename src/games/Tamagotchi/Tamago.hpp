//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Tamago.hpp
//

#ifndef CPP_ARCADE_TAMAGO_HPP
#define CPP_ARCADE_TAMAGO_HPP

#include "src/games/utils/Animated/AnimatedTexture.hpp"
#include "src/games/utils/IObject.hpp"

namespace arc {
	namespace tamago {
		class Tamago {
		public:
			Tamago(const arc::Texture &texture, const AnimatedTexture &body);

			std::shared_ptr<arc::IShape>
			draw(const std::shared_ptr<arc::IShape> &parent,
				const RectF &pos);
			void setHead(const Texture &head);
			void setBody(const AnimatedTexture &_body);
			void moveHeart();
			void feelInLove();
			void dance();
			void setSpeed(float speed);

		private:
			Texture _head;
			Texture _loveText;
			AnimatedTexture _body;
			std::vector<arc::VertexF> _love;
		};
	}
}

#endif /* CPP_ARCADE_TAMAGO_HPP */