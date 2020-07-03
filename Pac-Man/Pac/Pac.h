//
//  Pac.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 01/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef PAC_H
#define PAC_H

#include "Common.h"
#include "Texture.h"

enum pac_animation {
    PAC_CLOSE,
    PAC_MOUTH,
    PAC_WIDE_MOUTH,
    TOTAL_PAC_ANIMATIONS
};

enum pac_rotation {
    DOWN,
    UP,
    LEFT,
    RIGHT,
    TOTAL_PAC_ROTATIONS
};

extern Texture pacman[TOTAL_PAC_ANIMATIONS][TOTAL_PAC_ROTATIONS];

class PacMan {
public:
    PacMan();
    
    void move();
    void draw();
    
    Texture *currentPac;
    int pos_x;
    int pos_y;
    int vel_x;
    int vel_y;
};

#endif
