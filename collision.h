
#ifndef COLLISION_H
#define COLLISION_H

#include "header.h"
#include <iostream>

class Collision
{
 public:
  Collision();
  Collision(int x,int y, int w, int h);
  ~Collision();
  SDL_Rect GetRect() {return CollisionRect};
  void setRectangle(int x,int y, int w, int h);

 private:
  SDL_Rect CollisionRect;
};





#endif
