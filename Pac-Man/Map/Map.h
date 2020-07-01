//
//  Map.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef MAP_H
#define MAP_H

#define MAP_HEIGHT 31
#define MAP_WIDTH 28
#define TEST_MAP_HEIGHT 10
#define TEST_MAP_WIDTH 15
#define BLOCK_HEIGHT 8
#define BLOCK_WIDTH 8

#include "Texture.h"

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

void drawTestMap();

#endif
