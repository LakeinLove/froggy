//
// Created by Lake on 20/11/2023.
//

#ifndef RAYLIB_TEMPLATE_BLOCK_H
#define RAYLIB_TEMPLATE_BLOCK_H

#include "raylib.h"


struct Block{
    Vector3 position;
    Color face;
    Color wire;
};


void DrawBlock(const Block* block);
void CreateBlock(Block* block, float posX, float posY, float posZ, Color face, Color wire);


#endif //RAYLIB_TEMPLATE_BLOCK_H
