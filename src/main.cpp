#include "raylib.h"
#include "rcamera.h"
#include "grid.h"
#include"blocks.cpp"

int main() {
    Color darkBlue = {44,44,127,255};
    InitWindow(300,600, "Raylib Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();

    
    grid.Print();

    LBlock lBlock = LBlock();
    

    while (WindowShouldClose() == false)
    {
        
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        lBlock.Draw();
        EndDrawing();
    }

    CloseWindow();    
}