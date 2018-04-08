/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/events/MouseEvent.hpp"

Test(MouseEvent, creation)
{
	arc::MouseEvent e;
	cr_assert(e.getPos().x() == 0);
	cr_assert(e.getPos().y() == 0);
	e.setPos(arc::VertexF(1, 1));
	cr_assert(e.getPos().x() == 1);
	cr_assert(e.getPos().y() == 1);
	e.setButtonPressed(arc::MouseEvent::MouseButton::LEFT_BUTTON);
	cr_assert(e.isButtonPressed(arc::MouseEvent::MouseButton::LEFT_BUTTON));
}
