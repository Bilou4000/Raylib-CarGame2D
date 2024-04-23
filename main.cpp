#include "raylib.h"
#include <iostream>

#include "Car.h"
#include "Tile.h"

using namespace std;

//Variable
int screenWidth = 1280;
int screenHeight = 720;

Car car;

//Function
void Load();
void Init();
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

    Init();
}

void Init()
{
    //
}

void Update()
{
    float deltaTime = GetFrameTime();
    car.Update(deltaTime);
}

void Draw()
{
    BeginDrawing();
    ClearBackground({ GRAY });

    car.Draw();

    EndDrawing();
}

void Unload()
{
    CloseWindow();
}