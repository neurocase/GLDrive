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
//double accel = 0;	
/*
double h_pX = 0;
double h_pY = 0;*/

void Rotcalc::calcPhys(double &rot, int r, double &pX, double &pY, double &velX, double &velY, int fuel){

//int r = rot;


//----------------------
//-----FRICTION---------
/*
if (accel > 0){
	accel -= 0.01;
}
if (accel < 0){
	accel = 0;
}*/
//----------------------
/*
if (fuel == 1){
force += 0.1;
	if (force > 0.3){
		force = 0.3;
	}
}
*/


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

double engineForce = fuel;

double thickness = 0.5;	
double dragX = thickness * -velX / mass;
double dragY = thickness * -velY / mass;

double forceX = engineForce * cos(rot) + dragX;
double forceY = engineForce * sin(rot) + dragY; 

/*
h_pX = pX;
h_pY = pY;*/

//force = mass * accel;

double deltaT = 0.01;

//double accel = force / mass;
double dt2 = deltaT * deltaT / 2;

double accelX = forceX / mass; //accel * cos(rot);
double accelY = forceY / mass; //accel * sin(rot);

pX = pX + deltaT * velX + dt2 * accelX;
velX = velX + deltaT * accelX;

pY = pY + deltaT * velY + dt2 * accelY;
velY = velY + deltaT * accelY;

//(accel * cos(rot));
//pY = pY + (accel * sin(rot));

//velocity = displacement / time velocity
/*
double velX = (pX - h_pX ) /10;
double velY = (pY - h_pY) /10;*/
//pX += velX;
//pY += velY;
	
}

double Rotcalc::getVelT(){
	return (std::abs(velocityY) + std::abs(velocityX));
}

Rotcalc::~Rotcalc(){
	
}
