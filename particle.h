#ifndef __particle_h__
#define __particle_h__

class Particle {

public:
  virtual ~Particle();
  virtual void setWidth(int width) = 0;
  virtual void setHeight(int height) = 0;
  virtual void update(void) = 0;
  virtual int getX(void) = 0;
  virtual int getY(void) = 0;
  virtual double getRed(void) = 0;
  virtual double getGreen(void) = 0;
  virtual double getBlue(void) = 0;
} ;

#endif
