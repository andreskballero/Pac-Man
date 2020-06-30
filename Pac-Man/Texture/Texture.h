//
//  Texture.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 30/06/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include "Common.h"

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

#include <string>

// Texture class - texture wrapper
class Texture {
public:
    Texture();
    ~Texture();
    
    bool loadFromFile(std::string path);
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
    
    void render(const int x, const int y, SDL_Rect *clip = NULL, float angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void free();
    
    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(Uint8 alpha);
    
    int getWidth();
    int getHeight();
    
private:
    SDL_Texture *mTexture;
    
    int mWidth;
    int mHeight;
};

#endif
