#include<raylib.h>
#include<iostream>
#include "game.h"
#include "colors.h"

double LAST_UPDATED_TIME =0;
double GAME_SPEED = 0.2;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if(currentTime - LAST_UPDATED_TIME >= interval) {
        LAST_UPDATED_TIME = currentTime;
        return true;
    }
    return false;
}

int main() {
    
    InitWindow(530,620, "Raylib Tetris");

    SetTargetFPS(60);

    Font font = LoadFontEx("font/LeagueSpartan-Bold.otf", 64,0,0);
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if(EventTriggered(GAME_SPEED)) {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {385,15}, 35, 2, WHITE);
        DrawTextEx(font, "Next", {385,175}, 35, 2, WHITE);
        if(game.gameOver) {
            DrawTextEx(font, "GAME OVER", {320,450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({330,55,170,60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38,2);

        DrawTextEx(font, scoreText, {385 + (170 - textSize.x) / 2, 65}, 35, 2, WHITE);
        DrawRectangleRounded({330,215,170,180}, 0.3, 6, lightBlue);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();    
}