#include "header.h"



Environment:: Environment(int ScreenWidth, int ScreenHeight, float *passed_CameraX, float *passed_CameraY, CSDL_Setup* passed_csdl_setup, int *passed_BobPosX, int *passed_BobPosY)
{
  csdl_setup=passed_csdl_setup;
  CameraX=passed_CameraX;
  CameraY=passed_CameraY;
  BobPosX=passed_BobPosX;
  BobPosY=passed_BobPosY;
  for (int i=0; i<2; i++)
    {
      for (int j=0;j<2;j++)
        {
          grass[i][j] = new CSprite(csdl_setup->GetRenderer(),"images/background/grass.bmp", ScreenWidth*i, ScreenHeight*j, ScreenWidth, ScreenHeight,CameraX,CameraY);
        }
    }
  Mode=levelCreation;
  LoadFromFile();

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

  for (int i=0; i<2; i++)
    {
      for (int j=0;j<2;j++)
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

  for (int i=0; i<2; i++)
    {
      for (int j=0;j<2;j++)
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
  if (Mode==levelCreation)
  {
    //place
  if (csdl_setup->GetMainEvent()->type==SDL_KEYDOWN)
    {
      if(!OnePressed && place-> key.keysym.sym == SDLK_p)
        {

          fruit.push_back(new Objects(*BobPosX+120,*BobPosY+75,CameraX,CameraY,csdl_setup));
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
  //save
  if (csdl_setup->GetMainEvent()->type==SDL_KEYDOWN)
    {
      if(!OnePressed && place-> key.keysym.sym == SDLK_F11)
        {
          saveToFile();
          std::cout << "saved" << std::endl;
          OnePressed=true;

        }
    }
  if (csdl_setup->GetMainEvent()->type==SDL_KEYUP)
    {
      if(OnePressed && place-> key.keysym.sym == SDLK_F11)
        {
          OnePressed=false;
        }
    }
  }
  //mode change
  if (csdl_setup->GetMainEvent()->type==SDL_KEYDOWN)
    {
      if(!OnePressed && place-> key.keysym.sym == SDLK_F12)
        {
          if (Mode==levelCreation)
            {
              Mode=gamePlay;
              std::cout << "Level Creation: OFF" << std::endl;
            }
          else if (Mode==gamePlay)
            {
              std::cout << "Level Creation: ON" << std::endl;
              Mode=levelCreation;
            }
          OnePressed=true;

        }
    }
  if (csdl_setup->GetMainEvent()->type==SDL_KEYUP)
    {
      if(OnePressed && place-> key.keysym.sym == SDLK_F12)
        {
          OnePressed=false;
        }
    }

}
void Environment::saveToFile()
{
  std::ofstream LoadedFile;
  LoadedFile.open("maps/level01.txt");
  LoadedFile <<"___Begin Level___" <<std::endl;
      for (std::vector<Objects*>::iterator i=fruit.begin();i !=fruit.end();++i)
        {
          LoadedFile << "x: " <<(*i)->GetX() << " y: " <<(*i)->GetY() <<std::endl;
        }
      LoadedFile << "___END LEVEL___" <<std::endl;
    LoadedFile.close();
    std::cout <<"saved to file" <<std::endl;
}

void Environment::LoadFromFile()
{
  std::ifstream LoadedFile ("maps/level01.txt");

  std::string Line;

  enum ObjectType
  {
    TypeNone,
    TypeObj
  };
  int CurrentType=TypeNone;
  if (LoadedFile.is_open())
    {
      while ( LoadedFile.good())
        {
          std::getline(LoadedFile, Line);
          if (Line == "___Begin Level___")
            {
              CurrentType = TypeObj;
            }
          else if (Line== "___END LEVEL___")
            {
              CurrentType = TypeNone;
            }
          else
            {
              if (CurrentType==TypeObj)
                {
                  std::cout<< Line << std::endl;
                  std::istringstream iss(Line);
                  int tempX=0;
                  int tempY=0;
                  std::string previousWord="";
                  while (iss)
                    {
                      std::string word;
                      iss >> word;
                      std::cout << word << std::endl;
                      if (previousWord == "x:")
                        {
                          tempX=atoi (word.c_str());
                        }
                      if (previousWord == "y:")
                        {
                          tempY=atoi (word.c_str());
                          std::cout << "X is: " << tempX << std::endl;
                          std::cout << "Y is: " << tempY << std::endl;

                          fruit.push_back(new Objects(tempX,tempY,CameraX,CameraY,csdl_setup));

                        }
                      previousWord=word;
                    }
                }
            }
          // std:: cout <<Line <<std:: endl;
        }
    }
  else
    {
      std::cout <<"no file";
    }
}
