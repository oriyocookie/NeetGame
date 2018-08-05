
#include <iostream>
//environment
class Environment
{
 public:
  Environment(int ScreenWidth, int ScreenHeight, float *CameraX, float *CameraY, CSDL_Setup* csdl_setup);
  ~Environment();
  void DrawBack();
  void DrawFront();
 private:

  CSprite* grass[4][7];
};
