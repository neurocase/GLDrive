#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "laser.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>

Laser::Laser(){
	//empty constructor for no apparent reason
	lx = 0;
	ly = 0;
	isActive = false;
}

Laser::Laser(double shooterXPos, double shooterYPos, double direction){
	lx = shooterXPos;
	ly = shooterYPos;
	isActive = true;
	isGoUp = true;
}

void Laser::getXY(double &x, double &y){
	x = lx;
	y = ly;
}

void Laser::setXY(double x, double y){
	lx = x;
	ly = y;
}


Laser::~Laser(){

}
