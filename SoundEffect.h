//
//  SoundEffect.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 12/2/24.
//

#ifndef SoundEffect_h
#define SoundEffect_h
#include <iostream>
#include <SDL_mixer.h>
using namespace std;

class soundEffect {
private:
    const char* soundPath;
    int currVolume;
    Mix_Chunk* curChunk;
public:
    //Description: default constructor
    //Return: none
    //Precondition: soundEffect called
    //Postcondition: object created
    soundEffect();
    //Description: constructor with two arguments
    //Return: none
    //Precondition: called correctly
    //Postcondition: object created
    soundEffect(const char* path, double volume);
    //Description: play sound objects sound
    //Return: none
    //Precondition: soundEffect object exists
    //Postcondition: sound is played
    void playSound(double volume);
};


#endif /* SoundEffect_h */