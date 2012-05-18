#ifndef __simpleParticle_h__
#define __simpleParticle_h__

#include <unistd.h>
#include <stdlib.h>
#include "particle.h"

using namespace std;

class SimpleParticle : public Particle{
public:
  SimpleParticle(int x, int y);
  void setWidth(int width);
  void setHeight(int height);
  void update(void);
  int getX(void);
  int getY(void);
private:
  int randnum(int min, int max);
  int x;
  int y;
  int vx;
  int vy;
  int ax;
  int ay;
} ;

#endif
