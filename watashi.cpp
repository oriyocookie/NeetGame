#include "header.h"


Watashi::Watashi(CSDL_Setup* passedSDLSetup, float *passed_CameraX, float *passed_CameraY,int* passed_BobPosX,int* passed_BobPosY)
{

  csdl_setup=passedSDLSetup;
  CameraX=passed_CameraX;
  CameraY=passed_CameraY;
  BobPosX=passed_BobPosX;
  BobPosY=passed_BobPosY;

  bob = new CSprite(csdl_setup->GetRenderer(),"images/character/bob.png", *BobPosX,*BobPosY, 64,64,CameraX,CameraY);
  bob -> setUpAnimation(0);
  moveLeft=false;
  moveRight=false;
  moveUp=false;
  moveDown=false;
  timeTracker=SDL_GetTicks();
}

Watashi::~Watashi()
{
  delete bob;
}

void Watashi:: Draw()
{
  bob -> Draw();

}
void Watashi::Update()
{
  UpdateAnimation();

  UpdateControls();

}

void Watashi::UpdateAnimation()
{


  bob->walkAnimation(0,0,0,250);
      switch (csdl_setup -> GetMainEvent()->type)
        {
        case SDL_KEYDOWN:
          switch(csdl_setup->GetMainEvent()-> key.keysym.sym)
            {
            case SDLK_a:
              bob -> setUpAnimation(1);
              moveLeft=true;
              break;
            case SDLK_s:
              bob -> setUpAnimation(0);
              moveDown=true;
              break;
            case SDLK_d:
              bob -> setUpAnimation(3);
              moveRight=true;
              break;
            case SDLK_w:
              bob-> setUpAnimation(2);
              moveUp=true;
              break;
            default:
              break;
            }

          break;
        case SDL_KEYUP:
          switch(csdl_setup->GetMainEvent()->key.keysym.sym)
            {

            case SDLK_a:
              moveLeft=false;
              break;
            case SDLK_s:
              moveDown=false;
              break;
            case SDLK_d:
              moveRight=false;
              break;
            case SDLK_w:
              moveUp=false;
              break;
            default:
              break;

            }
        default:
          break;
        }
      if (timeTracker+5 < SDL_GetTicks()){
      SDL_GetTicks();
      if (moveRight)
        {

          *BobPosX=*BobPosX+1;
          *CameraX=*CameraX-1.0f;
          bob -> setX(bob->getX() +1);
        }
      else if (moveLeft)
        {
          *BobPosX=*BobPosX-1;
          *CameraX=*CameraX+1.0f;
          bob->setX(bob-> getX() - 1);
        }
      else if (moveDown)
        {

          *BobPosY=*BobPosY+1;
          *CameraY=*CameraY-1.0f;
          bob -> setY(bob->getY() +1);
        }
      else if (moveUp)
        {

          *BobPosY=*BobPosY-1;
          *CameraY=*CameraY+1.0f;
          bob -> setY(bob->getY() -1);
        }
      timeTracker=SDL_GetTicks();
      }

}

void Watashi::UpdateControls()
{


}
