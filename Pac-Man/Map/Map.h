//
//  Map.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef MAP_H
#define MAP_H

#include "Texture.h"

enum num_maps {
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    TOTAL_MAPS
};

extern Texture maps[TOTAL_MAPS];

class Map {
public:
    Map();
    
    void loadMap(int level);
    void draw();
    
    Texture *currentMap;
};

#endif
