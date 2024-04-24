#include "raylib.h"
#include <iostream>

#include "GameManager.h";

using namespace std;

//Variable
int screenWidth = 1280;
int screenHeight = 720;

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
    SetTargetFPS(60);

    gameManager.Init();
}

void Update()
{
    float deltaTime = GetFrameTime();
    
    gameManager.Update(deltaTime);
}

void Draw()
{
    BeginDrawing();
    ClearBackground({ GRAY });

    gameManager.Draw();

    EndDrawing();
}

void Unload()
{
    CloseWindow();
}