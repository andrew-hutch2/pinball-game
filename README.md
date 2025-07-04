# Pinball Game

A modern implementation of a classic pinball game using C++ and SDL2. This project demonstrates advanced game development concepts including physics simulation, collision detection, and real-time game mechanics.

## Features

### Core Gameplay
- Realistic ball physics with gravity and bounce mechanics
- Dual flipper controls (left and right) for ball manipulation
- Score system with lives and level progression
- Multiple levels with increasing difficulty
- Collision detection with triangles and flippers
- Game over screen with final score display

### Technical Features
- Frame rate capped at 160 FPS for smooth gameplay
- Real-time physics calculations
- Dynamic enemy spawning system
- Background music and sound effects
- Responsive controls using keyboard input
- Clean game state management

### Game Elements
- Ball physics with customizable properties (velocity, position, radius)
- Interactive flippers with collision detection
- Triangle obstacles for strategic gameplay
- Enemy system with multiple spawn points
- Score multiplier system
- Lives system with game over conditions

## Technologies Used

### Core Technologies
- C++ (Modern C++ features and OOP principles)
- SDL2 (Simple DirectMedia Layer) for graphics and input handling
- SDL_ttf for text rendering
- SDL_mixer for audio management

### Development Tools
- CMake for build system management
- CLion IDE for development
- Version control with Git

### Key Skills Demonstrated
1. Game Physics Implementation
   - Gravity simulation
   - Collision detection
   - Bounce mechanics
   - Velocity calculations

2. Object-Oriented Programming
   - Class hierarchy design
   - Encapsulation

3. Game Development
   - Game loop implementation
   - State management
   - Event handling
   - Frame rate control

4. Graphics Programming
   - SDL2 rendering
   - Texture management
   - Real-time graphics updates
   - Screen management

5. Audio Programming
   - Background music implementation
   - Sound effect management
   - Audio state control

## Project Structure
- `main.cpp`: Core game loop and initialization
- `SDL_Functions.h/cpp`: Core game mechanics and rendering
- `Flipper.h/cpp`: Flipper mechanics and collision
- `Enemies.h/cpp`: Enemy system implementation
- `Ltimer.h/cpp`: Frame rate and timing management
- `BackgroundMusic.h/cpp`: Audio system
- `SoundEffect.h/cpp`: Sound effect management
- `Assets/`: Game resources (images, sounds)

## Building and Running
1. Ensure you have CMake and a C++ compiler installed
2. Clone the repository
3. Create a build directory: `mkdir build && cd build`
4. Run CMake: `cmake ..`
5. Build the project: `cmake --build .`
6. Run the executable

## Controls
- Space: Drop ball
- A: Control left flipper
- D: Control right flipper
- Mouse Click: Alternative way to drop ball

## Game Rules
1. Start with 10 lives
2. Score points by hitting enemies and obstacles
3. Progress through levels by eliminating all enemies
4. Game ends when all lives are lost
5. Higher levels introduce more challenging enemy patterns
