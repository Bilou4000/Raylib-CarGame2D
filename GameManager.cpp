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

bool GameManager::Collision(Rectangle a, Rectangle b)
{
    int xMinA = a.x;
    int yMinA = a.y;
    int xMaxA = a.x + a.width;
    int yMaxA = a.y + a.height;

    int xMinB = b.x;
    int yMinB = b.y;
    int xMaxB = b.x + b.width;
    int yMaxB = b.y + b.height;

    return (!(xMinB > xMaxA || yMinB > yMaxA
        || xMaxB < xMinA || yMaxB < yMinA));
}
