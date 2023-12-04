//
// Created by Lake on 21/11/2023.
//

#include "chunk.h"

unsigned int front = 1 << 0;
unsigned int back = 1 << 1;
unsigned int top = 1 << 2;
unsigned int bottom = 1 << 3;
unsigned int left = 1 << 4;
unsigned int right = 1 << 5;

void AllocateMesh(Mesh* chunkMesh, int faces){
    int triangles = faces * 2; // 2 triangles per face
    int vertices = triangles * 3; // 3 vertices per triangle
    chunkMesh->triangleCount = triangles;
    chunkMesh->vertexCount = vertices;

    chunkMesh->vertices = static_cast<float*>(MemAlloc(sizeof(float) * 3 * vertices));
    chunkMesh->normals = static_cast<float*>(MemAlloc(sizeof(float) * 3 * vertices));
    chunkMesh->texcoords = static_cast<float*>(MemAlloc(sizeof(float) * 2 * vertices));
    chunkMesh->colors = nullptr;

    chunkMesh->animNormals = nullptr;
    chunkMesh->animVertices = nullptr;
    chunkMesh->boneIds = nullptr;
    chunkMesh->boneWeights = nullptr;
    chunkMesh->tangents = nullptr;
    chunkMesh->indices = nullptr;
    chunkMesh->texcoords2 = nullptr;
}

int GetVoxelIndex(int x, int y, int z){
    return (x * CHUNK_SIZE * CHUNK_SIZE) + (z * CHUNK_SIZE) + y;
}

void SetBlock(VoxelChunk* chunk, int position, Color color, bool visible){
    chunk->BlockVisible[position] = visible;
    chunk->BlockColor[position].a = color.a;
    chunk->BlockColor[position].r = color.r;
    chunk->BlockColor[position].g = color.g;
    chunk->BlockColor[position].b = color.b;
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

int GetChunkFaceCount(VoxelChunk* chunk){
    int count = 0;
    for (int x = 0; x < CHUNK_SIZE; x++) {
        for (int z = 0; z < CHUNK_SIZE; z++) {
            for (int y = 0; y < CHUNK_SIZE; y++) {
                if (!chunk->BlockVisible[GetVoxelIndex(x, y, z)])
                    continue;

                if (!IsBlockInChunkVisible(chunk, x + 1, y, z))
                    count++;
                if (!IsBlockInChunkVisible(chunk, x - 1, y, z))
                    count++;
                if (!IsBlockInChunkVisible(chunk, x, y, z + 1))
                    count++;
                if (!IsBlockInChunkVisible(chunk, x, y, z-1))
                    count++;
                if (!IsBlockInChunkVisible(chunk, x, y + 1, z))
                    count++;
                if (!IsBlockInChunkVisible(chunk, x, y - 1, z))
                    count++;
            }
        }
    }
    return count;
}



void AddBlockToChunk(VoxelChunk* chunk, int position, unsigned int faces){
    Rectangle uvRect = {0.5f,0,0.75f,1}; // Rectangle texture
    Vector2 UV = {0, 0}; // UVs for mesh vectors
    Vector3 normal = {0, 0, 0}; // Normal for mesh vectors

    if (faces && front){
        normal = {0, 0, 1}; //sets the face as the front face (z = 1)


    }


}

void BuildChunkMesh(const VoxelChunk* chunk, Mesh* mesh){


    for (int x = 0; x < CHUNK_SIZE; x++){
        for (int z = 0; z < CHUNK_SIZE; z++){
            for (int y = 0; y < CHUNK_SIZE; y++){
                if (!chunk->BlockVisible[GetVoxelIndex(x, y, z)])
                    continue;
                unsigned int faces = 0;

                if (!IsBlockInChunkVisible(chunk, x + 1, y, z))
                    faces |= right;
                if (!IsBlockInChunkVisible(chunk, x - 1, y, z))
                    faces |= left;
                if (!IsBlockInChunkVisible(chunk, x, y, z + 1))
                    faces |= front;
                if (!IsBlockInChunkVisible(chunk, x, y, z-1))
                    faces |= back;
                if (!IsBlockInChunkVisible(chunk, x, y + 1, z))
                    faces |= top;
                if (!IsBlockInChunkVisible(chunk, x, y - 1, z))
                    faces |= bottom;

                //This is where a mesh builder needs to go, and take the faces that add it to the mesh
            }
        }
    }
}

