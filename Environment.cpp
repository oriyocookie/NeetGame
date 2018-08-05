#include "header.h"



Environment:: Environment(int ScreenWidth, int ScreenHeight, float *CameraX, float *CameraY, CSDL_Setup* csdl_setup)
{

  for (int i=0; i<4; i++)
    {
      for (int j=0;j<7;j++)
        {
          grass[i][j] = new CSprite(csdl_setup->GetRenderer(),"images/background/grass.bmp", ScreenWidth*i, ScreenHeight*j, ScreenWidth, ScreenHeight,CameraX,CameraY);
        }
    }

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
}
void Environment::DrawFront()
{
  
}
