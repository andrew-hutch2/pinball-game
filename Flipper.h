//
// Created by Andrew Hutcheson on 11/19/2024.
//

#ifndef SDL2_TEST_FLIPPER_H
#define SDL2_TEST_FLIPPER_H
#include <SDL.h>
#include "SDL_Functions.h"
#include <cmath>

class Flipper{
private:
    float angle;
    int xPos;
    int yPos;
    SDL_Rect box;
    bool isFlipped = false;
    bool isMoving = false;

public:
    bool keydown = false;
    //Description: constructor for FLipper class
    //Return: none
    //Precondition: Flipper constructor called correctly
    //Postcondition: Flipper Class created
    Flipper(SDL_Renderer *renderer, int x, int y, float angle);
    //Description: Render flipper
    //Return: none
    //Precondition: flipper object exists
    //Postcondition: flipper is rendered to screen
    void renderFlipper(SDL_Renderer* renderer, SDL_Texture* texture, bool invert);
    //Description: increment flipper angle
    //Return: none
    //Precondition: flipper object exists
    //Postcondition: flipper angle incremented
    void incrementAngle();
    //Description: get flipper angle
    //Return: float
    //Precondition: flipper object exists
    //Postcondition: flipper angle returned
    float getAngle();
    //Description: set flipper angle
    //Return: none
    //Precondition: flipper object exists
    //Postcondition: flipper angle changed
    void setAngle(float angle);
    //Description: decrement flipper angle
    //Return: none
    //Precondition: flipper object exists
    //Postcondition: flipper angle decrement
    void decrementAngle();
    //Description: update flipper angle
    //Return: none
    //Precondition: flipper object exists
    //Postcondition: flipper angle is updated on screen
    void update();
    //Description: calculate flipper collision
    //Return: none
    //Precondition: flipper object exists
    //Postcondition: flipper collision calculated
    void collision(SDL_Renderer *renderer, Ball& ball, double dt);
};
#endif //SDL2_TEST_FLIPPER_H