//
//  Character.cpp
//  Pac-Man
//
//  Created by Andrés Caballero Toledo on 06/07/2020.
//  Copyright © 2020 act. All rights reserved.
//

#include "Character.h"

Character::Character() {
    pos_x = 0;
    pos_y = 0;
    vel_x = 0;
    vel_y = 0;
    animation = 0;
    direction = 0;
    currentCharacter = NULL;
}


void Character::move() {
    pos_x += vel_x;
    pos_y += vel_y;
}


void Character::stop() {
    vel_x = 0;
    vel_y = 0;
}


void Character::adjustHorizontal() {
    // Clarification variables
    int character_y = pos_y / BLOCK_HEIGHT;
    // Adjust character depending on the size of its height
    pos_y = character_y * BLOCK_HEIGHT + BLOCK_HEIGHT / 2 - 1;
}


void Character::adjustVertical() {
    // Clarification variables
    int character_x = pos_x / BLOCK_WIDTH;
    // Adjust character depending on the size of its width
    pos_x = character_x * BLOCK_WIDTH + BLOCK_WIDTH / 2 - 1;
}


bool Character::hitWall() {
    // Clarification variables
    int character_y = pos_y / BLOCK_HEIGHT;
    int character_x = pos_x / BLOCK_WIDTH;
    // If the character hits a wall, return true
    if ((direction == LEFT && map[character_y][character_x - 1] > BIG_DOT) ||
        (direction == RIGHT && map[character_y][character_x + 1] > BIG_DOT) ||
        (direction == DOWN && map[character_y + 1][character_x] > BIG_DOT) ||
        (direction == UP && map[character_y - 1][character_x] > BIG_DOT) ||
        (direction == NONE)) {
        return true;
    }
    return false;
}


bool Character::hitIntersection() {
    // Clarification variables
    int character_y = pos_y / BLOCK_HEIGHT;
    int character_x = pos_x / BLOCK_WIDTH;
    // Number of available sides for the character to go in an intersection
    // (must be >= 3 because 2 would mean that the character is in an aisle)
    int sides = 0;
    
    // Run the four sides of the pacman
    for (int i = -1; i < 2; i += 2) {
        if (map[character_y][character_x + i] <= BIG_DOT) {
            ++sides;
        }
        if (map[character_y + i][character_x] <= BIG_DOT) {
            ++sides;
        }
    }
    return (sides >= 3);
}


void Character::draw() {
    currentCharacter->render(pos_x - currentCharacter->getWidth() / 2, pos_y - currentCharacter->getHeight() / 2);
}
