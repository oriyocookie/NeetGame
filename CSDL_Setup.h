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
  CSDL_Setup(bool* quit, int ScreenWidth, int ScreenHeight);
  ~CSDL_Setup(void);

  SDL_Renderer* GetRenderer();
  SDL_Event* GetMainEvent();

  void Begin();
  void End();
 private:

  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event* mainEvent;
 };

#endif
