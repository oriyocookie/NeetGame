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
 private:

  int *BobPosX, *BobPosY;
  int timeTracker;

  float *CameraX,*CameraY;
  CSprite* bob;

  CSDL_Setup* csdl_setup;

  bool  moveRight, moveLeft, moveUp, moveDown;

};

#endif
