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

void Player::setThrottle(bool ac){
	accel = ac;
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
	ShipXPos = ShipXPos + xPos;
}

void Player::setYPos(double yPos)
{
	ShipYPos = ShipYPos + yPos;
}

Player::~Player()
{	
}
