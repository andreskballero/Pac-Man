//
//  Common.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef COMMON_H
#define COMMON_H

#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"

// Screen dimension constants
extern const float ASPECT_RATIO;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

// The window we will be rendering to
extern SDL_Window *gWindow;

// The window renderer
extern SDL_Renderer *gRenderer;

// Globally used font
extern TTF_Font *gFont;

#endif
