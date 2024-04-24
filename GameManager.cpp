#include "GameManager.h"

void GameManager::Init()
{
	car.mX = 860;
	car.mY = 624;
}

void GameManager::Update(float deltaTime)
{
	car.Update(deltaTime);
}

void GameManager::Draw()
{
	environment.Draw();
	car.Draw();
}
