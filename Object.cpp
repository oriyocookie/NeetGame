#include "header.h"
#include <iostream>

Objects::Objects(int x, int y,float *CameraX, float *CameraY, CSDL_Setup *csdl_setup)
{

  Fruit = new CSprite(csdl_setup->GetRenderer(),"images/Objects/split/tile002.png", x-50,y-100, 32,32,CameraX,CameraY);

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
