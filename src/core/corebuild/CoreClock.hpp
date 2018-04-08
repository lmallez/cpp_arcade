//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreClock.hpp
//

#ifndef CPP_ARCADE_CORECLOCK_HPP
#define CPP_ARCADE_CORECLOCK_HPP

#include <chrono>

namespace arc {
	class CoreClock {
	public:
		explicit CoreClock(const std::chrono::duration<double> &a);
		explicit CoreClock(double waitTime);

		bool compare(const std::chrono::duration<double> &time);
		bool updateTime();
		void waitTime();

		void setWaitTime(double _waitTime);

	private:
		std::chrono::duration<double> _waitTime;
		std::chrono::duration<double> _timescamp;
	};
}

#endif /* CPP_ARCADE_CORECLOCK_HPP */
