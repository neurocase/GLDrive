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


double pX = 1, pY = 1;
double h_pX = pX;
double h_pY = pY;
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

double col = 0;
	

Draw draweth;
Player Playr; 
Rotcalc rotcal;

Game::Game(){
}


Player* Game::getPlayer() {
	return &Playr;
}

void Game::drawBarrier(double sx, double sy, double ex, double ey){
	int t = 0;
	int drawtimes = 0;
	double xt = ex - sx;
	double yt = ey - sy;
	
	if (xt > yt){
		drawtimes = std::abs(xt) * 5;
	}else{
		drawtimes = std::abs(yt) * 5;
	}
	
	
	while (t < drawtimes){
	
	if (sx < ex){
		sx += 0.2;
	}
	if(sy < ey){
		sy +=0.2;
	}
	if (sx > ex){
		sx -= 0.2;
	}
	if(sy > ey){
		sy -=0.2;
	}
	
	draweth.DrawRTri(sx,sy,col);
	checkColl(sx,sy);	
	t++;	
	}
}


void Game::checkColl(double xa, double ya){

if ((std::abs(xa - pX) < 0.1) && (std::abs(ya - pY) < 0.1)){
		pX = h_pX;
		pY = h_pY;
	}
	
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

double rot = Playr.getRotation();
double rota = Playr.getRot();


//hold value of pX, pY, prior to acceleration 
h_pX = pX;
h_pY = pY;

rotcal.calcPhys(rota,rot, pX, pY,velX ,velY, Playr.isThrottle(),Playr.isBrake(),Playr.isHBrake());


//rot(active&direction), rotation(in degrees), playerX, playerY, fuel(active));




Playr.setXPos(pX);
Playr.setYPos(pY);
Playr.setRot(rota);


double view = rotcal.getVelT();
if (view < 4.5) view = 4.5;
view *=2;
if (view > 15) view = 15;
draweth.DrawPlayer(Playr.getXPos(),Playr.getYPos(),Playr.getRot(), view, 0);


// DRAWING THE TRACK



std::cout << " pX:" << pX <<  " pY:" << pY << std::endl;
draweth.DrawRTri(2,2,0);
		checkColl(2,2);

drawBarrier(0,2,18,2);		
drawBarrier(0,0,20,0);

drawBarrier(18,2,18,14);		
drawBarrier(20,0,20,12);

drawBarrier(18,14,22,14);
drawBarrier(22,6,22,14);


drawBarrier(22,6,30,6);
drawBarrier(20,4,28,4);

drawBarrier(30,-2,30,6);

drawBarrier(28,6,30,6);

drawBarrier(26,-2,26,4);

drawBarrier(30,6,26,6);


drawBarrier(28,2,30,2);

drawBarrier(26,0,28,0);

drawBarrier(28,-2,30,-2);



drawBarrier(28,-4,28,-2);


drawBarrier(20,-2,26,-2);
drawBarrier(20,-4,28,-4);


previousTime = nowTime;
glutSwapBuffers();
}
/*
for (double i = -1; i < 18; i+=0.2){
		double j = -1;
				
		
		if (i < 16){
		draweth.DrawRTri(i,j+2,0);
		checkColl(i,j+2);
		}
		draweth.DrawRTri(i,j,0);
		checkColl(i,j);		
}*/
//for (double j = -1; j < 9.2; j+=0.2){
/*	double i = 16;
	//for (double j = -25; j <25; j+=2){
		double j = -1;
		while (j < 9){	
			if (j > 1){
			draweth.DrawRTri(i,j,0);
			checkColl(i,j);	
			}
			if (j < 7){
			draweth.DrawRTri(i+2,j,0);
			checkColl(i+2,j);
			}
			j+=0.2;
		}
		if (j == 9){
			while (i < 20){	
				draweth.DrawRTri(i,j,0);
				checkColl(i,j);
				i += 0.2;
			}
			while (j > 4){
				j -= 0.2;
				draweth.DrawRTri(i,j,0);
				checkColl(i,j);
			}
			while(i < 28){
				i+=0.2;
				draweth.DrawRTri(i,j,0);
				checkColl(i,j);
				draweth.DrawRTri(i-2,j-2,0);
				checkColl(i-2,j-2);
			}
			
		//	j = 9;
		//}*/
		



Game::~Game()
{
}

