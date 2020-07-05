//
//  Ghost.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 05/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Ghost.h"

Texture ghosts[TOTAL_GHOSTS][TOTAL_GHOST_ANIMATIONS][TOTAL_GHOST_DIRECTIONS];


Ghost::Ghost(int g_id) {
    pos_x = 13 * BLOCK_WIDTH - BLOCK_WIDTH / 2 - 1;
    pos_y = 15 * BLOCK_HEIGHT - BLOCK_HEIGHT / 2 - 1;
    ghost_id = g_id;
    animation = ANIMATION_0;
    direction = SIDE_GHOST;
    currentGhost = &ghosts[RED][ANIMATION_0][SIDE_GHOST];
}


void Ghost::animate() {
    if (animation == FRAMES_PER_ANIMATION_GHOST * TOTAL_GHOST_ANIMATIONS) {
        animation = 0;
    } else {
        currentGhost = &ghosts[ghost_id][animation / FRAMES_PER_ANIMATION_GHOST][direction];
        ++animation;
    }
}


void Ghost::draw() {
    currentGhost->render(pos_x - currentGhost->getWidth() / 2, pos_y - currentGhost->getHeight() / 2);
}
