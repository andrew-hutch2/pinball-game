
//
//  SoundEffect.cpp
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 12/2/24.
//

#include "SoundEffect.h"

soundEffect::soundEffect(): soundPath(), currVolume(), curChunk(){}
soundEffect::soundEffect(const char* path, double volume){
    soundPath = path;
    currVolume = volume;
    curChunk = 0;
}
void soundEffect::playSound(double volume){
    currVolume = volume;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    curChunk = Mix_LoadWAV(soundPath);
    Mix_VolumeChunk(curChunk, currVolume);
    Mix_PlayChannel(-1, curChunk, 0);

    
}