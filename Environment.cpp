#include "header.h"



Environment:: Environment(int ScreenWidth, int ScreenHeight, float *passed_CameraX, float *passed_CameraY, CSDL_Setup* passed_csdl_setup, int *passed_BobPosX, int *passed_BobPosY)
{
  csdl_setup=passed_csdl_setup;
  CameraX=passed_CameraX;
  CameraY=passed_CameraY;
  BobPosX=passed_BobPosX;
  BobPosY=passed_BobPosY;
  for (int i=0; i<4; i++)
    {
      for (int j=0;j<7;j++)
        {
          grass[i][j] = new CSprite(csdl_setup->GetRenderer(),"images/background/grass.bmp", ScreenWidth*i, ScreenHeight*j, ScreenWidth, ScreenHeight,CameraX,CameraY);
        }
    }
  OnePressed=false;
  place=csdl_setup->GetMainEvent();

  // for (int i=0; i <10; i++)
  //   {
  //     fruit.push_back(new Objects(300+(50*i),300,CameraX,CameraY,csdl_setup));
  // // fruit= new Objects(300,300,CameraX,CameraY,csdl_setup);
  //   }
}

Environment::~Environment()
{

  for (int i=0; i<4; i++)
    {
      for (int j=0;j<7;j++)
        {
          delete grass[i][j];
        }
    }

  for (std::vector<Objects*>::iterator i=fruit.begin();i !=fruit.end();++i)
    {
      delete (*i);
    }
  fruit.clear();
}

void Environment::DrawBack()
{

  for (int i=0; i<4; i++)
    {
      for (int j=0;j<7;j++)
        {
          grass[i][j] -> Draw();
        }
    }
  // for (std::vector<Objects*>::iterator i=fruit.begin();i !=fruit.end();++i)
  //   {
  //     (*i) -> DrawFruit();
  //   }
}
void Environment::DrawFront()
{

  for (std::vector<Objects*>::iterator i=fruit.begin();i !=fruit.end();++i)
    {
      (*i) -> DrawBook();
    }
}
void Environment::Update()
{
  if (csdl_setup->GetMainEvent()->type==SDL_KEYDOWN)
    {
      if(!OnePressed && place-> key.keysym.sym == SDLK_p)
        {

          fruit.push_back(new Objects(*BobPosX+120,*BobPosY+75,CameraX,CameraY,csdl_setup));
          std::cout << "One";
          OnePressed=true;

        }
    }
  if (csdl_setup->GetMainEvent()->type==SDL_KEYUP)
    {
      if(OnePressed && place-> key.keysym.sym == SDLK_p)
        {
          OnePressed=false;
        }
    }

}
