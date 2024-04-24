#include "GameManager.h"

void GameManager::Init()
{
	car.mX = 860;
	car.mY = 624;
}

void GameManager::Update(float deltaTime)
{
	car.Update(deltaTime);

    //int carRow = floorf(car.mY / environment.mTileSize);
    //int carColumn = floorf(car.mX / environment.mTileSize);

    //bool hasCollided = false;
    //for (int offsetRow = -1; offsetRow <= 1; offsetRow++)
    //{
    //    for (int offsetColumn = -1; offsetColumn <= 1; offsetColumn++)
    //    {
    //        //check if car is on same pos as brick and check the 8 around it
    //        if (carRow + offsetRow < environment.mTilesX && carColumn + offsetColumn < environment.mTilesY
    //            && carRow + offsetRow >= 0 && carColumn + offsetColumn >= 0)
    //        {
    //            Brick& brick = bricks[ballRow + offsetRow][ballColumn + offsetColumn];

    //            //if brick is already destroyed, pass
    //            if (brick.isDestroyed)
    //            {
    //                continue;
    //            }

    //            //if brick isn't destroy, destroy it
    //            if (Collision(brick.brickRec, ball.ballRec))
    //            {
    //                ball.BounceOnBrick();
    //                hasCollided = true;
    //                brick.isDestroyed = true;

    //                brickCount--;
    //                score += 10;

    //                if (scoreThreshold <= score && life < maxLife)
    //                {
    //                    life += 1;
    //                    scoreThreshold += bonusScore;
    //                }

    //                //check if every brick has been destroy
    //                if (brickCount <= 0)
    //                {
    //                    if (endOfGame)
    //                    {
    //                        EndOfGame();
    //                        return true;
    //                    }

    //                    startRowBricks += 3;
    //                    Init();
    //                }

    //                break;
    //            }
    //        }
    //    }

    //    if (hasCollided) break;
    //}
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
