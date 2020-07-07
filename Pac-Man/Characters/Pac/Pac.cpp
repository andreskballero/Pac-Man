//
//  Pac.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 01/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Pac.h"

Texture pacman[TOTAL_PAC_ANIMATIONS][TOTAL_DIRECTIONS];


PacMan::PacMan() {
    animation = PAC_MOUTH;
    direction = RIGHT;
    next_direction = NONE;
    currentCharacter = &pacman[animation][direction];
}


bool PacMan::isStopped() {
    return vel_x == 0 && vel_y == 0;
}


void PacMan::animate() {
    if (animation == FRAMES_PER_ANIMATION_PAC * TOTAL_PAC_ANIMATIONS) {
        animation = 0;
    } else {
        currentCharacter = &pacman[animation / FRAMES_PER_ANIMATION_PAC][direction];
        ++animation;
    }
}


void PacMan::stopAnimation() {
    currentCharacter = &pacman[PAC_MOUTH][direction];
}


bool PacMan::nextDirection() {
    // Clarification variables
    int pacman_y = pos_y / BLOCK_HEIGHT;
    int pacman_x = pos_x / BLOCK_WIDTH;
    // If the next direction has been set, check if the pacman can
    // turn to that direction and change the real direction
    if (next_direction == LEFT &&
        map[pacman_y][pacman_x - 1] < BOTTOM_LEFT_CORNER) {
        direction = LEFT;
        vel_x = -2;
        vel_y = 0;
        adjustHorizontal();
    } else if (next_direction == RIGHT &&
               map[pacman_y][pacman_x + 1] < BOTTOM_LEFT_CORNER) {
        direction = RIGHT;
        vel_x = 2;
        vel_y = 0;
        adjustHorizontal();
    } else if (next_direction == DOWN &&
               map[pacman_y + 1][pacman_x] < BOTTOM_LEFT_CORNER) {
        direction = DOWN;
        vel_x = 0;
        vel_y = 2;
        adjustVertical();
    } else if (next_direction == UP &&
               map[pacman_y - 1][pacman_x] < BOTTOM_LEFT_CORNER) {
        direction = UP;
        vel_x = 0;
        vel_y = -2;
        adjustVertical();
    }
    
    if (next_direction == NONE) {
        return false;
    } else {
        return true;
    }
}


void PacMan::eat() {
    // Clarification variables
    int pacman_y = pos_y / BLOCK_HEIGHT;
    int pacman_x = pos_x / BLOCK_WIDTH;
    // If the pacman is on a block DOT or BIG_DOT,
    // eat the dot (set the block to BLANK)
    if (map[pacman_y][pacman_x] == DOT ||
        map[pacman_y][pacman_x] == BIG_DOT) {
        map[pacman_y][pacman_x] = BLANK;
    }
}
