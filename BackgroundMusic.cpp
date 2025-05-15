//
//  backgroundMusic.cpp
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

#include "backgroundMusic.h"
backgroundMusic::backgroundMusic(): songPath(), currVolume(){}
backgroundMusic::backgroundMusic(const char* path, double volume){
    songPath = path;
    currVolume = volume;
    SDL_AudioInit(songPath);

}
void backgroundMusic::playMusic(double volume){
    currVolume = volume;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_VolumeMusic(currVolume);
    Mix_Music* music = Mix_LoadMUS(songPath);
    Mix_PlayMusic(music, -1);
}