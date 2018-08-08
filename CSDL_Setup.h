#ifndef CSDL_SETUP
#define CSDL_SETUP


#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>

//SDL Setup
class CSDL_Setup
{
 public:
  CSDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight); //sets up the CSDL
  ~CSDL_Setup(void); 

  SDL_Renderer* GetRenderer(); //gets the renderer
  SDL_Event* GetMainEvent(); //gets event like key presses

  void Begin();
  void End();
 private:

  SDL_Window* window;  //the window
  SDL_Renderer* renderer; //graphics
  SDL_Event* mainEvent; //events
 };

#endif
