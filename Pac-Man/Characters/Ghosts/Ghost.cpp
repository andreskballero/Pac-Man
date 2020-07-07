//
//  Ghost.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 05/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Ghost.h"

Texture ghosts[TOTAL_GHOSTS][TOTAL_GHOST_ANIMATIONS][TOTAL_DIRECTIONS];


Ghost::Ghost(int g_id) {
    ghost_id = g_id;
    animation = ANIMATION_0;
    direction = NONE;
    currentCharacter = &ghosts[ghost_id][animation][direction];
}


void Ghost::autoMovement() {
    // Check the euclidean distance of the surrounding blocks
    // and move accordingly to the minimum one
    switch (minimumSurroundingEuclideanToPoint(0, 0, pos_x, pos_y)) {
        case LEFT:
            vel_y = 0;
            vel_x = -2;
            direction = LEFT;
            break;
        case RIGHT:
            vel_y = 0;
            vel_x = 2;
            direction = RIGHT;
            break;
        case DOWN:
            vel_y = 2;
            vel_x = 0;
            direction = DOWN;
            break;
        case UP:
            vel_y = -2;
            vel_x = 0;
            direction = UP;
            break;
        default:
            vel_y = 0;
            vel_x = 0;
            direction = NONE;
            break;
    }
    
    // Move the ghost
    move();
}


void Ghost::animate() {
    if (animation == FRAMES_PER_ANIMATION_GHOST * TOTAL_GHOST_ANIMATIONS) {
        animation = 0;
    } else {
        currentCharacter = &ghosts[ghost_id][animation / FRAMES_PER_ANIMATION_GHOST][direction];
        ++animation;
    }
}
