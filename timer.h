#ifndef TIMER_H
#define TIMER_H

#include <boost/timer/timer.hpp>

class Timer{
	private:
	  boost::timer::cpu_timer t;
	
	
	public:
		Timer();
		~Timer();
		double getTime();
};


#endif
