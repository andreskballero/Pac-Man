//
//  SDLConfig.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "SDLConfig.h"

bool init() {
    // Initialization flag
    bool success = true;
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!\n");
        }
        
        // Create window
        gWindow = SDL_CreateWindow("Pac-Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            // create vsynced renderer for the window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                // Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                
                // Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
                
                // Initialize SDL_ttf
                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }
    return success;
}


bool loadMedia() {
    // Loading success flag
    bool success = true;
    
    gFont = TTF_OpenFont("../Assets/lazy.ttf", 11);
    if (gFont == NULL) {
        printf("Failed to load lazy Font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }
    
    return success;
}


bool loadTextures() {
    bool success = true;
    
    // Map blocks
    if (!mapTextures[BLANK].loadFromFile("../Assets/blank.png")) {
        printf("Could not load the blank texture.\n");
        success = false;
    }
    if (!mapTextures[DOT].loadFromFile("../Assets/dot.png")) {
        printf("Could not load the dot texture.\n");
        success = false;
    }
    if (!mapTextures[BIG_DOT].loadFromFile("../Assets/bigDot.png")) {
        printf("Could not load the bigDot texture.\n");
        success = false;
    }
    if (!mapTextures[BOTTOM_LEFT_CORNER].loadFromFile("../Assets/bottomLeftCorner.png")) {
        printf("Could not load the bottomLeftCorner texture.\n");
        success = false;
    }
    if (!mapTextures[BOTTOM_RIGHT_CORNER].loadFromFile("../Assets/bottomRightCorner.png")) {
        printf("Could not load the bottomRightCorner texture.\n");
        success = false;
    }
    if (!mapTextures[TOP_LEFT_CORNER].loadFromFile("../Assets/topLeftCorner.png")) {
        printf("Could not load the topLeftCorner texture.\n");
        success = false;
    }
    if (!mapTextures[TOP_RIGHT_CORNER].loadFromFile("../Assets/topRightCorner.png")) {
        printf("Could not load the topRightCorner texture.\n");
        success = false;
    }
    if (!mapTextures[BOTTOM_LEFT_WALL].loadFromFile("../Assets/bottomLeftWall.png")) {
        printf("Could not load the bottomLeftWall texture.\n");
        success = false;
    }
    if (!mapTextures[BOTTOM_RIGHT_WALL].loadFromFile("../Assets/bottomRightWall.png")) {
        printf("Could not load the bottomRightWall texture.\n");
        success = false;
    }
    if (!mapTextures[TOP_LEFT_WALL].loadFromFile("../Assets/topLeftWall.png")) {
        printf("Could not load the topLeftWall texture.\n");
        success = false;
    }
    if (!mapTextures[TOP_RIGHT_WALL].loadFromFile("../Assets/topRightWall.png")) {
        printf("Could not load the topRightWall texture.\n");
        success = false;
    }
    if (!mapTextures[BOTTOM_MIDDLE_WALL].loadFromFile("../Assets/bottomMiddleWall.png")) {
        printf("Could not load the bottomMiddleWall texture.\n");
        success = false;
    }
    if (!mapTextures[TOP_MIDDLE_WALL].loadFromFile("../Assets/topMiddleWall.png")) {
        printf("Could not load the topMiddleWall texture.\n");
        success = false;
    }
    if (!mapTextures[LEFT_MIDDLE_WALL].loadFromFile("../Assets/leftMiddleWall.png")) {
        printf("Could not load the leftMiddleWall texture.\n");
        success = false;
    }
    if (!mapTextures[RIGHT_MIDDLE_WALL].loadFromFile("../Assets/rightMiddleWall.png")) {
        printf("Could not load the rightMiddleWall texture.\n");
        success = false;
    }
    if (!mapTextures[LEFT_WALL].loadFromFile("../Assets/leftWall.png")) {
        printf("Could not load the leftWall texture.\n");
        success = false;
    }
    if (!mapTextures[RIGHT_WALL].loadFromFile("../Assets/rightWall.png")) {
        printf("Could not load the rightWall texture.\n");
        success = false;
    }
    if (!mapTextures[BOTTOM_WALL].loadFromFile("../Assets/bottomWall.png")) {
        printf("Could not load the bottomWall texture.\n");
        success = false;
    }
    if (!mapTextures[TOP_WALL].loadFromFile("../Assets/topWall.png")) {
        printf("Could not load the topWall texture.\n");
        success = false;
    }
    if (!mapTextures[DOOR].loadFromFile("../Assets/pacDoor.png")) {
        printf("Could not load the pacDoor texture.\n");
        success = false;
    }
    
    // Pac-Man
    if (!pacman[PAC_CLOSE][DOWN].loadFromFile("../Assets/pac00.png")) {
        printf("Could not load the pac00 texture.\n");
        success = false;
    }
    if (!pacman[PAC_CLOSE][UP].loadFromFile("../Assets/pac00.png")) {
        printf("Could not load the pac00 texture.\n");
        success = false;
    }
    if (!pacman[PAC_CLOSE][LEFT].loadFromFile("../Assets/pac00.png")) {
        printf("Could not load the pac00 texture.\n");
        success = false;
    }
    if (!pacman[PAC_CLOSE][RIGHT].loadFromFile("../Assets/pac00.png")) {
        printf("Could not load the pac00 texture.\n");
        success = false;
    }
    if (!pacman[PAC_MOUTH][DOWN].loadFromFile("../Assets/pac10.png")) {
        printf("Could not load the pac10 texture.\n");
        success = false;
    }
    if (!pacman[PAC_MOUTH][UP].loadFromFile("../Assets/pac11.png")) {
        printf("Could not load the pac11 texture.\n");
        success = false;
    }
    if (!pacman[PAC_MOUTH][LEFT].loadFromFile("../Assets/pac12.png")) {
        printf("Could not load the pac12 texture.\n");
        success = false;
    }
    if (!pacman[PAC_MOUTH][RIGHT].loadFromFile("../Assets/pac13.png")) {
        printf("Could not load the pac13 texture.\n");
        success = false;
    }
    if (!pacman[PAC_WIDE_MOUTH][DOWN].loadFromFile("../Assets/pac20.png")) {
        printf("Could not load the pac20 texture.\n");
        success = false;
    }
    if (!pacman[PAC_WIDE_MOUTH][UP].loadFromFile("../Assets/pac21.png")) {
        printf("Could not load the pac21 texture.\n");
        success = false;
    }
    if (!pacman[PAC_WIDE_MOUTH][LEFT].loadFromFile("../Assets/pac22.png")) {
        printf("Could not load the pac22 texture.\n");
        success = false;
    }
    if (!pacman[PAC_WIDE_MOUTH][RIGHT].loadFromFile("../Assets/pac23.png")) {
        printf("Could not load the pac23 texture.\n");
        success = false;
    }
    
    // Ghosts
    if (!ghosts[RED][ANIMATION_0][DOWN].loadFromFile("../Assets/redGhostDown0.png")) {
        printf("Could not load the redGhostDown0 texture.\n");
        success = false;
    }
    if (!ghosts[RED][ANIMATION_1][DOWN].loadFromFile("../Assets/redGhostDown1.png")) {
        printf("Could not load the redGhostDown1 texture.\n");
        success = false;
    }
    if (!ghosts[RED][ANIMATION_0][UP].loadFromFile("../Assets/redGhostUp0.png")) {
        printf("Could not load the redGhostUp0 texture.\n");
        success = false;
    }
    if (!ghosts[RED][ANIMATION_1][UP].loadFromFile("../Assets/redGhostUp1.png")) {
        printf("Could not load the redGhostUp1 texture.\n");
        success = false;
    }
    if (!ghosts[RED][ANIMATION_0][LEFT].loadFromFile("../Assets/redGhostSide0.png")) {
        printf("Could not load the left redGhostSide0 texture.\n");
        success = false;
    }
    if (!ghosts[RED][ANIMATION_1][LEFT].loadFromFile("../Assets/redGhostSide1.png")) {
        printf("Could not load the left redGhostSide1 texture.\n");
        success = false;
    }
    if (!ghosts[RED][ANIMATION_0][RIGHT].loadFromFile("../Assets/redGhostSide0.png")) {
        printf("Could not load the right redGhostSide0 texture.\n");
        success = false;
    }
    if (!ghosts[RED][ANIMATION_1][RIGHT].loadFromFile("../Assets/redGhostSide1.png")) {
        printf("Could not load the right redGhostSide1 texture.\n");
        success = false;
    }
    
    return success;
}


void close() {
    // Free global font
    TTF_CloseFont(gFont);
    gFont = NULL;
    
    // Destroy renderer and window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gRenderer = NULL;
    gWindow = NULL;
    
    // Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
