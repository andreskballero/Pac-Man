//
//  Controls.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Controls.h"

void move(SDL_Event *e, bool *quit, PacMan *pacman) {
    // Handle events on queue
    while (SDL_PollEvent(e) != 0) {
        if (e->type == SDL_QUIT) {
            *quit = true;
        } else if (e->type == SDL_KEYDOWN) {
            switch (e->key.keysym.sym) {
                case SDLK_DOWN:
                    pacman->next_direction = DOWN;
                    break;
                case SDLK_UP:
                    pacman->next_direction = UP;
                    break;
                case SDLK_LEFT:
                    pacman->next_direction = LEFT;
                    break;
                case SDLK_RIGHT:
                    pacman->next_direction = RIGHT;
                    break;
            }
        }
    }
    
    if (nextDirection(pacman)) {
        // Check if the next position is valid for the pacman to move
        int next_x = pacman->pos_x + pacman->vel_x;
        int next_y = pacman->pos_y + pacman->vel_y;
        if (tentativePosition(next_x, next_y, pacman)) {
            pacman->move();            
        } else {
            if (hitWall(pacman)) {
                pacman->stop();
                pacman->next_direction = NONE_PAC;
            }
        }
    }
}
