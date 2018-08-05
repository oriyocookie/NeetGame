//main file
#include "header.h"

int main (int argc, char* argv[])
{

  CMain* runGame=new CMain(640,510);
  runGame-> GameLoop();
  delete runGame;
  return 0;

}
