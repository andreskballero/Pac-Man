//
//  Map.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Map.h"

int map[MAP_HEIGHT][MAP_WIDTH];

int testMap[TEST_MAP_HEIGHT][TEST_MAP_WIDTH] = {
    {  5,  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,  6},
    { 15,   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 16},
    { 15,   1,  9, 10,  0,  0,  0,  0,  0,  0,  0,  9, 10,  1, 16},
    { 15,   1, 13, 14,  0,  0,  0,  2,  0,  0,  0, 13, 14,  1, 16},
    { 15,   1, 13, 14,  0,  0,  0,  0,  0,  0,  0, 13, 14,  1, 16},
    { 15,   1, 13, 14,  0,  0,  0,  0,  0,  0,  0, 13, 14,  1, 16},
    { 15,   1, 13, 14,  0,  0,  0,  2,  0,  0,  0, 13, 14,  1, 16},
    { 15,   1,  7,  8,  0,  0,  0,  0,  0,  0,  0,  7,  8,  1, 16},
    { 15,   1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 16},
    {  3,  17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,  4},
};

Texture mapTextures[TOTAL_MAP_BLOCKS];


void drawTestMap() {
    for (int y = 0; y < TEST_MAP_HEIGHT; ++y) {
        for (int x = 0; x < TEST_MAP_WIDTH; ++x) {
            int yx = testMap[y][x];
            mapTextures[yx].render(BLOCK_WIDTH * x, BLOCK_HEIGHT * y);
        }
    }
}
