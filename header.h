#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#include <math.h>
#include <vector>

//header files
#include "CSDL_Setup.h"
#include "CSprite.h"
#include "Watashi.h"
#include "Environment.h"
#include "Objects.h"


//main class that initiates most thing
class CMain
{
 public:
  CMain(int passed_ScreenWidth, int passed_ScreenHeight);
  ~CMain(void);
  void GameLoop(); //main game loop

 private:
  //sets the width and Height of the screen
  float CameraX, CameraY;
  int ScreenWidth, ScreenHeight;

  bool quit; //checks if window was quit

  Watashi* bob; // main character pointer

  //environment

  Environment* Woods; //creates the map
  //uses the SDL library to set up things
  CSDL_Setup* csdl_setup; //sets up the sdl textures

  //
  int BobPosX, BobPosY;
  //

};



#endif
