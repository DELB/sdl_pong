#include <SDL/SDL.h>
#ifndef PADDLE_H
#define PADDLE_H

// Much the same as a ball, but this time just a paddle
class Paddle
{
  SDL_Rect rect;
  SDL_Surface* picture;

  int ySpeed;
  public:
  Paddle(SDL_Surface* bmp, int x, int y, int width, int height, int ySpeed);
  ~Paddle();

  // Gets address of the rectangle above, used for collision detection
  SDL_Rect* getRect();
  // Two functions for moving up and down
  void moveDown();
  void moveUp();

  void display();
};

#endif
