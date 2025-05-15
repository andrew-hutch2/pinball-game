cmake_minimum_required(VERSION 3.29)
project(clion_project1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/Users/ahutc/Desktop/SDL/sdlDownload/SDL2-2.30.9/x86_64-w64-mingw32")
set(SDL2_MIXER_PATH "C:/SDL LIBRARIES/SDL2_mixer-devel-2.8.0-mingw (1)/SDL2_mixer-2.8.0/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "C:/SDL LIBRARIES/SDL2_ttf-devel-2.22.0-mingw/SDL2_ttf-2.22.0/x86_64-w64-mingw32") #do path
set(SDL2_IMAGE_PATH "C:/SDL LIBRARIES/SDL2_image-devel-2.8.2-mingw/SDL2_image-2.8.2/x86_64-w64-mingw32") #do path



find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(clion_project1 main.cpp
        SDL_Functions.h
        SDL_Functions.cpp
        Flipper.h
        Flipper.cpp
        Ltimer.h
        Ltimer.cpp
        Enemies.h
        Enemies.cpp
        BackgroundMusic.cpp
        BackgroundMusic.h
        SoundEffect.h
        SoundEffect.cpp
        main.cpp
)



target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${SDL2_MIXER_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2_TTF_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})
