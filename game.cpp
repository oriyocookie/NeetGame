//only the main header is needed
#include "header.h"

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
  ScreenWidth = passed_ScreenWidth;
  ScreenHeight = passed_ScreenHeight;
  quit = false;
  csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight);

  grass = new CSprite(csdl_setup->GetRenderer(),"images/background/grass.bmp", 0, 0, ScreenWidth, ScreenHeight);
  bob = new Watashi(csdl_setup); 
  // moveRight=false;
  // moveLeft=false;
  // moveUp=false;
  // moveDown=false;

  // timeTracker=SDL_GetTicks();
}
 
 
CMain::~CMain(void)
{
  delete csdl_setup;
  delete grass;
  delete bob;
}
 
void CMain::GameLoop(void)
{
  while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
    {
      csdl_setup->Begin();

      grass->Draw();


      bob -> Draw();
      bob -> Update();

      csdl_setup->End();
    }
}
