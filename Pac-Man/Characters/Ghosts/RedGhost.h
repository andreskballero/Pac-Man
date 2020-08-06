//
//  RedGhost.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 03/08/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef REDGHOST_H
#define REDGHOST_H

#include "Ghost.h"

class RedGhost: public Ghost {
public:
    RedGhost();
    
    void autoMovement(const int x, const int y);
};

#endif
