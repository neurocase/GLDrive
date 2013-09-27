#ifndef ROTCALC_H
#define ROTCALC_H

class Rotcalc{

	private:
	
	double pX = 0;
	double pY = 0;
	double incSpeed = 0;

	double velocityX = 0;
	double velocityY = 0;

	double mrX;
	double mrY;
	
	public:
	
	Rotcalc();
	void calcPhys(double &rot, int r, double &pX, double &pY, int fuel);
	double getVelT();
	
	~Rotcalc();
	
	
	
};


#endif
