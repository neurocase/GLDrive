#ifndef DRAW_H
#define DRAW_H

class Draw{
	
	public:
	enum Colour {RED, BLUE, GREEN, ORANGE, YELLOW, WHITE};
	Draw();
	void DrawBoundaries();
	void DrawPlayer(double myX, double, double, double);
	void DrawAlien(double alX, double alY, char c);
	void DrawAsteroid(double alX, double alY, double rot);
	void DrawLaser(double laserX,double laserY);
	void DrawCharge(double charge);
	void DrawLife(int life);
	void DrawAlLaser(double laserX,double laserY);
	void DrawRTri(double, double);
	void DrawExplosion(double alX, double alY, double incV);
	~Draw();
	
	private:
		
};


#endif 
