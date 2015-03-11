#include <string>  //Standard C string header
#include <vector>  //Advanced arrays
#include <math.h>  //Mathematical functions
#include <sstream> //Standard Stringstream header for advanced string manipulation
#include <cstdlib> //The C standard library
#include <iostream>//Standard C input/output
#include <fstream> //To allow for file reading/writing

//Various constants and definitions used for convenience purposes
#define NOTHING 0
#define PLANET 1
#define ASTEROID 2
#define IS_DESTROYED 1
#define IS_BROKEN_UP 2

//Function prototypes
void quitGame( int exitCode );
void addEvent( std::string message, int maxLife );

//If statement to account for headers named differently under Linux, at least on my system
#ifdef __linux__
    #include "SDL.h"       //The main framework for SDL
    #include "SDL_image.h" //Library to load and use images not in bitmap format
    #include "SDL_mixer.h" //Library to simplify handling of sound and music
#else
    #include "sdl.h"       //The main framework for SDL
    #include "sdl_image.h" //Library to load and use images not in bitmap format
    #include "sdl_mixer.h" //Library to simplify handling of sound and music
#endif

#include "SDL_ttf.h"       //Library for loading and using fonts
#include "SDL_rotozoom.h"  //3rd party library for image scaling - called sdl_gfx, available at http://www.ferzkopp.net

#include "globalVariables.h" //All global variables used in the program
#include "mathFunctions.h"   //Functions that are primarily mathematical in nature
#include "shipImage.h"       //Class for holding aspects of a ship's image
std::vector < shipImage > shipImages; //Vector that holds images for all different ship colors
#include "SDL_Functions.h"   //Functions to initialize SDL components, load files, and apply SDL surfaces to the screen

#include "object.h"      //Class for holding objects like planets, asteroids
#include "keymap.h"      //Class for holding mapping of individual keys, if player using keyboard
#include "bullet.h"      //Class for holding bullets
std::vector <bullet> bulletList; //Vector that holds the bullets
#include "particle.h"    //Class for holding particles
std::vector <particle> particleList;//Vector that holds all particles
#include "ship.h"        //Class for holding ships
#include "player.h"      //Class for holding individual player's information
std::vector <player> playerList; // Vector that holds all players, including ship info, controls, score, etc.
#include "turret.h"      //Class for holding turrets
#include "eventNotice.h" // Class for holding info to be displayed on the screen
std::vector <eventNotice> eventNoticeList;
#include "level.h"       //Class for holding information of current level - number of each type of object, settings for some objects, etc.
#include "world.h"       //Class for holding current configuration of game - difficulty, etc.
#include "addEvent.h"    //Routine to add an event notice to the event notice list

std::vector <spaceObject> objectList; //Vector that holds all the objects
std::vector <turret> turretList;      //Vector that holds all the turrets

world theWorld; //The world used throughout the program
level myLevel;  //The level used throughout the program

#include "cleanup.h"  //Clean up all files and close everything
#include "quitGame.h" //Used when abnormally exiting game

//Various function prototypes
void checkCollisions();
void objectListUpdate();
void bulletListUpdate();
void shipUpdate();
void particleListUpdate();
void removeAllDead();
void checkBounds();
void destroyShip( int playerNum );

#include "misc.h"
#include "update.h"
#include "objectCreators.h"
#include "applySurfaces.h"
#include "playGame.h"
#include "configureGame.h"
#include "configureSettings.h"
#include "configuration.h"
#include "mainMenu.h"
#include "titleScreen.h"

int main( int argc, char* args[] )
{
      srand(time(NULL));

      //initialize SDL components
      if ( !initialize() )
            quitGame( 50 );

      //load all images and other data files
      load_files();

      //Play title screen music if not already playing (repeated below in menu loop, but included here to get music playing ASAP on load
      checkMusic( false, 7, false );

      spotOnMainMenu = 0;

      //Create the level based on the difficulty of the level and overall difficulty
      createLevel( theWorld.currentLevelNumber, theWorld.overallDifficulty );

      //Create all of the objects, including ship
      createObjects();

      //This is the program loop
      runTitleScreen();

      //Clean up files
      clean_up();

      return 0;
}
