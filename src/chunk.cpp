//
// Created by Lake on 21/11/2023.
//

#include "chunk.h"

int GetVoxelIndex(int x, int y, int z){
    return (x * CHUNK_SIZE * CHUNK_SIZE) + (z * CHUNK_SIZE) + y;
}

bool CoordinateValid(int coordinate){
    if (coordinate < 0 || coordinate >= CHUNK_SIZE)
        return false;
    return true;
}

bool IsBlockInChunkVisible(const VoxelChunk* chunk, int x, int y, int z){
    if (CoordinateValid(x))
        return false;
    if (CoordinateValid(z))
        return false;
    if (CoordinateValid(y))
        return false;
    return chunk->BlockVisible[GetVoxelIndex(x, y, z)];
}



unsigned long int GetChunkFaceCount(const VoxelChunk* chunk){
    unsigned int const front = 1 << 0;
    unsigned int const back = 1 << 1;
    unsigned int const top = 1 << 2;
    unsigned int const bottom = 1 << 3;
    unsigned int const left = 1 << 4;
    unsigned int const right = 1 << 5;


    for (int x = 0; x < CHUNK_SIZE; x++){
        for (int z = 0; z < CHUNK_SIZE; z++){
            for (int y = 0; y < CHUNK_SIZE; y++){

                if (!chunk->BlockVisible[GetVoxelIndex(x, y, z)])
                    continue;
                unsigned int faces = 0;



            }
        }
    }
}