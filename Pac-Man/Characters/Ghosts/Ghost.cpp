//
//  Ghost.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 05/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Ghost.h"

Texture ghosts[TOTAL_GHOSTS][TOTAL_GHOST_ANIMATIONS][TOTAL_DIRECTIONS];


Ghost::Ghost() {
    
}


Ghost::Ghost(int g_id) {
    ghost_id = g_id;
    animation = ANIMATION_0;
    direction = NONE;
    last_dir = NONE;
    currentCharacter = &ghosts[ghost_id][animation][direction];
    pos_x = 0;
    pos_y = 0;
}


void Ghost::animate() {
    if (animation == FRAMES_PER_ANIMATION_GHOST * TOTAL_GHOST_ANIMATIONS) {
        animation = 0;
    } else {
        currentCharacter = &ghosts[ghost_id][animation / FRAMES_PER_ANIMATION_GHOST][direction];
        ++animation;
    }
}
