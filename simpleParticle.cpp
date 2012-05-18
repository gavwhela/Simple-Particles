#include "simpleParticle.h"

using namespace std;

SimpleParticle::SimpleParticle(int x, int y) {
  this->x  = x;
  this->y  = y;
  this->vx = randnum(-6, 7);
  this->vy = randnum(-6, 14);
  this->ax = 0;
  this->ay = -1; 
}

void SimpleParticle::setWidth(int width) {
  
}

void SimpleParticle::setHeight(int height) {
  
}

void SimpleParticle::update(void) {
  this->x  += this->vx;
  this->y  += this->vy;
  this->vx += this->ax;
  this->vy += this->ay;
  if(this->y < 0)
    this->y = 0;
  if(this->vy <= -200)
    this->y = -1;
}

int SimpleParticle::getX(void) {
  return this->x;
}

int SimpleParticle::getY(void) {
  return this->y;
}

int SimpleParticle::randnum(int min, int max) {
  int j = min + (int)((max-min) * (rand() / (RAND_MAX + 1.0)));
  return j;
}
