#include <SDL/SDL.h>
#ifndef BALL_H
#define BALL_H

// Creates a header file that defines the declarations needed for the ball class
class Ball
{
  SDL_Rect rect;
  SDL_Surface* picture;

  int xSpeed, ySpeed;

  bool collided(SDL_Rect* firstRect, SDL_Rect* secondRect);

  public:
  // Constructor
  Ball(SDL_Surface* bmp, int x, int y, int width, int height, int xSpeed, int ySpeed);
  // Deconstructor
  ~Ball();
  void display();
  void movement();
};

#endif
