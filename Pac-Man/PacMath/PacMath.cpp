//
//  PacMath.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 07/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "PacMath.h"

float euclideanDistance(const int x1, const int y1, const int x2, const int y2) {
    return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}


int minimumSurroundingEuclideanToPoint(const int px, const int py, const int ghost_pos_x, const int ghost_pos_y) {
    // Clarification variables
    float minimum = euclideanDistance(0, 0, MAP_WIDTH * BLOCK_WIDTH, MAP_HEIGHT * BLOCK_HEIGHT);
    float aux = 0.0f;
    int direction = NONE;
    int ghost_x = ghost_pos_x / BLOCK_WIDTH;
    int ghost_y = ghost_pos_y / BLOCK_HEIGHT;
    int block_left_x = ghost_x * BLOCK_WIDTH - BLOCK_WIDTH;
    int block_right_x = ghost_x * BLOCK_WIDTH + BLOCK_WIDTH;
    int block_x = ghost_x * BLOCK_WIDTH;
    int block_down_y = ghost_y * BLOCK_HEIGHT + BLOCK_HEIGHT;
    int block_up_y = ghost_y * BLOCK_HEIGHT - BLOCK_HEIGHT;
    int block_y = ghost_y * BLOCK_HEIGHT;
    // Check the 4 sides of the block where the ghost is at;
    // hold the minimum value considering whether the minimum value
    // is at a valid position
    if (tentativePosition(block_left_x, block_y)) {
        aux = euclideanDistance(px, py, block_left_x, block_y);
        if (aux < minimum) {
            minimum = aux;
            direction = LEFT;
        }
    }
    if (tentativePosition(block_right_x, block_y)) {
        aux = euclideanDistance(px, py, block_right_x, block_y);
        if (aux < minimum) {
            minimum = aux;
            direction = RIGHT;
        }
    }
    if (tentativePosition(block_x, block_down_y)) {
        aux = euclideanDistance(px, py, block_x, block_down_y);
        if (aux < minimum) {
            minimum = aux;
            direction = DOWN;
        }
    }
    if (tentativePosition(block_x, block_up_y)) {
        aux = euclideanDistance(px, py, block_x, block_up_y);
        if (aux < minimum) {
            minimum = aux;
            direction = UP;
        }
    }
    
    return direction;
}
