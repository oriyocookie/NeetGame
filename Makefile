#OBJS specifies which files to compile as part of the project
OBJS = main.cpp game.cpp CSDL_Setup.cpp Csprite.cpp watashi.cpp Environment.cpp Object.cpp
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w  #-flto 

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image #-lSDL2_tff


#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = run

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
