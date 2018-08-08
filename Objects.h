#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include "CSprite.h"


class Objects
{
 public:
  Objects(int x,int y, float *CameraX, float *CameraY, CSDL_Setup *csdl_setup);
  ~Objects();

  void DrawFruit();
  void DrawBook();

  int GetX();
  int GetY();
 private:
  int x,y;

  CSprite *Fruit, *Book;
};






#endif
