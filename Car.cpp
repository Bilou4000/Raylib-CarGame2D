#include "Car.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <cmath>

bool playerIsMoving = false;


Car::Car( Environment& environment )
	: mEnvironment( environment )
{
}

void Car::Update(float deltaTime)
{
	//Move
	float targetSpeed = 0.0f;
	float accelerationSpeed = mAccelerationSpeed;
	if (IsKeyDown(KEY_W))
	{
		playerIsMoving = true;
		targetSpeed = mMaxSpeed;
	}
	else if (IsKeyDown(KEY_S))
	{
		playerIsMoving = true;
		targetSpeed = -mMaxSpeed;
	}
	else
	{
		playerIsMoving = false; 
		accelerationSpeed = mDeccelerationSpeed;
	}

	mSpeed = Lerp(mSpeed, targetSpeed, deltaTime * accelerationSpeed);

	if (IsKeyDown(KEY_D) && playerIsMoving)
	{
		mAngle += mVelocity * DEG2RAD * deltaTime;
	}

	if (IsKeyDown(KEY_A)&& playerIsMoving)
	{
		mAngle -= mVelocity * DEG2RAD * deltaTime;
	}


	//Get pos of car in environment
	int carRow = floorf(mY / mEnvironment.mTileSize);
	int carColumn = floorf(mX / mEnvironment.mTileSize);

	const TileData* tiledata = mEnvironment.GetTileDataAtPos(carColumn, carRow);

	float speedMultiplier = 1.0f;
	if (tiledata != nullptr)
	{
		speedMultiplier = tiledata->mSpeedMultiplier;
	}

	//MOVE in forward
	mCurrentSpeedMultiplier = Lerp(mCurrentSpeedMultiplier, speedMultiplier, deltaTime * 10.0f);
	//printf( "%f\n", mCurrentSpeedMultiplier );
	//float speedMultiplier = tiledata != nullptr ? tiledata->mSpeedMultiplier : 1.0f;

	float x = mX + cos(mAngle) * (mSpeed * mCurrentSpeedMultiplier * deltaTime);
	float y = mY + sin(mAngle) * (mSpeed * mCurrentSpeedMultiplier * deltaTime);

	//car collide ?
	bool hasCollided = false;
	for (int offsetRow = -1; offsetRow <= 1; offsetRow++)
	{
		for (int offsetColumn = -1; offsetColumn <= 1; offsetColumn++)
		{
			float tilePosX = carColumn + offsetColumn;
			float tilePosY = carRow + offsetRow;

			//check if car is on same pos as tile and check the 8 around it
			if (tilePosY < mEnvironment.mTilesY && tilePosX < mEnvironment.mTilesX
				&& tilePosY >= 0 && tilePosX >= 0)
			{
				const TileData* tiledata = mEnvironment.GetTileDataAtPos(tilePosX, tilePosY);

				if (tiledata != nullptr && tiledata->mIsObstacle)
				{
					Rectangle tile { tilePosX * mEnvironment.mTileSize, tilePosY * mEnvironment.mTileSize,
						mEnvironment.mTileSize, mEnvironment.mTileSize };

					if (CheckCollisionCircleRec({ x, y }, mHeight / 2, tile))
					{
						x = mX;
						y = mY;
						mSpeed = 0;
						hasCollided = true;
						break;
					}
				}
			}
		}
		if (hasCollided)
		{
			break;
		}
	}

	mX = x;
	mY = y;

	//Collision on wall
	if (mY < 0)
	{
		mY = 0;
	}
	if (mX < 0)
	{
		mX = 0;
	}
	if (mX > GetScreenWidth()) 
	{
		mX = GetScreenWidth(); 
	}
	if (mY > GetScreenHeight()) 
	{
		mY = GetScreenHeight(); 
	}

}

void Car::Draw()
{
	Rectangle rec{ mX, mY, mWidth, mHeight};
	Vector2 origin{ mWidth / 1.3f, mHeight / 2 };

	DrawRectanglePro(rec, origin, mAngle * RAD2DEG, WHITE);

	DrawCircleLines(mX, mY, mHeight / 2, RED);

	//DEBUG
	int carRow = floorf(mY / mEnvironment.mTileSize);
	int carColumn = floorf(mX / mEnvironment.mTileSize);

	for (int offsetRow = -1; offsetRow <= 1; offsetRow++)
	{
		for (int offsetColumn = -1; offsetColumn <= 1; offsetColumn++)
		{
			float tilePosX = carColumn + offsetColumn;
			float tilePosY = carRow + offsetRow;

			//check if car is on same pos as tile and check the 8 around it
			if (tilePosY < mEnvironment.mTilesY && tilePosX < mEnvironment.mTilesX
				&& tilePosY >= 0 && tilePosX >= 0)
			{
				const TileData* tiledata = mEnvironment.GetTileDataAtPos(tilePosX, tilePosY);

				if (tiledata != nullptr)
				{
					const float tileSize = mEnvironment.mTileSize;
				
					DrawRectangleLines(tilePosX * tileSize, tilePosY * tileSize, tileSize, tileSize, tiledata->mIsObstacle ? RED : WHITE);
				}
			}
		}
	}
}
