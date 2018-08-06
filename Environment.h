#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include "header.h"
#include "Objects.h"
#include <vector>

//environment
class Environment
{
 public:
  Environment(int ScreenWidth, int ScreenHeight, float *CameraX, float *CameraY, CSDL_Setup* csdl_setup, int *BobPosX, int *BobPosY);
  ~Environment();
  void DrawBack();
  void DrawFront();

  void Update();
 private:
  int *BobPosX;
  int *BobPosY;
  CSDL_Setup* csdl_setup;
  float* CameraX;
  float* CameraY;
  bool OnePressed;
  SDL_Event* place;
  CSprite* grass[4][7];
  std::vector<Objects*> fruit;
};


#endif
