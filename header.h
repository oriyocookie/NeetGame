//header things that are needed so the includes are nnot used multiple times
#ifndef NEET_GAME
#define NEET_GAME
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <math.h>
#include "CSDL_Setup.h"
#include "CSprite.h"
#include "Watashi.h"
#include "Environment.h"



//main class that initiates most thing
class CMain
{
 public:
  CMain(int passed_ScreenWidth, int passed_ScreenHeight);
  ~CMain(void);
  void GameLoop();

 private:
  //sets the width and Height of the screen
  float CameraX;
  float CameraY;
  int ScreenWidth;
  int ScreenHeight;

  bool quit;
  //sprites that are pointer
  Watashi* bob;

  //environment

  Environment* Woods;
  //uses the SDL library to set up things
  CSDL_Setup* csdl_setup;

};



#endif
