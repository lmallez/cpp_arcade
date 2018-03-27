//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreClock.hpp
//

#ifndef CPP_ARCADE_CORECLOCK_HPP
#define CPP_ARCADE_CORECLOCK_HPP

namespace arc {
	class CoreClock {
	public:
		explicit CoreClock(unsigned int waitTime);

		bool compare(unsigned long time) const;
		bool updateTime();
		void waitTime();
	private:
		unsigned long _timescamp;
		unsigned int _waitTime;
	};
}

#endif /* CPP_ARCADE_CORECLOCK_HPP */