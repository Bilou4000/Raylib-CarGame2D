#include "raylib.h"
#include <iostream>

using namespace std;

//Variable
int screenWidth = 1280;
int screenHeight = 720;

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
    InitWindow(screenWidth, screenHeight, "TouhouEngine");
    SetTargetFPS(60);
}

void Update()
{
    float deltaTime = GetFrameTime();
}

void Draw()
{
    BeginDrawing();
    ClearBackground({ GRAY });
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}