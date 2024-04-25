#include "Car.h"

#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <cmath>

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
		targetSpeed = mMaxSpeed;
	}
	else if (IsKeyDown(KEY_S))
	{
		targetSpeed = -mMaxSpeed;
	}
	else
	{
		accelerationSpeed = mDeccelerationSpeed;
	}

	mSpeed = Lerp(mSpeed, targetSpeed, deltaTime * accelerationSpeed);

	if (IsKeyDown(KEY_D))
	{
		mAngle += mSpeed / mMaxSpeed * mVelocity * DEG2RAD * deltaTime;
	}

	if (IsKeyDown(KEY_A))
	{
		mAngle -= mSpeed / mMaxSpeed * mVelocity * DEG2RAD * deltaTime;
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
	Vector2 hitboxForwardPos = GetHitboxPos(x, y, 0);
	Vector2 hitboxBackwardPos = GetHitboxPos(x, y, 1);

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


					if (CheckCollisionCircleRec(hitboxForwardPos, mHitboxRadius, tile) || CheckCollisionCircleRec(hitboxBackwardPos, mHitboxRadius, tile))
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

	Vector2 hitboxForwardPos = GetHitboxPos(mX, mY, 0);
	Vector2 hitboxBackwardPos = GetHitboxPos(mX, mY, 1);

	DrawCircleLines(hitboxForwardPos.x, hitboxForwardPos.y, mHitboxRadius, RED);
	DrawCircleLines(hitboxBackwardPos.x, hitboxBackwardPos.y, mHitboxRadius, RED);

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

Vector2 Car::GetHitboxPos(float carPosX, float carPosY, int hitboxIndex)
{
	if (hitboxIndex == 0)
	{
		return { carPosX, carPosY };
	}
	else if (hitboxIndex == 1)
	{
		return { carPosX + cos(mAngle) * (-mHitboxRadius * 2), carPosY + sin(mAngle) * (-mHitboxRadius * 2)};
	}

	return { carPosX, carPosY };
}
