//
//  backgroundMusic.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

#ifndef backgroundMusic_h
#define backgroundMusic_h
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_audio.h>
using namespace std;

class backgroundMusic {
private:
    string songName;
    const char* songPath;
    int currVolume;
public:
    //Description: default constructor
    //Return: none
    //Precondition: constructor called
    //Postcondition: backgroundMusic object is created
    backgroundMusic();
    //Description: constructor with two arguments
    //Return: none
    //Precondition: constructor called
    //Postcondition: backgroundMusic object created
    backgroundMusic(const char* path, double volume);
    //Description: plays background music
    //Return: none
    //Precondition: backgroundMusic object exists
    //Postcondition: music is played
    void playMusic(double volume);
};


#endif /* backgroundMusic_h */