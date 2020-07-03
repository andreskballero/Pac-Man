//
//  Controls.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef CONTROLS_H
#define CONTROLS_H

#include "Common.h"
#include "Map.h"
#include "Pac.h"

#include "SDL2/SDL.h"

void move(SDL_Event *e, bool *quit, PacMan *pacman);

#endif
