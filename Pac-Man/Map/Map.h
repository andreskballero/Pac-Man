//
//  Map.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef MAP_H
#define MAP_H

#include "Common.h"
#include "Texture.h"
#include "Pac.h"

enum map_textures {
    BLANK,
    DOT,
    BIG_DOT,
    BOTTOM_LEFT_CORNER,
    BOTTOM_RIGHT_CORNER,
    TOP_LEFT_CORNER,
    TOP_RIGHT_CORNER,
    BOTTOM_LEFT_WALL,
    BOTTOM_RIGHT_WALL,
    TOP_LEFT_WALL,
    TOP_RIGHT_WALL,
    BOTTOM_MIDDLE_WALL,
    TOP_MIDDLE_WALL,
    LEFT_MIDDLE_WALL,
    RIGHT_MIDDLE_WALL,
    LEFT_WALL,
    RIGHT_WALL,
    BOTTOM_WALL,
    TOP_WALL,
    TOTAL_MAP_BLOCKS
};

extern int map[MAP_HEIGHT][MAP_WIDTH];

extern int testMap[TEST_MAP_HEIGHT][TEST_MAP_WIDTH];

extern Texture mapTextures[TOTAL_MAP_BLOCKS];

// Checks if the next position of the pacman depending on its velocity is valid
bool tentativePosition(const int next_x, const int next_y, PacMan *pacman);

// Adjusts the pacman to the y-axis
void adjustHorizontal(PacMan *pacman);

// Adjusts the pacman to the x-axis
void adjustVertical(PacMan *pacman);

// Checks if the pacman has hit a wall
bool hitWall(PacMan *pacman);

// Controls whether the pacman has to turn in one direction or the other
bool nextDirection(PacMan *pacman);

void drawMap();

#endif
