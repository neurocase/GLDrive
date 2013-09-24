#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "timer.h"


#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>


Timer::Timer(){

  t.start();

}

double Timer::getTime(){
	double timeA =  t.elapsed().wall*1e-9;
	//std::cout << "" << timeA ;
	return timeA;
}

Timer::~Timer(){


}

