#include "GameManager.h"

void GameManager::Init()
{
	//initialize car and environment
    car.Init();
    environment.Init();
}

bool GameManager::Update(float deltaTime)
{
	//update timer
	mTimer += GetFrameTime();

	car.Update(deltaTime);

	//if car end game -> end game
	if (car.Update(deltaTime))
	{
		Init();
		return true;
	}

	return false;
}

void GameManager::Draw()
{
	//Draw Car, Environment (tiles) and show timer
	environment.Draw();
	car.Draw();

	DrawText(TextFormat("Time : %.2fs", mTimer), GetScreenWidth() - (MeasureText(TextFormat("Time : %.2fs", mTimer), 50)) - 10, 10, 50, WHITE);
}

float GameManager::GetTimer()
{
	return mTimer;
}

void GameManager::ResetTimer()
{
	mTimer = 0;
}
