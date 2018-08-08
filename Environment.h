#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include "header.h"
#include "Objects.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
//environment
class Environment
{
 public:
  Environment(int ScreenWidth, int ScreenHeight, float *CameraX, float *CameraY, CSDL_Setup* csdl_setup, int *BobPosX, int *BobPosY);
  ~Environment();
  void DrawBack();
  void DrawFront();

  void Update();
  void LoadFromFile();
  void saveToFile();
  enum ModeType
  {
    gamePlay,
    levelCreation
  };

 private:

  int Mode;

  int *BobPosX,*BobPosY;
  CSDL_Setup* csdl_setup;
  float* CameraX, *CameraY;
  bool OnePressed;
  SDL_Event* place;
  CSprite* grass[2][2];

  std::vector<Objects*> fruit;
};


#endif
