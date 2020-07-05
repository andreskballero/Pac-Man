//
//  Pac.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 01/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef PAC_H
#define PAC_H

#define FRAMES_PER_ANIMATION 3

#include "Common.h"
#include "Texture.h"

enum pac_animation {
    PAC_CLOSE,
    PAC_MOUTH,
    PAC_WIDE_MOUTH,
    TOTAL_PAC_ANIMATIONS
};

enum pac_direction {
    NONE,
    DOWN,
    UP,
    LEFT,
    RIGHT,
    TOTAL_PAC_DIRECTIONS
};

extern Texture pacman[TOTAL_PAC_ANIMATIONS][TOTAL_PAC_DIRECTIONS];

class PacMan {
public:
    PacMan();
    
    void move();
    void stop();
    bool isStopped();
    void animate();
    void stopAnimation();
    void draw();
    
    int pos_x;
    int pos_y;
    int vel_x;
    int vel_y;
    int animation;
    int direction;
    int next_direction;
    int animation_frame;
    Texture *currentPac;
};

#endif
