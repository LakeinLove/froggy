//
// Created by Lake on 21/11/2023.
//

#ifndef FROGGY_CHUNK_H
#define FROGGY_CHUNK_H

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#define CHUNK_SIZE 10


struct VoxelChunk{
    bool isVisible;
    bool BlockVisible[CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE];
    Color BlockColor[CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE];

};

typedef enum{
    BLOCK_FRONT,
    BLOCK_BACK,
    BLOCK_TOP,
    BLOCK_BOTTOM,
    BLOCK_LEFT,
    BLOCK_RIGHT
}BlockFace;

int GetVoxelIndex(int x, int y, int z);

void SetBlock(VoxelChunk* chunk, int position, Color color, int visible);

bool CoordinateValid(int coordinate);

bool IsBlockInChunkVisible(const VoxelChunk* chunk, int x, int y, int z);

unsigned long int GetChunkFaceCount(const VoxelChunk* chunk);

#endif //FROGGY_CHUNK_H
