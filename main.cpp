#include "raylib.h"
#include <iostream>

#include "Car.h"
#include "Tile.h"
#include "Environment.h"

using namespace std;

//Variable
int screenWidth = 1280;
int screenHeight = 720;

Environment environment;
Car car( environment );

//Function
void Load();
void Update();
void Draw();
void Unload();

void DrawBackground();


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

    DrawBackground();

    car.Draw();

    EndDrawing();
}

void DrawBackground()
{
    environment.Draw();
}

void Unload()
{
    CloseWindow();
}