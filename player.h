#ifndef PLAYER_H
#define PLAYER_H


class Player{
	
	private:
	
	double ShipXPos;
	double ShipYPos;
	bool isAlive;
	int pHealth;
	bool reloaded;
	bool brake;
	bool hbrake;
	
	double laserPosX[4];
	double laserPosY[4];
	double mislPosX[4];
	double mislPosY[4];
	long timeNow;
	long timeLastShoot;
	int pRotation;
	

	// move this into player.cpp later
	
	double rot = 0;
	double accel;
	
	
	public:

	double getVelX();
	double getVelY();
	double getVelT();
	
	
	Player();
	void setRotation (int);
	int getRotation ();
	bool isThrottle();
	bool isBrake();
	void setBrake(bool);
	bool isHBrake();
	void setHBrake(bool);
	void setThrottle(bool);
	//void calcPhys();
	
	double getRot();
	double getXPos();
	double getYPos();
	void setXPos(double);
	void setYPos(double);
	void setRot(double);
	void killPlayer();
	void fireLaser();
	void fireMissle();
	bool isReloaded();
	//laserPos getLaserPos(int);
	//void setLaserPos(laserPos, int, char);
	
	
	~Player();
	
	
	
	
};



#endif
