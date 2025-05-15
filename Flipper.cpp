//
// Created by Andrew Hutcheson on 11/19/2024.
//
#include "Flipper.h"
#include "SDL_Functions.h"

double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

Flipper::Flipper(SDL_Renderer *renderer, int x, int y, float angle): xPos(x), yPos(y), angle(angle) {
    box = {xPos,yPos,150,20};
    this->angle = angle;
}

void Flipper::renderFlipper(SDL_Renderer *renderer, SDL_Texture* texture, bool invert) {
    //find point of rotation
    SDL_Point center;
    if (invert){
        center.x = 15;
        center.y = box.h / 2;
    }else{
        center.x = box.w - 15;
        center.y = box.h / 2;
    }
    this->isFlipped = invert;
    //decide to flip or not
    SDL_RenderCopyEx(renderer, texture, nullptr, &box, angle, &center, isFlipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}


void Flipper::incrementAngle(){
    isMoving = true;
    if (isFlipped){
        if (angle > -60){
            angle -= 6;
        }
    }else{
        if (angle < 60){
            angle += 6;
        }
    }
}

void Flipper::decrementAngle(){
    isMoving = false;
    if (isFlipped){
        if (angle < 0){
            angle += 6;
        }
    }else{
        if (angle > 0){
            angle -= 6;
        }
    }
}

float Flipper::getAngle() {
    return angle;
}

void Flipper::setAngle(float angle) {
    this->angle = angle;
}

void Flipper::update(){
    if (keydown) {
        incrementAngle();
    } else {
        decrementAngle();
    }
}

void Flipper::collision(SDL_Renderer* renderer, Ball& ball, double dt) {
    //draw collision line
    SDL_Point basePoint;
    SDL_Point endPoint;
    if (isFlipped) {
        basePoint.x = xPos+5;
        basePoint.y = yPos;
        float y = yPos+8 - basePoint.y;
        float x = xPos+box.w - basePoint.x;
        endPoint.x = static_cast<int>((x)*cos(toRadians(angle)) - (y)*sin(toRadians(angle)) + basePoint.x);
        endPoint.y = static_cast<int>((x)*sin(toRadians(angle)) + (y)*cos(toRadians(angle)) + basePoint.y+5);

        //SDL_RenderDrawPoint(renderer, xPos+box.w,yPos+5);
        //SDL_RenderDrawPoint(renderer, xPos+5,yPos);
    }else {
        basePoint.x = xPos+box.w-5;
        basePoint.y = yPos+2;
        float y = yPos+5 - basePoint.y;
        float x = xPos - basePoint.x;
        endPoint.x = static_cast<int>((x)*cos(toRadians(angle)) - (y)*sin(toRadians(angle)) + basePoint.x);
        endPoint.y = static_cast<int>((x)*sin(toRadians(angle)) + (y)*cos(toRadians(angle)) + basePoint.y+10);

        //SDL_RenderDrawPoint(renderer, xPos,yPos+5);
        //SDL_RenderDrawPoint(renderer, xPos+box.w-10,yPos);
    }
    bool collision = false;
    double accuracy = 8;

    double distance2;
    double distance1;
    double lineLength;

    distance2 = sqrt(pow(basePoint.x - ball.getX(), 2) + pow(basePoint.y - ball.getY(), 2));
    distance1 = sqrt(pow(endPoint.x - ball.getX(), 2) + pow(endPoint.y - ball.getY(), 2));
    lineLength = sqrt(pow(basePoint.x - endPoint.x, 2) + pow(basePoint.y - endPoint.y, 2));

    if((distance2 + distance1) <= lineLength + accuracy) {
        collision = true;
    }

    if(collision){
        double speed = sqrt(pow(ball.getXVel(), 2) + pow(ball.getYVel(), 2));

        double newXVel;
        double newYVel;
        if (isFlipped) {
            newXVel = (abs(angle) > 1) ? speed * cos(toRadians(angle+180)) * 2 : ball.getXVel() * BOUNCINESS;
            newYVel = (abs(angle) > 1) ? speed * sin(toRadians(angle+180)) * 2 : ball.getYVel() * BOUNCINESS;
        }else {
            newXVel = (abs(angle) > 1) ? -speed * cos(toRadians(angle+180)) * 2 : ball.getXVel() * BOUNCINESS;
            newYVel = (abs(angle) > 1) ? -speed * sin(toRadians(angle+180)) * 2 : ball.getYVel() * BOUNCINESS;

        }
        // Update ball's velocity
        ball.setXVelo(newXVel);
        ball.setYVelo(-newYVel);

        // Update ball's position
        ball.setX(ball.getX() + ball.getXVel() * dt);
        ball.setY(ball.getY() + ball.getYVel() * dt);
    }
    //SDL_RenderDrawLine(renderer, basePoint.x, basePoint.y, endPoint.x, endPoint.y);
    //SDL_RenderDrawLine()
}