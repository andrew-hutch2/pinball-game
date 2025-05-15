
Project setup

to run the game the user needs to download SDL, SDL_ttf, and SDL_mixer
next change the file paths in CMakeLists.txt to correspond with
the paths of the on the users computer

change these paths in the CMakeLists.txt file:
set(SDL2_PATH "C:/Users/ahutc/Desktop/sdlDownload/SDL2-2.30.9/x86_64-w64-mingw32")
set(SDL2_MIXER_PATH "C:/SDL LIBRARIES/SDL2_mixer-devel-2.8.0-mingw (1)/SDL2_mixer-2.8.0/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "C:/SDL LIBRARIES/SDL2_ttf-devel-2.22.0-mingw/SDL2_ttf-2.22.0/x86_64-w64-mingw32") #do path
set(SDL2_IMAGE_PATH "C:/SDL LIBRARIES/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/x86_64-w64-mingw32") #do path
to correspond with the x86_64-w64-mingw32 for each library

if user wants to run the game on mac the included libraries may need to be adjusted accordingly
then, the user should be able to run the program correctly