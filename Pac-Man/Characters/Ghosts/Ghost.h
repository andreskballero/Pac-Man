//
//  Ghost.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 05/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef GHOST_H
#define GHOST_H

#define FRAMES_PER_ANIMATION_GHOST 6

#include "Common.h"
#include "Texture.h"
#include "Map.h"
#include "Character.h"
#include "Pac.h"
#include "PacMath.h"

enum ghosts {
    RED,
    ORANGE,
    PINK,
    BLUE,
    TOTAL_GHOSTS
};

enum ghost_animation {
    ANIMATION_0,
    ANIMATION_1,
    TOTAL_GHOST_ANIMATIONS
};

extern Texture ghosts[TOTAL_GHOSTS][TOTAL_GHOST_ANIMATIONS][TOTAL_DIRECTIONS];

class Ghost: public Character {
public:
    Ghost(int g_id);
    
    void autoMovement(const int x, const int y);
    void animate();
    
    int ghost_id;
};

#endif
