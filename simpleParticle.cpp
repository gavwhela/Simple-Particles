#include "simpleParticle.h"

using namespace std;

SimpleParticle::SimpleParticle(int x, int y) {
  this->x  = (double)x;
  this->y  = (double)y;
  this->vx = randnum(-50, 51) * .1;
  this->vy = randnum(-60, 101) * .1;
  this->ax = 0;
  this->ay = -.5; 
  this->red = 1.0;
  this->green = 1.0;
  this->blue = 1.0;
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
  if(this->y < 0) {
    this->y = 0;
    if(this->vx < 0)
      this->vx += 1;
    else if(this->vx > 0)
      this->vx -=1;
  }
  this->blue -= .04;
  if(this->blue <= 0.0) {
    this->blue = 0.0;
    this->green -= .05;
    if(this->green <= 0.0) {
      this->green = 0.0;
      this->red -= .05;
    }
  }

}

int SimpleParticle::getX(void) {
  return (int)this->x;
}

int SimpleParticle::getY(void) {
  return (int)this->y;
}

int SimpleParticle::randnum(int min, int max) {
  int j = min + (int)((max-min) * (rand() / (RAND_MAX + 1.0)));
  return j;
}

double SimpleParticle::getRed(void) {
  return this->red;
}

double SimpleParticle::getGreen(void) {
  return this->green;
}

double SimpleParticle::getBlue(void) {
  return this->blue;
}

int SimpleParticle::freeable(void) {
  return (this->red <= 0.0) && (this->green <= 0.0) && (this->blue <= 0.0); 
}
