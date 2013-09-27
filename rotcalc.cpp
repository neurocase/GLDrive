#include "rotcalc.h"
//#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "player.h"

//#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>


Rotcalc::Rotcalc(){
	
}
	
double force = 0;	
double mass = 1;
double accel = 0;	

double h_pX = 0;
double h_pY = 0;

void Rotcalc::calcPhys(double &rot, int r, double &pX, double &pY, int fuel){

//int r = rot;


//----------------------
//-----FRICTION---------
if (accel > 0){
	accel -= 0.01;
}
if (accel < 0){
	accel = 0;
}
//----------------------

if (fuel == 1){
accel += 0.1;
	if (accel > 0.3){
		accel = 0.3;
	}
}




switch(r){
	case -1:
		rot -= 0.1;
		break;
	case 1:
		rot += 0.1;
		break;
	default:
		break;
}


h_pX = pX;
h_pY = pY;





force = mass * accel;

pX = pX + (force * cos(rot));
pY = pY + (force * sin(rot));

//velocity = displacement / time velocity

double velX = (pX - h_pX ) /10;
double velY = (pY - h_pY) /10;
pX += velX;
pY += velY;


	
}

double Rotcalc::getVelT(){
	return (std::abs(velocityY) + std::abs(velocityX));
}

Rotcalc::~Rotcalc(){
	
}
