//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// test_sfml_shape.cpp
//

#include <memory>
#include <src/graphic/sfml/SFGraphic.hpp>
#include <src/graphic/sfml/draw/SFDrawRect.hpp>
#include <src/graphic/sfml/draw/SFDrawCircle.hpp>

int main(int ac, char **av)
{
	std::unique_ptr<arc::SFGraphic> &aled = arc::SFGraphic::initialize();
	arc::RectF center(0.25, 0.25, 0.5, 0.5);
	std::shared_ptr<arc::IDraw> shape1 =
		std::make_shared<arc::SFDrawCircle>(nullptr, center);
	std::shared_ptr<arc::IDraw> shape2 =
		std::make_shared<arc::SFDrawRect>(shape1, center);
	std::shared_ptr<arc::IDraw> shape3 =
		std::make_shared<arc::SFDrawCircle>(shape2, center);

	shape1->draw();
	shape2->draw();
	shape3->draw();
	aled->display();
	while (1);
}