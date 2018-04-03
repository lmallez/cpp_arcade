/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/events/KeyEvent.hpp"
#include "src/exception/Exception.hpp"

Test(KeyEvent, aled)
{
	arc::KeyEvent e;
	cr_assert(e.isKeyPressed(arc::KeyEvent::Key::A) == false);
	e.setKeyPressed(arc::KeyEvent::Key::A);
	cr_assert(e.isKeyPressed(arc::KeyEvent::Key::A) == true);
	cr_assert(e.isKeyjustPressed(arc::KeyEvent::Key::A) == true);
	e.makeOld();
	cr_assert(e.isKeyjustPressed(arc::KeyEvent::Key::A) == false);
	e.setKeyReleased(arc::KeyEvent::Key::A);
	cr_assert(e.isKeyjustReleased(arc::KeyEvent::Key::A) == true);

	try {
		e.setKeyPressed(arc::KeyEvent::Key::UNKNOWN);
	} catch (arc::Exception E) {
	}
	try {
		e.setKeyReleased(arc::KeyEvent::Key::UNKNOWN);
	} catch (arc::Exception E) {
	}
	try {
		e.setKeyState(arc::KeyEvent::Key::UNKNOWN, true);
	} catch (arc::Exception E) {
	}
	e.makeOld();
	e.setKeyState(arc::KeyEvent::Key::A, true);
	cr_assert(e.isKeyjustPressed(arc::KeyEvent::Key::A) == true);
}
