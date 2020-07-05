//
//  Pac.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 01/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Pac.h"

Texture pacman[TOTAL_PAC_ANIMATIONS][TOTAL_PAC_DIRECTIONS];


PacMan::PacMan() {
    pos_x = 14 * BLOCK_WIDTH + BLOCK_WIDTH / 2 - 1;
    pos_y = 17 * BLOCK_HEIGHT + BLOCK_HEIGHT / 2 - 1;
    vel_x = 0;
    vel_y = 0;
    animation = 0;
    direction = RIGHT;
    next_direction = NONE;
    //animation_frame = 0;
    currentPac = &pacman[animation][direction];
}


void PacMan::move() {
    pos_x += vel_x;
    pos_y += vel_y;
    currentPac = &pacman[animation][direction];
}


void PacMan::stop() {
    vel_x = 0;
    vel_y = 0;
}


bool PacMan::isStopped() {
    return vel_x == 0 && vel_y == 0;
}


void PacMan::animate() {
    currentPac = &pacman[animation / FRAMES_PER_ANIMATION][direction];
    
    if (animation == FRAMES_PER_ANIMATION * (TOTAL_PAC_ANIMATIONS - 1)) {
        animation = 0;
    } else {
        ++animation;
    }
}


void PacMan::stopAnimation() {
    currentPac = &pacman[PAC_MOUTH][direction];
}


void PacMan::draw() {
    currentPac->render(pos_x - currentPac->getWidth() / 2, pos_y - currentPac->getHeight() / 2);
}
