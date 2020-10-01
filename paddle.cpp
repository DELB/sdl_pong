#include "paddle.h"

Paddle::Paddle(SDL_Surface* bmp, int x, int y, int width, int height, int ySpeed)
{
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

    picture = bmp;
    paddleSpeed = ySpeed;
}

Paddle::~Paddle()
{
    SDL_FreeSurface(picture);
}

// Add vSpeed to whatever the y coord is (going down increases coord)
void Paddle::moveUp()
{
    rect.y -= paddleSpeed;
}

void Paddle::moveDown()
{
    rect.y += paddleSpeed;
}

void Paddle::display()
{
    SDL_BlitSurface(picture, NULL, SDL_GetVideoSurface(), &rect);
}
