//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreClock.cpp
//

#include <ctime>
#include <iostream>
#include "CoreClock.hpp"

arc::CoreClock::CoreClock(unsigned int waitTime):
	_waitTime(waitTime), _timescamp(0)
{
	std::cout << "ALED" << std::endl;
}

bool arc::CoreClock::compare(unsigned long time) const
{
	return (time - _timescamp > _waitTime);
}

bool arc::CoreClock::updateTime()
{
	const unsigned long &tempTime = (unsigned long)time(NULL);

	if (!compare(tempTime))
		return false;
	_timescamp = tempTime;
	return true;
}

void arc::CoreClock::waitTime()
{
	while (updateTime());
}
