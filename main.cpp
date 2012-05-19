// Gavin Whelan
// 5/16/12
// gavwhela@indiana.edu
// Fucking Around...

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#if defined (__APPLE__) || defined (MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "simpleParticle.h"

using namespace std;

// Modifiable Arguments
#define WINDOW_TITLE "Test Window"
#define MAX_PARTICLES 100000

int width = 0;
int height = 0;
int cursorX = 600;
int cursorY = 600;

Particle** particles;

void passive(int x, int y) {
  cursorX = x;
  cursorY = height - y - 1;
  glutPostRedisplay();
}
 
void reshape(int w, int h) {
  width = w;
  height = h;
  glViewport(0, 0, w-1, h-1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w-1, 0, h-1);
  glMatrixMode(GL_MODELVIEW);
  int i;
  for(i = 0; i < MAX_PARTICLES; i++) {
    Particle* p = particles[i];
    if(p != NULL){
      p->setWidth(w);
      p->setHeight(h);
    }
  }
  glutPostRedisplay();
}

void free_memory(void) {
  int i;
  for (i = 0; i < MAX_PARTICLES; i++)
    if(particles[i] != NULL)
      delete particles[i];
  free(particles);
}


void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 'q':
    free_memory();
    exit(EXIT_SUCCESS);
    break;
  }
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(2.0);
  glBegin(GL_POINTS);
  int i;
  for(i = 0; i < MAX_PARTICLES; i++){
    Particle* p = particles[i];
    if(p != NULL) {
      glColor3f(p->getRed(), p->getGreen(), p->getBlue());
      glVertex2i(p->getX(), p->getY());
    }
  } 
  glColor3f(1.0, 0.0, 0.0);
  glVertex2i(cursorX, cursorY);
  glEnd();
  glutSwapBuffers();
}

void idle(void) {
  int i;
  int added = 10;
  for(i = 0; i < MAX_PARTICLES; i++){
    Particle* p = particles[i];
    if(p == NULL && added){
      p = (Particle*) new SimpleParticle(cursorX, cursorY);
      particles[i] = p;
      added--; 
    }
    if(p != NULL){
      p->update();
      if(p->getY() < 0){
	delete p;
	particles[i] = NULL;
      }
    }
  }
  for(i = 0; i < 10000000; i++);
  glutPostRedisplay();
}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitWindowSize(1280, 800);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  int main_window = glutCreateWindow(WINDOW_TITLE);
  
  glutPassiveMotionFunc(passive);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
  glutReshapeFunc(reshape);

  glClearColor(0.0, 0.0, 0.0, 1.0);
  particles = (Particle **) calloc(MAX_PARTICLES, sizeof(Particle*));
  struct timeval *t = (timeval *) malloc(sizeof(struct timeval));;
  gettimeofday(t, NULL);

  srand((t->tv_sec * t->tv_usec) ^ getpid());

  glutMainLoop();
  
  return(EXIT_SUCCESS);
}

