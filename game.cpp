//only the main header is needed
#include "header.h"

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
  CameraX=0.0f;
  CameraY=0.0f;

  ScreenWidth = passed_ScreenWidth;
  ScreenHeight = passed_ScreenHeight;
  quit = false;
  csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight);
  bob = new Watashi(csdl_setup,&CameraX,&CameraY);
  // moveRight=false;
  // moveLeft=false;
  // moveUp=false;
  // moveDown=false;
  Woods= new Environment(ScreenWidth,ScreenHeight,&CameraX,&CameraY, csdl_setup);
  // timeTracker=SDL_GetTicks();
}
 
 
CMain::~CMain(void)
{
  delete csdl_setup;

  delete bob;
}
 
void CMain::GameLoop(void)
{
  while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
    {
      csdl_setup->Begin();

      Woods->DrawBack();
    bob -> Draw();
    bob -> Update();
    Woods -> DrawFront();

    csdl_setup->End();
}
}
