//
//  SDLConfig.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef SDLCONFIG_H
#define SDLCONFIG_H

#include "Common.h"

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

// Starts SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Loads the textures
bool loadTextures();

// Frees resources and quits SDL
void close();

#endif
