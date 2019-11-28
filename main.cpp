/*
#include <iostream>
#include <SDL.h>
int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768,
                                          SDL_WINDOW_FULLSCREEN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_Quit();
}

/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
/*
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 10000 );
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}*/

///THE HEADER FILES
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_mixer.h>
#include <string>

#include "heli.h"
#include "loader.h"
#include "timer.h"
#include "window.h"
#include "obstacles.h"
#include "game_functions.h"
#include "play.h"

int main(int argc, char* args[])
{
    bool cont=true;
    //Initialize
    if( init() == false )
    {
        return 1;
    }

    Window my;
    my.toggle_fullscreen();
    wel_come();     ///WELCOME SCREEN FUNCTION CALL
    int opt;
    while(cont)
    {
        opt=game_menu();        ///GAME MENU FUNCTION CALL
        switch(opt)
        {
            case 1:
                play();         ///GAME LOOP
                break;
            case 2:
                ///OPTIONS
                break;
            case 3:
                ///HIGHSCORES
                break;
            case 4:
                ///INSTRUCTIONS
                break;
            case 5:
                ///CREDITS
                break;
            case 6:
                ///QUIT FROM PROGRAM
                cont=false;
                break;
            default:
                break;

        }
    }

    clean_up();         ///FREES THE MEMORY
    return 0;
}
