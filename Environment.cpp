#include "header.h"



Environment:: Environment(int ScreenWidth, int ScreenHeight, float *passed_CameraX, float *passed_CameraY, CSDL_Setup* passed_csdl_setup, int *passed_BobPosX, int *passed_BobPosY)
{
  csdl_setup=passed_csdl_setup; //sets up the csdl with the passed values
  CameraX=passed_CameraX; //gets camera values, however this is not being used right now
  CameraY=passed_CameraY;
  BobPosX=passed_BobPosX; //gets the value of the main character's position
  BobPosY=passed_BobPosY;
  for (int i=0; i<2; i++) //for loop that prints the grass background
    {
      for (int j=0;j<2;j++)
        {
          grass[i][j] = new CSprite(csdl_setup->GetRenderer(),"images/background/grass.bmp", ScreenWidth*i, ScreenHeight*j, ScreenWidth, ScreenHeight,CameraX,CameraY);
        }
    }
  Mode=levelCreation; //the mode that the game is in
  LoadFromFile();  //loads from the file to create map at the start

  OnePressed=false; //makes sure the key is pressed once when held
  place=csdl_setup->GetMainEvent(); //places the object in the map

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

  for (std::vector<Objects*>::iterator i=fruit.begin();i !=fruit.end();++i) //deletes all fruit objects
    {
      delete (*i);
    }
  fruit.clear();
}

void Environment::DrawBack()
{

  for (int i=0; i<2; i++) //draws grass at the back
    {
      for (int j=0;j<2;j++)
        {
          grass[i][j] -> Draw();
        }
    }
}
void Environment::DrawFront()
{

  for (std::vector<Objects*>::iterator i=fruit.begin();i !=fruit.end();++i) //draws at the front
    {
      (*i) -> DrawBook();
    }
}
void Environment::Update()
{
  if (Mode==levelCreation) //if mode creation you can place objects on the map
  {
    //place
  if (csdl_setup->GetMainEvent()->type==SDL_KEYDOWN)
    {
      if(!OnePressed && place-> key.keysym.sym == SDLK_p)
        {

          fruit.push_back(new Objects(*BobPosX+120,*BobPosY+75,CameraX,CameraY,csdl_setup)); //pushes fruit in the stack
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
      if(!OnePressed && place-> key.keysym.sym == SDLK_F11) //if f11 is pressed saves to a file
        {
          saveToFile(); //saves to file
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
  std::ofstream LoadedFile; //writes to a text file
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
  std::ifstream LoadedFile ("maps/level01.txt"); //reads from the file

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
                  std::istringstream iss(Line);
                  int tempX=0;
                  int tempY=0;
                  std::string previousWord="";
                  while (iss)
                    {
                      std::string word;
                      iss >> word;
                      if (previousWord == "x:")
                        {
                          tempX=atoi (word.c_str());
                        }
                      if (previousWord == "y:")
                        {
                          tempY=atoi (word.c_str());

                          fruit.push_back(new Objects(tempX,tempY,CameraX,CameraY,csdl_setup));

                        }
                      previousWord=word;
                    }
                }
            }
        }
    }
  else
    {
      std::cout <<"no file";
    }
}
