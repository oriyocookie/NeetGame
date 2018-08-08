//only the main header is needed
#include "header.h"

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
  CameraX=0.0f;
  CameraY=0.0f;
  //
  BobPosX=256;
  BobPosY=256;
  //
  ScreenWidth = passed_ScreenWidth;
  ScreenHeight = passed_ScreenHeight;
  quit = false;
  csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight); //create sprites and everything
  bob = new Watashi(csdl_setup,&CameraX,&CameraY,&BobPosX,&BobPosY); //creates the main character
  Woods= new Environment(ScreenWidth,ScreenHeight,&CameraX,&CameraY, csdl_setup,&BobPosX,&BobPosY); //creates environment using passed values
}
 
 
CMain::~CMain(void)
{
  delete csdl_setup;
  delete Woods;
  delete bob;
}
 
void CMain::GameLoop(void)
{
  while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
    {
      csdl_setup->Begin(); //starts renderer

      Woods->DrawBack(); //draws back of woods
      bob -> Draw(); //draws the main character
      bob -> Update(); //updates him 
      Woods->Update(); //updates the environment
      Woods -> DrawFront(); //draws the front part of the woods

      csdl_setup->End(); //ends the renderer
}
}
