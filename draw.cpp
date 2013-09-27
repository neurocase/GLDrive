#include "openGL.h"
#include "game.h"
#include "draw.h"


#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <string>
#include <set>



const double PI = 3.141592653589793;


std::set<std::string> debug;

void PrintOnce(std::string key, std::string message) {
	if (debug.insert(key).second) {
	   std::cout << message << std::endl;
	}
}

Draw::Draw(){
}

/*
void Draw::DrawLaser(double laserX,double laserY){
	
 
	PrintOnce("laser", "LASER!");
	glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);  
				glVertex3f(laserX, laserY-0.2, -10.0);
        glVertex3f(laserX-0.03, laserY, -10.0);
        glVertex3f(laserX+0.03, laserY, -10.0);
	glEnd();
} */

void Draw::DrawLaser(double alX, double alY, double rot){
//const double PI = 3.141592653589793;

	//degdToRad
	//rot = rot * (PI/180);
	
	double alXt[3] = {-0.02, 0.02, 0};
	double alYt[3] = {0.1, 0.1, -0.1};
	double tmpalXt[3] = {alXt[0],alXt[1],alXt[2]};
	double tmpalYt[3] = {alYt[0],alYt[1],alYt[2]};
		
	for (int i = 0; i < 3; i++){
		alXt[i] = tmpalXt[i]*cos(rot)-tmpalYt[i]*sin(rot);
		alYt[i] = tmpalXt[i]*sin(rot)+tmpalYt[i]*cos(rot);
		
	}
	
	PrintOnce("Player", "Drawing Player");
	glColor3f(1,1,1);
	
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX+alXt[0], alY+alYt[0], -10.0); //point A
        glVertex3f(alX+alXt[1], alY+alYt[1], -10.0); //point B
        glVertex3f(alX+alXt[2], alY+alYt[2], -10.0); //point C
    
   /* for (int i = 0; i < 3; i++){
		alXt[i] += 0.1;
		alYt[i] =  0.1;
	}
    
    glBegin(GL_TRIANGLES);  
        glVertex3f(alX+alXt[0], alY+alYt[0], -10.0); //point A
        glVertex3f(alX+alXt[1], alY+alYt[1], -10.0); //point B
        glVertex3f(alX+alXt[2], alY+alYt[2], -10.0); //point C
    
    glEnd();*/
	
}

void Draw::DrawRTri(double alX, double alY, double c){
	
	
	if (c > 1){
		c = c -1;
	glColor3f(c,0,c/2);
	}
	if (c > 2){
		c = c -2;
		glColor3f(c/2,0,c);
	}
	if (c > 3){
		c = c -3;
		glColor3f(c,c/2,0);
	}
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.05, alY+0.05, -10.0);
        glVertex3f(alX, alY-0.05, -10.0);
        glVertex3f(alX+0.05, alY+0.05, -10.0);
    glEnd();
	
}

void Draw::DrawPlayer(double alX, double alY, double rot, double view, int throt){
//const double PI = 3.141592653589793;
view = 5;
view = std::abs(view);
glTranslated(-alX, -alY,  -10);
	//degdToRad
	//rot = rot * (PI/180);
	
	double alXt[3] = {-0.1, -0.1, 0.1};
	double alYt[3] = {-0.07, 0.07, 0};
	double tmpalXt[3] = {alXt[0],alXt[1],alXt[2]};
	double tmpalYt[3] = {alYt[0],alYt[1],alYt[2]};
		
	for (int i = 0; i < 3; i++){
		alXt[i] = tmpalXt[i]*cos(rot)-tmpalYt[i]*sin(rot);
		alYt[i] = tmpalXt[i]*sin(rot)+tmpalYt[i]*cos(rot);
		
	}
	
	PrintOnce("Player", "Drawing Player");
	glColor3f(1,1,1);
	
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX+alXt[0], alY+alYt[0], -10.0); //point A
        glVertex3f(alX+alXt[1], alY+alYt[1], -10.0); //point B
        glVertex3f(alX+alXt[2], alY+alYt[2], -10.0); //point C
    
   /* for (int i = 0; i < 3; i++){
		alXt[i] += 0.1;
		alYt[i] =  0.1;
	}
    
    glBegin(GL_TRIANGLES);  
        glVertex3f(alX+alXt[0], alY+alYt[0], -10.0); //point A
        glVertex3f(alX+alXt[1], alY+alYt[1], -10.0); //point B
        glVertex3f(alX+alXt[2], alY+alYt[2], -10.0); //point C
    
    glEnd();*/
	
}

Draw::~Draw()
{
	
}
