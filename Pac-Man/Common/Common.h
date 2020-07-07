//
//  Common.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef COMMON_H
#define COMMON_H

#define MAP_HEIGHT 31
#define MAP_WIDTH 28
#define TEST_MAP_HEIGHT 10
#define TEST_MAP_WIDTH 15
#define BLOCK_HEIGHT 8
#define BLOCK_WIDTH 8
#define BLOCK_SIDES 4

#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"

enum directions {
    NONE,
    DOWN,
    UP,
    LEFT,
    RIGHT,
    TOTAL_DIRECTIONS
};

// Screen dimension constants
extern const float ASPECT_RATIO;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;

// The window we will be rendering to
extern SDL_Window *gWindow;

// The window renderer
extern SDL_Renderer *gRenderer;

// Globally used font
extern TTF_Font *gFont;

#endif
