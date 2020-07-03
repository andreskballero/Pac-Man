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
                    pacman->vel_y = 2;
                    break;
                case SDLK_UP:
                    pacman->vel_y = -2;
                    break;
                case SDLK_LEFT:
                    pacman->vel_x = -2;
                    break;
                case SDLK_RIGHT:
                    pacman->vel_x = 2;
                    break;
            }
        } else if (e->type == SDL_KEYUP) {
            switch (e->key.keysym.sym) {
                case SDLK_DOWN:
                    pacman->vel_y -= 2;
                    break;
                case SDLK_UP:
                    pacman->vel_y += 2;
                    break;
                case SDLK_LEFT:
                    pacman->vel_x += 2;
                    break;
                case SDLK_RIGHT:
                    pacman->vel_x -= 2;
                    break;
            }
        }
    }
    
    int next_x = pacman->pos_x + pacman->vel_x;
    int next_y = pacman->pos_y + pacman->vel_y;
    if (tentativePosition(next_x, next_y)) {
        pacman->move();
    }
}
