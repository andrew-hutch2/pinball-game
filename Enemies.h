//
// Created by aaron on 11/19/2024.
//

#ifndef ENEMIES_H
#define ENEMIES_H
#include <SDL.h>
#include "SDL_Functions.h"

class Enemies {

public:
    //Description: constructor for Enemies class
    //Return: none
    //Precondition: Enemies called with correct parameters
    //PostCondition: Enemies object created
    Enemies(double r, double xPos, double yPos, SDL_Color c, int lives);
    //Description: Render Enemy and calculate enemy collision
    //Return: none
    //Precondition: enemy object exists
    //PostCondition: enemy is rendered and collision calculated
    void RenderEnemy(SDL_Renderer* renderer, double dT, Ball& b, Score& s);
    //Description: respawns enemy
    //Return: none
    //Precondition: enemy exists
    //PostCondition: enemy is rerendered to screen
    void respawn(Score &s, int min, int max);
    //Description: sets new enemy xPosition
    //Return: none
    //Precondition: enemy object exists
    //PostCondition: enemy xPosition is updated
    void setXPosition(double xPos);
    //Description: sets new enemy yPosition
    //Return: none
    //Precondition: enemy object exists
    //Postcondition: enemy xPosition is updated
    void setYPosition(double yPos);
    //Description: gets enemy object xPosition
    //Return: double
    //Precondition: enemy object exists
    //Postcondition: xPosition returned
    double getXPosition()const;
    //Description: gets enemy object yPosition
    //Return: double
    //Precondition: enemy object exists
    //Postcondition: yPosition returned
    double getYPostion()const;
    //Description: returns if enemy should be spawned
    //Return: bool
    //Precondition: enemy object exists
    //Postcondition: isSpawned returned
    bool getIsSpawned()const;
    //Description: set is spawned value
    //Return: none
    //Precondition: enemy object exists
    //Postcondition: isSpawned is set to new value
    void setIsSpawned(bool val);

private:
    double radius;
    int lives;
    double xPosition;
    double yPosition;
    SDL_Color color;
    bool isSpawned = true;

};


#endif //ENEMIES_H