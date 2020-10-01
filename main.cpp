#include <SDL/SDL.h>
#include <iostream>

#include "ball.h"
#include "paddle.h"

// Loads an image and is used in the constructor for the ball and paddle
SDL_Surface* load_picture(const char* fileName, Uint32 colorKey = 0)
{
    // Creates the image
    SDL_Surface* surfaceImage = SDL_LoadBMP(fileName);

    // If the color key is not the default parameter then color key the image
    if (colorKey != 0)
    {
        SDL_SetColorKey(surfaceImage, SDL_SRCCOLORKEY, colorKey);
    }

    // Return the image
    return surfaceImage;
}

int main( int argc, char *argv[] )
{
    // Create a screen
    SDL_Surface* screen;

    const int screenWidth = 640;
    const int screenHeight = 480;

    const int FPS = 30;

    screen = SDL_SetVideoMode(screenWidth, screenHeight, 32, SDL_SWSURFACE);

    // Keyboard checks
    SDL_Event event;

    // Regulates FPS i.e. makes it smooth
    Uint32 start;
    // Starts the game
    bool running = true;

    // Create paddle and ball, max velocity is 3
    Paddle firstPlayer(load_picture("paddle.bmp"), 0, 225, 10, 50, 3);
    Paddle secondPlayer(load_picture("paddle.bmp"), screenWidth - 10, 225, 10, 50, 3);

    // Color key to make the background of the image transparent
    Ball ball(load_picture("ball.bmp", SDL_MapRGB(screen->format, 0x00, 0xff, 0xff)), 320, 240, 20, 20, 1, 1);

    const Uint8* state = SDL_GetKeyState(NULL);

    while(running)
    {
        // Number of milliseconds since SDL started
        start = SDL_GetTicks();
        // HANDLE EVENTS
        while(SDL_PollEvent(&event))
        {
            // Checks a variety of types
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }

        // LOGIC

        if (state[SDLK_w])
        {
            firstPlayer.moveDown();
        }
        if (state[SDLK_s])
        {
            firstPlayer.moveUp();
        }
        if (state[SDLK_UP])
        {
            secondPlayer.moveDown();
        }
        if (state[SDLK_DOWN])
        {
            secondPlayer.moveUp();
        }

        ball.movement();

        // RENDER or draw everything; clip_rect represents entire screen
        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));

        firstPlayer.display();
        secondPlayer.display();
        ball.display();

        SDL_Flip(screen);

        // Regulate the FPS, if this loop finishes in less than 1000 / FPS, then
        // wait for the reminder of that time e.g. loop finishes in 10 ms, wait 23.333...
        if(1000 / FPS > (SDL_GetTicks() - start))
        {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
        }
    }

    SDL_Quit();
}
