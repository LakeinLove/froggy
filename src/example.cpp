/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "block.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 2100;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "3d view");

    // Define Camera to view world
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};    // Camera Position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};        // Where Camera is Looking
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};            // Camera up vector (Rotation towards target)
    camera.fovy = 45.0f;                                        // Camera FOV Y
    camera.projection = CAMERA_PERSPECTIVE;
    Block blockOne = {0}, blockTwo = {0};
    CreateBlock(&blockOne, 0.0f, 0.0f, 0.0f, GREEN, WHITE);
    CreateBlock(&blockTwo, 4.0f, 0.0f, 4.0f, GREEN, WHITE);



    DisableCursor();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE);

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode3D(camera);


        DrawBlock(&blockOne);
        DrawBlock(&blockTwo);
        DrawGrid(20, 1.0f);

        EndMode3D();

        DrawFPS(10, 10);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

