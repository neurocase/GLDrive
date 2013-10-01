#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "timer.h"
#include "player.h"
#include "rotcalc.h"

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


double pX = 0, pY = 0;
double velX = 0, velY = 0;

/*double pX = 0;
double pY = 0;
double incSpeed = 0;

double velocityX = 0;
double velocityY = 0;

double mrX;
double mrY;
// move this into player.cpp later
double rot = 0; */

Draw draweth;
Player Playr; 
Rotcalc rotcal;

Game::Game(){
}


Player* Game::getPlayer() {
	return &Playr;
}


void Game::run(int argc, char **argv){

}
void Game::Reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -float(h)/(10.0*float(w)), float(h)/(10.0*float(w)), 0.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Game::GameLoop(){

	if (startTime == 0){
		startTime = mytime.getTime();
	}

nowTime = mytime.getTime();
double delta = nowTime - previousTime;

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();

delta = delta * 10;
/*
*/
double rot = Playr.getRotation();
double rota = Playr.getRot();


rotcal.calcPhys(rota,rot, pX, pY,velX ,velY, Playr.isThrottle(),Playr.isBrake(),Playr.isHBrake());


//rot(active&direction), rotation(in degrees), playerX, playerY, fuel(active));




Playr.setXPos(pX);
Playr.setYPos(pY);
Playr.setRot(rota);


//double view = rotcal.getVelT();
//if (view > 2) view = 2;
//view *=2;
draweth.DrawPlayer(Playr.getXPos(),Playr.getYPos(),Playr.getRot(), 2, 0);


// just some hats to mark distance
for (double i = -25; i < 25; i+=1.3){
	double c = 0;
	
	for (double j = -25; j <25; j+=1.3){
		draweth.DrawRTri(i,j,c);
		c = c+ 0.1;
	}
	
}

previousTime = nowTime;
glutSwapBuffers();
}

Game::~Game()
{
}

