//
//  Pac.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 01/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef PAC_H
#define PAC_H

#include "Texture.h"

enum pac_animation {
    PAC_CLOSE,
    PAC_MOUTH,
    PAC_WIDE_MOUTH,
    TOTAL_PAC_ANIMATIONS
};

extern Texture pacman[TOTAL_PAC_ANIMATIONS];

#endif
