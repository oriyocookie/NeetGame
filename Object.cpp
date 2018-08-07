#include "header.h"
#include <iostream>

Objects::Objects(int x_passed, int y_passed,float *CameraX, float *CameraY, CSDL_Setup *csdl_setup)
{
  x=x_passed;
  y=y_passed;

  Fruit = new CSprite(csdl_setup->GetRenderer(),"images/Objects/split/tile002.png", x,y, 32,32,CameraX,CameraY);

  Book = new CSprite(csdl_setup->GetRenderer(),"images/Objects/split/poop.png", x-100,y-50, 32,32,CameraX,CameraY);

}

Objects::~Objects()
{
  delete Fruit;
  delete Book;
}

void Objects::DrawFruit()
{
  Fruit -> Draw();
}
void Objects::DrawBook()
{
  Book -> Draw();
}
int Objects:: GetX()
{
  return x;
}
int Objects:: GetY()
{
  return y;
}
