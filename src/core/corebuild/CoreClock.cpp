//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreClock.cpp
//

#include <iostream>
#include "CoreClock.hpp"

arc::CoreClock::CoreClock(const std::chrono::duration<double> &waitTime):
	_waitTime(waitTime), _timescamp(0)
{
}

arc::CoreClock::CoreClock(double waitTime):
	_waitTime(waitTime), _timescamp(0)
{
}

bool arc::CoreClock::compare(const std::chrono::duration<double> &time)
{
	return (time.count() - _timescamp.count() > _waitTime.count());
}

bool arc::CoreClock::updateTime()
{
	auto tempTime = std::chrono::system_clock::now().time_since_epoch();

	if (!compare(tempTime))
		return false;
	_timescamp = tempTime;
	return true;
}

void arc::CoreClock::waitTime()
{
	while (!updateTime());
}

void arc::CoreClock::setWaitTime(double waitTime)
{
	_waitTime = std::chrono::duration<double>(waitTime);
}
