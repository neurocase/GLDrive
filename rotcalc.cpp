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

void Rotcalc::calcPhys(double &rot, int r, double &pX, double &pY, bool fuel){
	
	
//int r = rot;


double qrot = (rot/360)*4;
int qrt = (int)qrot;
double pqrt = qrot - qrt;



if (rot >= 360){
	rot -= 360;
}else if(rot < 0){
	rot += 360;
}

switch(r){
	case -1:
		rot -= 4;
		break;
	case 1:
		rot += 4;
		break;
	default:
		break;
}



pX = 0;
pY = 0;
//velocityX = 0;
//velocityY = 0;

if (fuel){	

	switch(qrt){
		case 0:
			velocityX += pqrt;
			velocityY -= (1-pqrt);
			mrX = pqrt;
			mrY = -(1-pqrt);
			break;
		case 1:
			velocityX += (1-pqrt);
			velocityY += pqrt;

			mrX = (1-pqrt);
			mrY = pqrt;

			break;
		case 2:
			velocityX -= pqrt;
			velocityY +=(1-pqrt);

			mrX =-pqrt;
			mrY =(1-pqrt);


			break;
		case 3:
			velocityX -= (1-pqrt);
			velocityY -= pqrt;

			mrX = -(1-pqrt);
			mrY = -pqrt;
			break;

}
}
/*incSpeed = nowTime - throttleTime;
if (incSpeed > 2) incSpeed = 2;*/


//}else{
// throttleTime = nowTime;

//}

//drag and resistance to velocity

if (velocityX >0.0){
	velocityX /= 1.05;
	if (velocityX >2.0 +mrX){
		velocityX = 2.0+mrX;
	}

}else if(velocityX <0.0){
	velocityX /= 1.05;
	if (velocityX <-2.0+mrX){
		velocityX = -2.0+mrX;
	}
}

//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY

if (velocityY >0.0){
	velocityY /= 1.05;
	if (velocityY >2.0+mrY){
		velocityY = 2.0+mrY;
	}

}else if (velocityY <0.0){
	velocityY /= 1.05;
	if (velocityY <-2.0+mrY){
		velocityY = -2.0+mrY;
	}
}

if (std::abs(velocityX) < 0.1){
	velocityX = 0;
}
if (std::abs(velocityY) < 0.1){
	velocityY = 0;
}

std::cout << "vX:" << velocityX << "vY:" << velocityY << std::endl;


pX = (velocityX * 0.05);
pY = (velocityY * 0.05);

	
}

double Rotcalc::getVelT(){
	return (std::abs(velocityY) + std::abs(velocityX));
}

Rotcalc::~Rotcalc(){
	
}
