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
    animation = PAC_MOUTH;
    direction = RIGHT;
    next_direction = NONE;
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


void PacMan::draw() {
    currentPac->render(pos_x - currentPac->getWidth() / 2, pos_y - currentPac->getHeight() / 2);
}
