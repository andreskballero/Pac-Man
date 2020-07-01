//
//  Map.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Map.h"

Texture maps[TOTAL_MAPS];


Map::Map() {
    currentMap = NULL;
}


void Map::loadMap(int level) {
    currentMap = &maps[level];
}


void Map::draw() {
    currentMap->render(0, 0);
}
