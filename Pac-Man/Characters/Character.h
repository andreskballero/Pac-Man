//
//  Character.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 06/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Common.h"
#include "Texture.h"
#include "Map.h"

class Character {
public:
    Character();
    
    void move();
    void stop();
    virtual void animate() = 0;
    void adjustHorizontal();
    void adjustVertical();
    bool hitWall();
    void draw();
    
    int pos_x;
    int pos_y;
    int vel_x;
    int vel_y;
    int animation;
    int direction;
    int next_direction;
    Texture *currentCharacter;
    
};

#endif
