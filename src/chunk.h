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

void AllocateMesh(Mesh* chunkMesh, int faces);

int GetVoxelIndex(int x, int y, int z);

void SetBlock(VoxelChunk* chunk, int position, Color color, bool visible);

void AddBlockToChunk(VoxelChunk* chunk, int position, unsigned int faces);

void BuildChunkMesh(const VoxelChunk* chunk);

bool CoordinateValid(int coordinate);

bool IsBlockInChunkVisible(const VoxelChunk* chunk, int x, int y, int z);

unsigned int GetChunkFaceCount(const VoxelChunk* chunk);

#endif //FROGGY_CHUNK_H
