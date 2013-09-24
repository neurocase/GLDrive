#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "timer.h"
#include "player.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>

Timer mytime;

double previousTime = 0;
double startTime = 0;
double holdTime = 0;
double nowTime = 0;
double throttleTime = 0;
double deccelTime = 0;
double pX = 0;
double pY = 0;
double incSpeed = 0;

double velocityX = 0;
double velocityY = 0;

// move this into player.cpp later
double rot = 0;

Draw draweth;
Player Playr;


Game::Game()
{
}


Player* Game::getPlayer() {
	return &Playr;
}


void Game::run(int argc, char **argv)
{
	 
}
void Game::Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -float(h)/(10.0*float(w)), float(h)/(10.0*float(w)), 0.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Game::GameLoop()
{

	if (startTime == 0){
		startTime = mytime.getTime();
			
	}
	
	nowTime = mytime.getTime();
    double delta = nowTime - previousTime;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    delta = delta * 10;
	
	int r = Playr.getRotation();
	
	
	
	if (rot >= 360)
	{
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
	
	double qrot = (rot/360)*4;
	int qrt = (int)qrot;
	double pqrt = qrot - qrt;
	
	pX = 0;
	pY = 0;
	//velocityX = 0;
	//velocityY = 0;
	
	if (Playr.isThrottle() > 0){	
		
		switch(qrt){
			case 0:
				velocityX += pqrt;
				velocityY -= (1-pqrt);
			break;
			case 1:
				velocityX += (1-pqrt);
				velocityY += pqrt;	
			break;
			case 2:
				velocityX -= pqrt;
				velocityY +=(1-pqrt);
				
			break;
			case 3:
				velocityX -= (1-pqrt);
				velocityY -= pqrt;
			break;
			
		}
		
		/*incSpeed = nowTime - throttleTime;
		if (incSpeed > 2) incSpeed = 2;*/
		
		
	}else{
	//	throttleTime = nowTime;

	}
	
	//drag and resistance to velocity
	
	if (velocityX  >0.0){
			velocityX -= 0.1;
				if (velocityX  >2.0){
					velocityX = 2.0;
				}
				
	}else if(velocityX  <0.0){
			velocityX += 0.1;
				if (velocityX  <-2.0){
					velocityX = -2.0;
				}
	}
	
	//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
	
	if (velocityY  >0.0){
			velocityY -= 0.1;
				if (velocityY  >2.0){
					velocityY = 2.0;
				}
				
	}else if (velocityY  <0.0){
			velocityY += 0.1;
				if (velocityY  <-2.0){
					velocityY = -2.0;
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
	Playr.setXPos(pX);
	Playr.setYPos(pY);
	//std::cout << " rot:" << rot << " qrot:" << qrot << " qrt:" << qrt << " pqrt:" << pqrt << std::endl;
	//std::cout << "go?" << Playr.getAcceleration() << " px: " << pX << " pY:" << pY << "incSpeed:" << nowTime - throttleTime << std::endl;
	
	draweth.DrawPlayer(Playr.getXPos(),Playr.getYPos(),rot, 0);
	
	
	// just some hats to mark distance
	for (double i = -25; i < 25; i+=0.5)
	{
		draweth.DrawRTri(i,i);
	}
	
    previousTime = nowTime;
	glutSwapBuffers();
}

Game::~Game()
{
} 
