#ifndef PLAYER_H
#define PLAYER_H


class Player{
	
	private:
	
	double ShipXPos;
	double ShipYPos;
	bool isAlive;
	int pHealth;
	bool reloaded;
	double laserPosX[4];
	double laserPosY[4];
	double mislPosX[4];
	double mislPosY[4];
	long timeNow;
	long timeLastShoot;
	int pRotation;
	
	
	double accel;
	
	
	public:

	
	Player();
	void setRotation (int);
	int getRotation ();
	bool isThrottle();
	void setThrottle(bool);
	
	
	double getXPos();
	double getYPos();
	void setXPos(double);
	void setYPos(double);
	void killPlayer();
	void fireLaser();
	void fireMissle();
	bool isReloaded();
	//laserPos getLaserPos(int);
	//void setLaserPos(laserPos, int, char);
	
	
	~Player();
	
	
	
	
};



#endif
