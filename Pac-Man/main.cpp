//
//  main.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "SDLConfig.h"
#include "Controls.h"
#include "Texture.h"
#include "Timer.h"
#include "Map.h"
#include "Pac.h"
#include "Ghost.h"
#include "Common.h"

#include "SDL2/SDL.h"

#include <cstdlib>
#include <string>
#include <sstream>

int main(int argc, const char *argv[]) {
    // Start SDL and initialize window
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        // Load media
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            // Load textures
            if(!loadTextures()) {
                printf("Failed to load textures!\n");
            } else {
                // Game loop flag
                bool quit = false;
                
                // Event handler
                SDL_Event e;
                
                // Application timer
                Timer gameTimer;
                
                // Start counting FPS
                int countedFrames = 0;
                gameTimer.start();
                
                // Timer texture
                Texture FPSTexture;
                
                // In memory text stream
                std::stringstream timeText;
                
                //Set text color as blue
                SDL_Color textColor = {0, 255, 255, 255};
                
                // Pac-Man
                PacMan pacman;
                
                // Ghosts
                Ghost redGhost(RED);
                
                // Game loop
                while (!quit) {
                    // ======= GAME MOVEMENT ======= //
                    // Handle the input
                    move(&e, &quit, &pacman);
                    redGhost.autoMovement(pacman.pos_x, pacman.pos_y);
                    
                    // Calculate and correct FPS
                    float avgFPS = countedFrames / (gameTimer.getTicks() / 1000.f);
                    if (avgFPS > 2000000) {
                        avgFPS = 0;
                    }
                    if (countedFrames > 1000000) { // secure avoiding overflow
                        countedFrames = 0;
                    }
                    
                    // Set text to be rendered
                    timeText.str("");
                    timeText << "FPS: " << avgFPS;
                    
                    // Render Text
                    if (!FPSTexture.loadFromRenderedText(timeText.str().c_str(), textColor)) {
                        printf("Unable to render FPS texture!\n");
                    }
                    
                    // ======= GAME LOGIC ======= //
                    pacman.eat();
                    
                    // ======= GAME DRAWING ======= //
                    // Clear screen
                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);
                    
                    // Map
                    drawMap();
                    
                    // Ghosts
                    redGhost.animate();
                    redGhost.draw();
                    
                    // Pac-Man
                    if (!pacman.isStopped()) {
                        pacman.animate();
                    } else {
                        pacman.stopAnimation();
                    }
                    pacman.draw();

                    // Render FPS counter
                    FPSTexture.render(0, 0);
                    
                    // Update screen
                    SDL_RenderPresent(gRenderer);
                    
                    // Update variables
                    ++countedFrames;
                }
            }
        }
    }
    
    // Free resources and close SDL
    close();
    
    return EXIT_SUCCESS;
}
