//
//  Map.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Map.h"

int map[MAP_HEIGHT][MAP_WIDTH] = {
    { 5,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18,18, 6},
    {15, 1, 1, 1, 1, 1, 1,13,14, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,13,14, 1, 1, 1, 1, 1, 1,16},
    {15, 2, 9,12,12,10, 1,13,14, 1, 9,12,12,12,12,12,12,10, 1,13,14, 1, 9,12,12,10, 2,16},
    {15, 1, 7,11,11, 8, 1, 7, 8, 1, 7,11,11,11,11,11,11, 8, 1, 7, 8, 1, 7,11,11, 8, 1,16},
    {15, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,16},
    {12,12,10, 1, 9,10, 1, 9,12,12,12,10, 1, 9,10, 1, 9,12,12,12,10, 1, 9,10, 1, 9,12,12},
    { 0, 0,14, 1,13,14, 1,13, 0, 0, 0,14, 1,13,14, 1,13, 0, 0, 0,14, 1,13,14, 1,13, 0, 0},
    {11,11, 8, 1,13,14, 1, 7,11,11,11, 8, 1,13,14, 1, 7,11,11,11, 8, 1,13,14, 1, 7,11,11},
    { 0, 0, 0, 1,13,14, 1, 1, 1, 1, 1, 1, 1,13,14, 1, 1, 1, 1, 1, 1, 1,13,14, 1, 0, 0, 0},
    {12,12,10, 1, 9,12,12,12,10, 0, 9,12,12,12,12,12,12,10, 0, 9,12,12,12,10, 1, 9,12,12},
    { 0, 0,14, 1, 7,11,11,11, 8, 0, 7,11,11,11,11,11,11, 8, 0, 7,11,11,11, 8, 1,13, 0, 0},
    { 0, 0,14, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,13, 0, 0},
    { 0, 0,14, 1, 9,12,12,12,10, 0, 9,12,12, 0, 0,12,12,10, 0, 9,12,12,12,10, 1,13, 0, 0},
    { 0, 0,14, 1, 7,11,11,11, 8, 0,13, 0, 0, 0, 0, 0, 0,14, 0, 7,11,11,11, 8, 1,13, 0, 0},
    { 0, 0,14, 1,13,14, 0, 0, 0, 0,13, 0, 0, 0, 0, 0, 0,14, 0, 0, 0, 0,13,14, 1,13, 0, 0},
    { 0, 0,14, 1,13,14, 0, 9,10, 0,13, 0, 0, 0, 0, 0, 0,14, 0, 9,10, 0,13,14, 1,13, 0, 0},
    {11,11, 8, 1, 7, 8, 0,13,14, 0, 7,11,11,11,11,11,11, 8, 0,13,14, 0, 7, 8, 1, 7,11,11},
    { 0, 0, 0, 1, 0, 0, 0,13,14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,13,14, 0, 0, 0, 1, 0, 0, 0},
    {12,12,10, 1, 9,12,12,12,12,12,12,10, 0, 9,10, 0, 9,12,12,12,12,12,12,10, 1, 9,12,12},
    { 0, 0,14, 1, 7,11,11,11,11,11,11, 8, 0,13,14, 0, 7,11,11,11,11,11,11, 8, 1,13, 0, 0},
    { 0, 0,14, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,13,14, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,13, 0, 0},
    { 0, 0,14, 1, 9,12,12,12,10, 1, 9,12,12,12,12,12,12,10, 1, 9,12,12,12,10, 1,13, 0, 0},
    {11,11, 8, 1, 7,11,11,11, 8, 1, 7,11,11,11,11,11,11, 8, 1, 7,11,11,11, 8, 1, 7,11,11},
    {15, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,16},
    {15, 1, 9,12,12,10, 1, 9,12,12,12,10, 1, 9,10, 1, 9,12,12,12,10, 1, 9,12,12,10, 1,16},
    {15, 1,13, 0, 0,14, 1, 7,11,11,11, 8, 1,13,14, 1, 7,11,11,11, 8, 1,13, 0, 0,14, 1,16},
    {15, 1,13, 0, 0,14, 1,13,14, 1, 1, 1, 1,13,14, 1, 1, 1, 1,13,14, 1,13, 0, 0,14, 1,16},
    {15, 2,13, 0, 0,14, 1,13,14, 1, 9,12,12,12,12,12,12,10, 1,13,14, 1,13, 0, 0,14, 2,16},
    {15, 1, 7,11,11, 8, 1, 7, 8, 1, 7,11,11,11,11,11,11, 8, 1, 7, 8, 1, 7,11,11, 8, 1,16},
    {15, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,16},
    { 3,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17, 4},
};

int testMap[TEST_MAP_HEIGHT][TEST_MAP_WIDTH] = {
    {  5, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  6},
    { 15,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 16},
    { 15,  1,  9, 10,  0,  0,  0,  0,  0,  0,  0,  9, 10,  1, 16},
    { 15,  1, 13, 14,  0,  0,  0,  2,  0,  0,  0, 13, 14,  1, 16},
    { 15,  1, 13, 14,  0,  0,  0,  0,  0,  0,  0, 13, 14,  1, 16},
    { 15,  1, 13, 14,  0,  0,  0,  0,  0,  0,  0, 13, 14,  1, 16},
    { 15,  1, 13, 14,  0,  0,  0,  2,  0,  0,  0, 13, 14,  1, 16},
    { 15,  1,  7,  8,  0,  0,  0,  0,  0,  0,  0,  7,  8,  1, 16},
    { 15,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 16},
    {  3, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  4},
};

Texture mapTextures[TOTAL_MAP_BLOCKS];


bool tentativePosition(const int next_x, const int next_y, PacMan *pacman) {
    // Clarification variables
    int next_block_y = next_y / BLOCK_HEIGHT;
    int next_block_x = next_x / BLOCK_WIDTH;    
    // If the pacman goes left/right and is in the middle of y-axis
    // OR
    // pacman goes down/up and is in the middle of the x-axis
    // AND
    // the block of the tentative position is blank, dot or bigdot...
    if (pacman->direction != NONE &&
        (map[next_block_y][next_block_x] == BLANK ||
        map[next_block_y][next_block_x] == DOT ||
        map[next_block_y][next_block_x] == BIG_DOT)) {
        return true;
    }
    
    return false;
}


void adjustHorizontal(PacMan *pacman) {
    // Clarification variables
    int pacman_y = pacman->pos_y / BLOCK_HEIGHT;
    // Adjust depending on the size of the pacman height
    pacman->pos_y = pacman_y * BLOCK_HEIGHT + BLOCK_HEIGHT / 2 - 1;
}


void adjustVertical(PacMan *pacman) {
    // Clarification variables
    int pacman_x = pacman->pos_x / BLOCK_WIDTH;
    // Adjust depending on the size of the pacman width
    pacman->pos_x = pacman_x * BLOCK_WIDTH + BLOCK_WIDTH / 2 - 1;
}


bool hitWall(PacMan *pacman) {
    // Clarification variables
    int pacman_y = pacman->pos_y / BLOCK_HEIGHT;
    int pacman_x = pacman->pos_x / BLOCK_WIDTH;
    // If the pacman has hit a wall, return true
    if ((pacman->direction == LEFT && map[pacman_y][pacman_x - 1] > BIG_DOT) ||
        (pacman->direction == RIGHT && map[pacman_y][pacman_x + 1] > BIG_DOT) ||
        (pacman->direction == DOWN && map[pacman_y + 1][pacman_x] > BIG_DOT) ||
        (pacman->direction == UP && map[pacman_y - 1][pacman_x] > BIG_DOT)) {
        return true;
    }
    return false;
}


bool nextDirection(PacMan *pacman) {
    // Clarification variables
    int pacman_y = pacman->pos_y / BLOCK_HEIGHT;
    int pacman_x = pacman->pos_x / BLOCK_WIDTH;
    // If the next direction has been set, check if the pacman can
    // turn to that direction and change the real direction
    if (pacman->next_direction == LEFT &&
        map[pacman_y][pacman_x - 1] < BOTTOM_LEFT_CORNER) {
        pacman->direction = LEFT;
        pacman->vel_x = -2;
        pacman->vel_y = 0;
        adjustHorizontal(pacman);
    } else if (pacman->next_direction == RIGHT &&
               map[pacman_y][pacman_x + 1] < BOTTOM_LEFT_CORNER) {
        pacman->direction = RIGHT;
        pacman->vel_x = 2;
        pacman->vel_y = 0;
        adjustHorizontal(pacman);
    } else if (pacman->next_direction == DOWN &&
               map[pacman_y + 1][pacman_x] < BOTTOM_LEFT_CORNER) {
        pacman->direction = DOWN;
        pacman->vel_x = 0;
        pacman->vel_y = 2;
        adjustVertical(pacman);
    } else if (pacman->next_direction == UP &&
               map[pacman_y - 1][pacman_x] < BOTTOM_LEFT_CORNER) {
        pacman->direction = UP;
        pacman->vel_x = 0;
        pacman->vel_y = -2;
        adjustVertical(pacman);

    }
    
    if (pacman->next_direction == NONE) {
        return false;
    } else {
        return true;
    }
}


void pacmanEats(PacMan *pacman) {
    // Clarification variables
    int pacman_y = pacman->pos_y / BLOCK_HEIGHT;
    int pacman_x = pacman->pos_x / BLOCK_WIDTH;
    // If the pacman is on a block DOT or BIG_DOT,
    // eat the dot (set the block to BLANK)
    if (map[pacman_y][pacman_x] == DOT ||
        map[pacman_y][pacman_x] == BIG_DOT) {
        map[pacman_y][pacman_x] = BLANK;
    }
}


void drawMap() {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            int yx = map[y][x];
            mapTextures[yx].render((SCREEN_WIDTH / MAP_WIDTH) * x, (SCREEN_HEIGHT / MAP_HEIGHT) * y);
        }
    }
}
