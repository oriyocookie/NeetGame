#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
//Csprite
class CSprite
{
 public:
  CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, float *CameraX, float *CameraY);
  ~CSprite(void);

  void Draw();
  void setX(int X);
  void setY(int Y);
  void SetPosition(int X,int Y); //move Character X

  int getX();
  int getY();
  void setHeight(int H);
  void setWidth(int W);
  int getWidth();
  int getHeight();

  void walkAnimation(int BeginFrame, int EndFrame, int Row, int Speed);
  void setUpAnimation(int passed_amountFrame);
 private:

  SDL_Rect Camera;
  float *CameraX, *CameraY;


  SDL_Texture* image; //image texture
  SDL_Rect rect, crop; //x,y,w,h values for the image and for cropping the image
  int img_width, img_height; //image size 

  int CurrentFrame, animationDelay, amountFrame; //functions for walking

  SDL_Renderer* renderer;

};

#endif
