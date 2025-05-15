//
// Created by aaron on 10/30/2024.
//

#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H
#include <SDL.h>
#include <iostream>
#include <SDL_ttf.h>
using namespace std;

const double GRAVITY = 2.5;
const double BOUNCINESS = .8;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int BALL_INITIAL_X = 700;
const int BALL_INITIAL_Y = 550;
// BALL CLASS
class Ball {
public:
    //Description: constructor for Ball class
    //Return: none
    //Precondition: Ball constructor called correctly
    //Postcondition: Ball object exists
    Ball(double xInitialPos, double yInitialPos, double startXVelo, double startYVelo, double r, SDL_Color c);
    //Description: calculates ball physics
    //Return: none
    //Precondition: Ball object exists
    //Postcondition: ball physics calculated
    void Physics(double dT);
    //Description: renders ball to screen
    //Return: none
    //Precondition: Ball object exists
    //Postcondition: ball rendered to screen
    void renderBall (SDL_Renderer* renderer);
    //Description: resets ball to intial x and y
    //Return: none
    //Precondition: Ball object exists
    //Postcondition: ball is reset
    void reset();
    //Description: gets x value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball x is changed
    float getX() const { return x; }
    //Description: gets y value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball y is changed
    float getY() const { return y; }
    //Description: gets y Velocity value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball y Velocity is changed
    float getYVel() const {return yVelocity;}
    //Description: gets x Velocity value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball x Velocity is changed
    float getXVel() const {return xVelocity;}
    //Description: set x value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball x value is changed
    void setX(float tempX){x = tempX;}
    //Description: set y value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball y value is changed
    void setY(float tempY){y = tempY;}
    //Description: sets x velocity value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball x velocity value is changed
    void setXVelo(float tempXVelo){xVelocity = tempXVelo;}
    //Description: sets y velocity value of ball
    //Return: none
    //Precondition: ball object exists
    //Postcondition: ball y velocity value is changed
    void setYVelo(float tempYVelo){yVelocity = tempYVelo;}



    //Description: calculates collision for left triangle
    //Return: none
    //Precondition: triangle object and ball  object exist
    //Postcondition: triangle collision is calculated
    void TriangleCollision1(double dT); //COLLISION FOR TRIANGLE ON LEFT SIDE OF SCREEN
    //Description: calculates collision for right triangle
    //Return: none
    //Precondition: triangle object and ball  object exist
    //Postcondition: triangle collision is calculated
    void TriangleCollision2(double dT); // COLLISION FOR TRIANGLE ON RIGHT SIDE OF SCREEN

private:
    double x, y;
    double xVelocity, yVelocity;
    double radius;
    SDL_Color color;
    SDL_Point a = {0, 550}, c = {200, 750};
    SDL_Point d = {799, 550}, e = {599, 750};
};

//TRIANGLE CLASS
class Triangle {
public:
    //Description: constructor for Triangle class
    //Return: none
    //Precondition: constructor called correctly
    //Postcondition: triangle object created
    Triangle(double xPos, double yPos, double b, double h, SDL_Color c); // TRIANGLE CONSTRUCTOR
    //Description: triangle is rendered to screen
    //Return: none
    //Precondition: triangle object exists
    //Postcondition: triangle is rendered to screen
    void renderTriangle(SDL_Renderer* renderer); //RENDERS STATIC TRIANGLES TO SCREEN
private:
    double base;
    double height;
    double x,y;
    SDL_Color color;
    SDL_Point a = {0, 550}, b = {0, 700}, c = {200, 750};
    SDL_Point d = {799, 550}, e = {599, 750}, f = {799, 700};

};

struct Score {

    int totalScore = 0;
    int lives;
    int level = 1;
    float multiplier;

    //Description: constructor for Score struct
    //Return: none
    //Precondition: Score constructor called correctly
    //Postcondition: Score variable created
    Score(int totalScore, int lives, float multiplier): totalScore(totalScore), lives(lives), multiplier(multiplier){}
    //Description:add Score to score totalScore
    //Return: none
    //Precondition: score variable exists
    //Postcondition: totalScore is increased
    void addScore(int score);
};
//Description: when ball is out of bound pauses game
//Return: none
//Precondition: ball out of bounds
//Postcondition: game is paused until user clicks
void gamePause(bool &userClick, Ball &b1);
//Description: resets game and subtracts life
//Return: none
//Precondition: game is paused
//Postcondition: game is restarted
void handleUserClick(bool &userClick, Ball &b1, Score &score);

//Description: displays game over and score
//Return: none
//Precondition: arguments passed correctly
//Postcondition: game ends
void gameOverScreen(SDL_Renderer* renderer, Score& s, SDL_Event e);

//Description: displays text and number input
//Return: none
//Precondition: arguments passed correctly
//Postcondition: text and number are displayed
void displayScore(int xPos, int yPos, const char* text, int inputNum, SDL_Renderer* rend);
//Description: displays text
//Return: none
//Precondition: arguments passed correctly
//Postcondition: text is displayed
void displayText(int xPos, int yPos, int length, int width, const char* text, SDL_Renderer* renderer, SDL_Color c);


#endif //SDL_FUNCTIONS_H