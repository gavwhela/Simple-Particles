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
  double getRed(void);
  double getGreen(void);
  double getBlue(void);
  int freeable(void);
private:
  int randnum(int min, int max);
  double x;
  double y;
  double vx;
  double vy;
  double ax;
  double ay;
  double red;
  double green;
  double blue;
} ;

#endif
