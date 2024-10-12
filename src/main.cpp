#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]){
    // Main window
    SDL_Window* window = NULL;

    //Surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    //On error
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initalize! SDL_Error: %s\n", SDL_GetError() );
    }
    else {
        //Create a window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if ( window == NULL )
        {
            printf( "SDL could not initalize! SDL_Error: %s\n", SDL_GetError() );
        }
    }
}

