#include "rotcalc.h"
//#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "player.h"
//#inclide "timer.h"


//#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>


Rotcalc::Rotcalc(){
	
}

double force = 0;	
double mass = 1;
double engineForce = 0;
double traction = 1;
int dotdot = 0;
//double accel = 0;	
/*
double h_pX = 0;
double h_pY = 0;*/

void Rotcalc::calcPhys(double &rot, int r, double &pX, double &pY, double &velX, double &velY, int fuel,int isBrake, bool isHBrake){

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



if (fuel == 1){
	//first gear
	if (engineForce < 20){
	engineForce += 1;	
	}
	//second gear
	engineForce += 0.8;
	if (engineForce > 80){
		engineForce = 80;
	}
	}else if (fuel == 0){
		engineForce -= 2;
}

if (isBrake){
	if (engineForce > 0){
		engineForce -= 3;
	}
	if (engineForce <= 0){
		engineForce -= 0.3;
		if (engineForce < -10){
			engineForce = -10;
		}
	}
}
if (engineForce < 0 && !isBrake){
	engineForce = 0;
}

double totVel = std::abs(velX) + std::abs(velY);

if (totVel > 0 || engineForce > 0)
{
	double incT = 0.055;
	
	if (isHBrake){
	incT = 0.055 * totVel / 4; 
	engineForce = -2;
	std::cout << "handbrake" << std::endl;
	}
	
switch(r){
	case -1:
		rot -= incT;
		break;
	case 1:
		rot += incT;
		break;
	default:
		break;
}
}
double thickness = 5;
	
double dragX = thickness * -velX / mass;
double dragY = thickness * -velY / mass;

double forceX = engineForce * cos(rot) + dragX;
double forceY = engineForce * sin(rot) + dragY; 


if (dotdot == 0){	
std::cout << "fY:" << forceY << " fX:" << forceX << " engF:" << engineForce << std::endl;
} 
dotdot++;
if (dotdot > 30){
	dotdot = 0;
}



double deltaT = 0.01;

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
