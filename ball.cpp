#include "ball.h"

// Sets up a constructor that takes in parameters to set up the properties of a ball
Ball::Ball(SDL_Surface* bmp, int x, int y, int width, int height, int xSpeed, int ySpeed)
{
    picture = bmp;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}

// The deconstructor will remove the memory that holds the picture
Ball::~Ball()
{
    SDL_FreeSurface(picture);
}

// Puts the picture on the rectangle
void Ball::display()
{
    SDL_BlitSurface(picture, NULL, SDL_GetVideoSurface(), &rect);
}

// Movement and collision detection, checks also to see if the ball is
// within the max/min screen bounds
void Ball::movement()
{
    rect.x += xSpeed;
    rect.y += ySpeed;
}

bool Ball::collided(SDL_Rect* firstRect, SDL_Rect* secondRect)
{
    if(firstRect->y >= secondRect->y + secondRect->h)
    {
        return 0;
    }

    if(firstRect->x >= secondRect->x + secondRect->w)
    {
        return 0;
    }

    if(firstRect->y + firstRect->h <= secondRect->y)
    {
        return 0;
    }

    if(firstRect->x + firstRect->w <= secondRect->x)
    {
        return 0;
    }

    return 1;
}
