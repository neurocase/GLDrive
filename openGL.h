
#ifndef OPEN_GL_H
#define	OPEN_GL_H

#ifdef __APPLE__

// include MACOS opengl header files
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#else

// include Linux opengl header files
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#endif


#endif