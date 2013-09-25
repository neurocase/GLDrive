#ifndef DRAW_H
#define DRAW_H

class Draw{
	
	public:
	enum Colour {RED, BLUE, GREEN, ORANGE, YELLOW, WHITE};
	Draw();
	void DrawBoundaries();
	void DrawPlayer(double myX, double, double, double, int throt);
	//void DrawAlien(double alX, double alY, char c);
	//void DrawAsteroid(double alX, double alY, double rot);
	void DrawLaser(double,double, double);
//	void DrawCharge(double charge);
//	void DrawLife(int life);
	void DrawRTri(double, double, double);
	void DrawExplosion(double alX, double alY, double incV);
	~Draw();
	
	private:
		
};


#endif 
