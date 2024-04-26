#include "GameManager.h"

void GameManager::Init()
{
    car.Init();
    environment.Init();
}

bool GameManager::Update(float deltaTime)
{
	mTimer += GetFrameTime();

	car.Update(deltaTime);

	if (car.Update(deltaTime))
	{
		Init();
		return true;
	}

	return false;
}

void GameManager::Draw()
{
	environment.Draw();
	car.Draw();

	DrawText(TextFormat("Time : %.2fs", mTimer), GetScreenWidth() - (MeasureText(TextFormat("Time : %.2fs", mTimer), 50)) - 10, 10, 50, WHITE);
	//DrawText(TextFormat("Lap %i/%i", mRound, mMaxRound), GetScreenWidth() - (MeasureText(TextFormat("Lap %i/%i", mRound, mMaxRound), 50)) - 10, 10, 50, WHITE);
}

float GameManager::GetTimer()
{
	return mTimer;
}

void GameManager::ResetTimer()
{
	mTimer = 0;
}
