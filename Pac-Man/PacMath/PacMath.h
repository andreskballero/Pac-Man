//
//  PacMath.h
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 07/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#ifndef PACMATH_H
#define PACMATH_H

#include "Common.h"
#include "Map.h"

#include <cmath>

float euclideanDistance(const int x1, const int y1, const int x2, const int y2);

int minimumSurroundingEuclideanToPoint(const int px, const int py, const int ghost_pos_x, const int ghost_pos_y);

#endif
