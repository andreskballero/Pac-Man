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

enum ghost_direction {
    NONE_GHOST,
    DOWN_GHOST,
    UP_GHOST,
    SIDE_GHOST,
    TOTAL_GHOST_DIRECTIONS
};

extern Texture ghosts[TOTAL_GHOSTS][TOTAL_GHOST_ANIMATIONS][TOTAL_GHOST_DIRECTIONS];

class Ghost {
public:
    Ghost(int g_id);
    
    void animate();
    void draw();
    
    int pos_x;
    int pos_y;
    int ghost_id;
    int animation;
    int direction;
    Texture *currentGhost;
};

#endif
