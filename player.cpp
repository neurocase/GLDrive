#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "player.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>

time_t dTime;

Player::Player(){	
	accel = 0;
	pRotation = 0;
	ShipXPos = 1;
	ShipYPos = 1;
	reloaded = true;
	brake = 0;
	hbrake = 0;

}


/*

double Player::getVelX(){
	return velocityX;
}
double Player::getVelY(){
	return velocityY;
}*/

bool Player::isBrake(){
	return brake;
}

void Player::setBrake(bool br){
	brake = br;
}
bool Player::isHBrake(){
	return hbrake;
}

void Player::setHBrake(bool hbr){
	hbrake = hbr;
}
void Player::setThrottle(bool ac){
	accel = ac;
}


void Player::setRotation (int d){
	pRotation = d;
}
int Player::getRotation (){
	return pRotation;
}

bool Player::isThrottle(){
	return accel;
}

void Player::setRot(double r){
	rot = r;
}

double Player::getRot(){
	return rot;
}

double Player::getXPos()
{
	return ShipXPos;
	
}

double Player::getYPos()
{
	return ShipYPos;
	
}

void Player::setXPos(double xPos)
{
	ShipXPos = xPos;
}

void Player::setYPos(double yPos)
{
	ShipYPos = yPos;
}

Player::~Player()
{	
}
