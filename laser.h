#ifndef LASER_H
#define LASER_H

class Laser{
	
	private:
	double lx;
	double ly;
	
	public:
	
	//enum colour {RED, BLUE, CYAN, GREEN, ORANGE, YELLOW, WHITE};
	//IMPLIMENT LATER
	
	Laser();
	Laser(double shooterXPos, double shooterYPOS, double direction);
	bool isGoUp;
	
	void getXY(double &x, double &y);
	void setXY(double x, double y);
	
	bool isActive;
	~Laser();
};

#endif
