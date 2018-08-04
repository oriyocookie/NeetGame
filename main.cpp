//main file
#include "header.h"

int main (int argc, char* argv[])
{

  CMain* runGame=new CMain(600,500);
  runGame-> GameLoop();
  delete runGame;
  return 0;

}
