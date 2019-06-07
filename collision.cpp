#include "header.h"
#include "collision.h"

Collision::Collision()
{
  setRectangle(0,0,0,0);
}
Collision::Collision(int x,int y, int w, int h)
{
  setRectangle(x,y,w,h);

}
Collision::~Collision()
{
  
}

void Collision:: setRectangle(int x,int y, int w, int h)
{
  CollisionRect.x=x;
  CollisionRect.y=y;
  CollisionRect.w=w;
  CollisionRect.h=h;
} 
