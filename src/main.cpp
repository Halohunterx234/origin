/* Headers */
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

/* Constants */
//Screen dimension constants
constexpr int kScreenWidth { 640 };
constexpr int kScreenHeight { 480 };

/* Function Prototypes */
//Starts up SDL and creates a window
bool init();

//Loads media;
bool loadMedia();

//Frees media and shuts down SDl
void close();

/* Global Variables */
//The window we will be rendering to
SDL_Window* gWindow{ nullptr };

//The surface contained by the window
SDL_Surface* gScreenSurface{ nullptr };

//The image we will load and show on the screen
SDL_Surface* gHelloWorld{ nullptr };

//Function Implementation
bool init() {
    //Initialization Flag
    bool success{ true };

    //Initialize SDL
    if( !SDL_Init( SDL_INIT_VIDEO )) {
        SDL_Log( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    } 

    else {
        //Create window
        if( gWindow = SDL_CreateWindow( "SDL3 Tutorial: Hello SDL3", kScreenWidth, kScreenHeight, 0); gWindow == nullptr ) {
            SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else{
            //Get window surfafce
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia() {
    //File loading flag
    bool success{ true };

    //Load splash image
    std::string imagePath{ "01-hello-sdl3/hello-sdl3.bmp "};
    if( gHelloWorld = SDL_LoadBMP( imagePath.c_str() ); gHelloWorld == nullptr) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    return success;
}

void close() {
    //Clean up surface
    SDL_DestroySurface( gHelloWorld );
    gHelloWorld = nullptr;

    //Destroy Window
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gScreenSurface = nullptr;

    //Quit SDL Subsystems
    SDL_Quit();
}

// main function
int main(int argc, char* args[]) {
    //Final exit code
    int exitCode{0};

    //Initialize
    if(!init()) {
        SDL_Log("Unable to initialize program! \n");
        exitCode = 1;
    }
    else {
        //Load media
        if(!loadMedia()) {
            SDL_Log("Unable to load media! \n ");
            exitCode = 2;
        }
        else {
            //The quit flag
            bool quit{false};

            //The event data
            SDL_Event e;
            memset(&e, 0, sizeof(e));

            //The main loop
            while (quit == false) {
                //Get event data
                while( SDL_PollEvent( &e )) {
                    //If event is quit type
                    if (e.type == SDL_EVENT_QUIT) {
                        //End the main loop
                        quit = true;
                    }
                }
                //Fill hte surface white
                SDL_FillSurfaceRect(gScreenSurface, nullptr, SDL_MapSurfaceRGB(gScreenSurface, 0xFF, 0xFF, 0xFF));

                //Render image on screen
                SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);

                //Update the surface
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }
    //Clean up
    close();

    return exitCode;
}