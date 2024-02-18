#include<raylib.h>
#include "game.h"

double LAST_UPDATED_TIME =0;
double GAME_SPEED = 0.02;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if(currentTime - LAST_UPDATED_TIME >= interval) {
        LAST_UPDATED_TIME = currentTime;
        return true;
    }
    return false;
}

int main() {
    Color darkBlue = {44,44,127,255};
    InitWindow(300,600, "Raylib Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if(EventTriggered(GAME_SPEED)) {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();    
}