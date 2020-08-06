//
//  RedGhost.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 03/08/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "RedGhost.h"


RedGhost::RedGhost() {
    currentCharacter = &ghosts[ghost_id][animation][direction];
    pos_x = BLOCK_WIDTH + currentCharacter->getWidth() / 2;
    pos_y = BLOCK_HEIGHT + currentCharacter->getHeight() / 2;
}


void RedGhost::autoMovement(const int x, const int y) {
    // Obtain a new direction if the ghost has hit a wall or an intersection
    //if (hitWall() || hitIntersection()) {
        // Check the euclidean distance of the surrounding blocks
        // and move accordingly to the minimum one
        switch (minimumSurroundingEuclideanToPoint(x, y, pos_x, pos_y)) {
            case LEFT:
                vel_y = 0;
                vel_x = -1;
                direction = LEFT;
                break;
            case RIGHT:
                vel_y = 0;
                vel_x = 1;
                direction = RIGHT;
                break;
            case DOWN:
                vel_y = 1;
                vel_x = 0;
                direction = DOWN;
                break;
            case UP:
                vel_y = -1;
                vel_x = 0;
                direction = UP;
                break;
            default:
                vel_y = 0;
                vel_x = 0;
                direction = NONE;
                break;
        }
    //}
    
    // Move the ghost
    move();
}
