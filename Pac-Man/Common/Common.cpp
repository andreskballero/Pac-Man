//
//  Common.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Common.h"

// Screen dimension constants
const float ASPECT_RATIO = 1.0 / 1.0;
const int SCREEN_WIDTH = 8 * 15;
const int SCREEN_HEIGHT = 8 * 10;

// The window we will be rendering to
SDL_Window *gWindow = NULL;

// The window renderer
SDL_Renderer *gRenderer = NULL;

// Globally used font
TTF_Font *gFont = NULL;
