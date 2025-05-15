//
// Created by aaron on 10/30/2024.
//
#include <iostream>
#include <math.h>
#include "SDL_Functions.h"


// BALL CLASS
Ball::Ball(double xInitialPos, double yInitialPos, double startXVelo, double startYVelo, double r, SDL_Color c):
        x(xInitialPos), y(yInitialPos), xVelocity(startXVelo), yVelocity(startYVelo), radius(r), color(c) {}

void Ball::Physics(double dT) {
    yVelocity += GRAVITY / (dT * dT);

    y += yVelocity * dT;
    x += xVelocity * dT;

    //wall collision
    if (x <= radius || x >= SCREEN_WIDTH - radius) {
        xVelocity *= -BOUNCINESS;
        x = (x <= radius) ? radius : SCREEN_WIDTH - radius;
    }
    //only one condition for ceiling because ball needs
    //to fall through floor
    if (y <= radius) {
        yVelocity *= -BOUNCINESS;
        y = (y <= radius) ? radius : SCREEN_HEIGHT - radius;
    }

}

void Ball::renderBall (SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for(int i = 0; i < radius * 2; i++) {
        for(int j = 0; j < radius * 2; j++) {
            int dx = radius - i;
            int dy = radius - j;
            if((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void Ball::reset() {
    x = BALL_INITIAL_X;
    y = BALL_INITIAL_Y;
    yVelocity = 0;
    xVelocity = 0;

}
void Ball::TriangleCollision1(double dT) {  // left triangle
    double distancePointLine1;
    double distancePointLine2;
    double lineLength; // left
    double accuracy = 8;
    bool collision1 = false;
    distancePointLine1 = sqrt(pow(a.x - x, 2) + pow(a.y - y, 2)); // left triangle
    distancePointLine2 = sqrt(pow(c.x - x, 2) + pow(c.y - y, 2));
    lineLength = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));

    if((distancePointLine1 + distancePointLine2) <= lineLength + accuracy) {
        collision1 = true;
    }


    if(collision1){
        /*xVelocity *= BOUNCINESS; //FIX ME ACCURATE X AND Y PHYSICS
        yVelocity *= -BOUNCINESS;
        x += xVelocity * dT;
        y += yVelocity * dT;*/

        double speed = sqrt(pow(xVelocity, 2) + pow(yVelocity, 2));

        // Calculate the new velocity components based on angle
        //0.7853 is the angle of the triangle in radians
        double newXVel = speed * cos(0.7853) * BOUNCINESS;
        double newYVel = speed * sin(0.7853) * BOUNCINESS;

        // Update ball's velocity
        xVelocity = newXVel;
        yVelocity = -newYVel; // Reverse Y velocity to simulate bounce

        // Update ball's position
        x +=  xVelocity * dT;
        y +=  yVelocity * dT;
    }
}

void Ball::TriangleCollision2(double dT) { // right triangle
    double distancePointLine3;
    double distancePointLine4;
    double lineLength2;
    double accuracy = 8;
    bool collision2 = false;

    distancePointLine3 = sqrt(pow(d.x - x, 2) + pow(d.y - y, 2)); // right triangle
    distancePointLine4 = sqrt(pow(e.x - x, 2) + pow(e.y - y, 2));
    lineLength2 = sqrt(pow(d.x - e.x, 2) + pow(d.y - e.y, 2));

    if((distancePointLine3 + distancePointLine4) <= lineLength2 + accuracy) {
        collision2 = true;
    }

    if(collision2) {
        double speed = sqrt(pow(xVelocity, 2) + pow(yVelocity, 2));

        // Calculate the new velocity components based on angle
        //2.35619 is the angle of the triangle in radians
        double newXVel = speed * cos(2.35619) * BOUNCINESS;
        double newYVel = speed * sin(2.35619) * BOUNCINESS;

        // Update ball's velocity
        xVelocity = newXVel;
        yVelocity = -newYVel; // Reverse Y velocity to simulate bounce

        // Update ball's position
        x +=  xVelocity * dT;
        y +=  yVelocity * dT;
    }
}

//TRIANGLE CLASS

Triangle::Triangle(double xPos, double yPos, double b, double h, SDL_Color c):
        x(xPos), y(yPos), base(b), height(h){}

void Triangle::renderTriangle(SDL_Renderer* renderer) {
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
    SDL_RenderDrawLine(renderer, a.x, a.y, c.x, c.y);
    SDL_RenderDrawLine(renderer, c.x, c.y, b.x, b.y);

    SDL_RenderDrawLine(renderer, d.x, d.y, e.x, e.y);
    SDL_RenderDrawLine(renderer, d.x, d.y, f.x, f.y);
    SDL_RenderDrawLine(renderer, f.x, f.y, e.x, e.y);
}

void Score::addScore(int score){
    totalScore += score;
}

void handleUserClick(bool &userClick, Ball &b1, Score &score) {
    score.lives -= 1;
    userClick = !userClick;
    b1.reset();
}

void gamePause(bool &userClick, Ball &b1){
    if (b1.getY() >= SCREEN_HEIGHT + 100) {
        if (userClick == true) {
            userClick = false;
        }
    }
}


void gameOverScreen(SDL_Renderer* renderer, Score& s, SDL_Event e) {
    //clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    bool exit = false;
    while (!exit) {
        //allow user to quit end game screen
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                case SDL_MOUSEBUTTONDOWN:
                case SDL_KEYDOWN:
                    exit = true;
                break;

                default:
                    break;
            }
        }

        displayText(200,350,400,60,"Game Over",renderer, {255,0,0,0});
        displayScore(320,400, "Score ", s.totalScore, renderer);
        SDL_RenderPresent(renderer);
    }
}



void displayScore(int xPos, int yPos, const char* text, int inputNum, SDL_Renderer* rend) {
    //  font shenanigans
    if(TTF_Init() < 0) {
        SDL_Delay(100);
        exit(1);
    }
    TTF_Font* font = TTF_OpenFont("../Assets/Background/ARCADECLASSIC.TTF" ,24);
    if(!font) {
        SDL_Delay(100);
        exit(1);
    }
    SDL_Color White = {255,255,255};
    const char* scoreText = (text + to_string(inputNum)).c_str();
    SDL_Surface* textSurface =  TTF_RenderText_Solid(font, scoreText, White);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(rend, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect textRect = { xPos ,yPos ,150, 40};
    SDL_RenderCopy(rend, textTexture, NULL, &textRect);

}

void displayText(int xPos, int yPos, int length, int width, const char* text, SDL_Renderer* renderer, SDL_Color c) {
    //  font shenanigans
    if(TTF_Init() < 0) {
        SDL_Delay(100);
        exit(1);
    }
    TTF_Font* font = TTF_OpenFont("../Assets/Background/ARCADECLASSIC.TTF" ,20);
    if(!font) {
        SDL_Delay(100);
        exit(1);
    }
    const char* scoreText = text;
    SDL_Surface* textSurface =  TTF_RenderText_Solid(font, scoreText, c);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect textRect = { xPos ,yPos ,length, width};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
}