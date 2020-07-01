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
    
    // Pac-Man
    if (!pacman[PAC_CLOSE].loadFromFile("../Assets/pac0.png")) {
        printf("Could not load the pac0 texture.\n");
        success = false;
    }
    if (!pacman[PAC_MOUTH].loadFromFile("../Assets/pac1.png")) {
        printf("Could not load the pac1 texture.\n");
        success = false;
    }
    if (!pacman[PAC_WIDE_MOUTH].loadFromFile("../Assets/pac2.png")) {
        printf("Could not load the pac2 texture.\n");
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
