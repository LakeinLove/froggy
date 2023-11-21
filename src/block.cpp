//
// Created by Lake on 20/11/2023.
//


#include "block.h"
#include "raymath.h"

void CreateBlock(Block* block, float posX, float posY, float posZ, Color face, Color wire){
    block->position = (Vector3){posX, posY, posZ};
    block->face = face;
    block->wire = wire;
}

void DrawBlock(const Block* block){
    Vector3 actualPosition = Vector3Add(block->position, (Vector3){0.5, 0.5, 0.5});
    DrawCube(actualPosition, 1.0, 1.0, 1.0, block->face);
    DrawCubeWires(actualPosition, 1.0, 1.0, 1.0, block->wire);
}