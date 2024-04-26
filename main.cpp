#include "raylib.h"
#include <iostream>

#include "GameManager.h";

using namespace std;

//Variable
int screenWidth = 1280;
int screenHeight = 720;

bool ending = false;
float gameTime = 0;

typedef enum GameScreen { MENU, GAMEPLAY, ENDING } GameScreen;
GameScreen currentScreen;
GameManager gameManager;

//Function
void Load();
void Update();
void Draw();
void Unload();


int main() {

    Load();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    Unload();
    return 0;
}


void Load()
{
    InitWindow(screenWidth, screenHeight, "Racing Car");
    currentScreen = MENU;
    SetTargetFPS(60);

    gameManager.Init();
}

void Update()
{
    float deltaTime = GetFrameTime();

    switch (currentScreen)
    {
        case MENU:
        {
            //StopMusicStream(endMusic);

            //PlayMusicStream(startMusic);
            //UpdateMusicStream(startMusic);

            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = GAMEPLAY;
                //gameManager.SetScoreThreshold();
            }
        }
        break;
        case GAMEPLAY:
        {
            //StopMusicStream(startMusic);
            //StopMusicStream(endMusic);

            //PlayMusicStream(mainMusic);
            //UpdateMusicStream(mainMusic);
            ending = gameManager.Update(deltaTime);
            gameTime = gameManager.GetTimer();

            if (ending)
            {
                currentScreen = ENDING;
            }
        }
        break;
        case ENDING:
        {
            //StopMusicStream(mainMusic);

            //PlayMusicStream(endMusic);
            //UpdateMusicStream(endMusic);

            gameManager.ResetTimer();

            if (IsKeyPressed(KEY_R))
            {
                currentScreen = GAMEPLAY;
            }

            if (IsKeyPressed(KEY_SEMICOLON))
            {
                currentScreen = MENU;
            }
        }
        break;
        default: break;
    }
}

void Draw()
{
    BeginDrawing();
    ClearBackground({ LIGHTGRAY });

    switch (currentScreen)
    {
        case MENU:
        {
            DrawText("Car Game 2D", (GetScreenWidth() / 2) - (MeasureText("Car Game 2D", 100) / 2), GetScreenHeight() / 3, 100, RED);
            DrawText("Press ENTER to PLAY", (GetScreenWidth() / 2) - (MeasureText("Press ENTER to PLAY", 50) / 2), 400, 50, GRAY);
        }
        break;
        case GAMEPLAY:
        {
            //DrawRectangle(0, 900, GetScreenWidth(), 100, { 255, 255, 255, 50 });
            gameManager.Draw();
        }
        break;
        case ENDING:
        {
            DrawText("Race Finished !", (GetScreenWidth() / 2) - (MeasureText("Race Finished !", 150) / 2), 100, 150, RED);

            //DrawText("SCORE", (GetScreenWidth() / 2) - (MeasureText("SCORE", 100) / 2), 300, 100, ORANGE);
            //DrawText(TextFormat("%i", score), (GetScreenWidth() / 2) - (MeasureText(TextFormat("%i", score), 75) / 2), 400, 75, WHITE);

            DrawText("TIME", (GetScreenWidth() / 2) - (MeasureText("TIME", 100) / 2), 300, 100, ORANGE);
            DrawText(TextFormat("%.2fs", gameTime), (GetScreenWidth() / 2) - (MeasureText(TextFormat("%.2fs", gameTime), 75) / 2), 400, 75, BLACK);


            DrawText("Press R to PLAY AGAIN", (GetScreenWidth() / 2) - (MeasureText("Press R to PLAY AGAIN", 40) / 2), 530, 40, GRAY);
            DrawText("Or Press M to go back to MENU", (GetScreenWidth() / 2) - (MeasureText("Or Press M to go back to MENU", 40) / 2), 620, 40, GRAY);
        }
        break;
        default: break;
    }

    EndDrawing();
}

void Unload()
{
    CloseWindow();
}