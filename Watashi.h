#ifndef WATASHI_H
#define WATASHI_H

//Watashi.h
#include <iostream>

class Watashi
{
 public:
  Watashi(CSDL_Setup* passedSDLSetup, float *CameraX, float *CameraY, int *BobPosX, int *BobPosY);
  ~Watashi();

  void Update();
  void Draw();
  void UpdateAnimation();
  void UpdateControls();
 private:
  int *BobPosX;
  int *BobPosY;

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

#endif
