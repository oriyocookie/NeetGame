//Watashi.h
#include <iostream>

class Watashi
{
 public:
  Watashi(CSDL_Setup* passedSDLSetup, float *CameraX, float *CameraY);
  ~Watashi();

  void Update();
  void Draw();
  void UpdateAnimation();
  void UpdateControls();
 private:


  float *CameraX;
  float *CameraY;
  CSprite* bob;

  CSDL_Setup* csdl_setup;

  bool  moveRight;
  bool  moveLeft;
  bool  moveUp;
  bool  moveDown;

  int timeTracker;
};
