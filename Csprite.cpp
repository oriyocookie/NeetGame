#include "header.h"
#include <iostream>

CSprite::CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h)
{
  renderer = passed_renderer;
  image = NULL;
  image = IMG_LoadTexture(renderer,FilePath.c_str());
 
  if (image == NULL)
    {
      std::cout << "Couldn't Load " << FilePath.c_str() << std::endl;
    }

  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  SDL_QueryTexture(image,NULL,NULL,&img_width,&img_height);

  crop.x=0;
  crop.y=0;
  crop.w=img_width;
  crop.h=img_height;
  CurrentFrame=0;
  amountFrame=0;
} 
 
CSprite::~CSprite(void)
{
  SDL_DestroyTexture(image);
}
void CSprite::setUpAnimation(int passed_amountFrame)
{
  amountFrame=passed_amountFrame;
}
void CSprite::walkAnimation( int BeginFrame, int EndFrame, int Row, int Speed)
{
  if (animationDelay+Speed < SDL_GetTicks()){
  if (EndFrame< CurrentFrame)
    {
      CurrentFrame= BeginFrame;
    }
  else
    {
    CurrentFrame++;
  }
  crop.x=amountFrame* img_width/4;
  crop.y=CurrentFrame* img_width/4;
  crop.w=img_width/4;
  crop.h=img_height/4;

  animationDelay=SDL_GetTicks();
  }
}

void CSprite::Draw()
{
  SDL_RenderCopy(renderer,image, &crop, &rect);
}

void CSprite::setX(int X)
{
  rect.x= X;
}
void CSprite::setY(int Y)
{
  rect.y= Y;
}
void CSprite::SetPosition(int X,int Y)
{
  rect.x=X;
  rect.y=Y;
}


int CSprite::getX()
{
  return rect.x;
}
int CSprite::getY()
{
  return rect.y;
}
int CSprite::getWidth()
{
  return rect.w;
}
int CSprite:: getHeight()
{
  return rect.h;
}
void CSprite:: setWidth(int W)
{
  rect.w=W;
}
void CSprite:: setHeight(int H)
{
  rect.h=H;
}
