#include "player.h"

#ifndef GAME_H
#define	GAME_H

class Game{
	private:
		long timeStored;
		long timeNew;
		bool quit;
		
		
	public:
		
		//double &ShipXPosAdd;
		Game();
		void drawBarrier(double sx, double sy, double ex, double ey);
		void PlayerShoot();
		void run(int argc, char **argv);
		void GameLoop();
		void Reshape(int w, int h);
		long getTime();	
		void setMyShipX(double myS);
		void checkColl(double xa, double ya);
		
	//	void setPlayerAdd(Player&);
		Player* getPlayer();
		//double getGShipXPosAddy();
		~Game();
	
	
};

#endif
