//
// Created by Andrew Hutcheson on 12/2/2024.
//

#ifndef SDL2_TEST_LTIMER_H
#define SDL2_TEST_LTIMER_H
#include <SDL.h>
class LTimer
{
public:
    //Description: default constructor
    //Return: none
    //Precondition: none
    //Postcondition: LTimer object is created
    LTimer();

    //Description: starts timer
    //Return: none
    //Precondition: timer exists
    //Postcondition: timer is started
    void start();
    //Description: stops timer
    //Return: none
    //Precondition: timer exists
    //Postcondition: timer is stopped
    void stop();
    //Description: pauses timer
    //Return: none
    //Precondition: timer exists
    //Postcondition: timer is paused
    void pause();
    //Description: unpauses timer
    //Return: none
    //Precondition: timer exists
    //Postcondition: timer is unpaused
    void unpause();

    //Description: retrieves time
    //Return: Uint32
    //Precondition: timer exists
    //Postcondition: ticks returned
    Uint32 getTicks();

    //Description: checks if timer is started
    //Return: bool
    //Precondition: timer exists
    //Postcondition: returns true of started
    bool isStarted();
    //Description: checks if timer is paused
    //Return: bool
    //Precondition: timer exists
    //Postcondition: returns true if paused
    bool isPaused();

private:
    Uint32 mStartTicks;
    Uint32 mPausedTicks;
    bool mPaused;
    bool mStarted;
};


#endif //SDL2_TEST_LTIMER_H