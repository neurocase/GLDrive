#include "openGL.h"
#include "game.h"
#include "player.h"
#include "timer.h"

#include <unistd.h>

#include <iostream>



Game GameHeart;

void keyboard(unsigned char key, int x, int y)
{
	Player* Playr = GameHeart.getPlayer();
   switch (key) {
      case 27: exit(0); break;
      case 'a':
      Playr->setRotation(1);
      break;
      case 'd':
      Playr->setRotation(-1);
      break;
      case 's':
        if (Playr->isBrake() == 0)
		Playr->setBrake(1);
     // GameHeart.PlayerShoot();
      break;
       case 'w':
       if (Playr->isThrottle() == 0)
		Playr->setThrottle(1);
		
      break;
      
     // default: std::cout << "KEY DOWN = " << key << "\n"; break;
   } 
}

void keyboardUp(unsigned char key, int x, int y)
{
		Player* Playr = GameHeart.getPlayer();
   switch (key) {
      case 27: exit(0); break;
      case 'a':
      if  (Playr->getRotation() == 1)
      Playr->setRotation(0); //-1
      break;
      case 'd':
      if  (Playr->getRotation() == -1)
      Playr->setRotation(0); //1
      break;
      case 'w':
      if  (Playr->isThrottle() == 1)
      Playr->setThrottle(0); //1
      break;
      
  }
  // std::cout << "KEY UP = " << key << "\n";
}

void onKeyPress(unsigned char key, int x, int y) {
	//std::cout << "key : " << key << std::endl;
}

void onSpecialKeyPress(int key, int x, int y) {
}
void display() {
	GameHeart.GameLoop();
}

void reshape(int w, int h) {
	GameHeart.Reshape(w, h);
}
void init() // Called before main loop to set up the program
{
	double r = 70 / 256.0;
	double g = 70 / 256.0;
	double b = 70 / 256.0;
	

    glClearColor(r, g, b, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}
int main(int argc, char **argv){
 glutInit(&argc, argv); // Initializes glut

    // Sets up a double buffer with RGBA components and a depth component
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    // Sets the window size to 512*512 square pixels
    glutInitWindowSize(756, 756);

    // Sets the window position to the upper left
    glutInitWindowPosition(0, 0);

    // Creates a window using internal glut functionality
    glutCreateWindow("GL-Driving!");

    // passes reshape and display functions to the OpenGL machine for callback
    glutReshapeFunc(reshape);
    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
   // void glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));
	
	glutKeyboardFunc(onKeyPress);
	glutSpecialFunc(onSpecialKeyPress);
	
	glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
	
  //  glutKeyboardUpFunc(keyboard_up); 
    init();

    // Starts the program.
    glutMainLoop();

	return 0;
}
