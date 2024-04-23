#include "raylib.h"
#include <iostream>

#include "Car.h"
#include "Tile.h"

using namespace std;

//Variable
int screenWidth = 1280;
int screenHeight = 720;

Car car;
//Tile grass = Tile(GRASS);
//Tile road = Tile(ROAD);

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
    //grass
    Tile* grass[16][10];
    for (int x = 0; x < 16; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            grass[x][y] = new Tile(( x * 80 ), ( y * 80 ), 80, TilesType::GRASS);
            grass[x][y]->Draw();
        }
    }

    //road
    //Tile* road1{};
    //for (int x = 2; x < 13; x++)
    //{
    //    road1 = new Tile(( x * 80 ), 40, 80, ROAD);
    //    road1->UpdateColor();
    //    road1->UpdateSpeed();
    //    road1->Draw();
    //    //for (int y = 0; y < 2; y++)
    //    //{
    //    //    road1[x][y] = new Tile(( x * 80 ), ( y * 80 ), 80, ROAD);
    //    //    road1[x][y]->GetColor();
    //    //    road1[x][y]->Draw();
    //    //}
    //}
}

void Unload()
{
    CloseWindow();
}