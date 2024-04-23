#include "Car.h"

#include "raylib.h"
#include <iostream>
#include <cmath>

bool playerIsMoving = false;

Car::Car( Environment& environment )
	: mEnvironment( environment )
{
}

void Car::Update(float deltaTime)
{
	if (IsKeyDown(KEY_W))
	{
		playerIsMoving = true;

		if (mSpeed < mMaxSpeed)
		{
			mSpeed += 10;
		}
	}
	else if (IsKeyDown(KEY_S))
	{
		playerIsMoving = true;

		if (mSpeed > -mMaxSpeed)
		{
			mSpeed -= 10;
		}
	}
	else
	{
		playerIsMoving = false; 

		if(mSpeed > 0)
		{
			mSpeed -= 20;
		}
		else if (mSpeed < 0)
		{
			mSpeed += 20;
		}

	}

	if (IsKeyDown(KEY_D) && playerIsMoving)
	{
		mAngle += mVelocity * ( PI / 180.0f ) * deltaTime;
	}

	if (IsKeyDown(KEY_A)&& playerIsMoving)
	{
		mAngle -= mVelocity * ( PI / 180.0f ) * deltaTime;
	}

	int tilePosX = floorf((mX / mEnvironment.mTileSize));
	int tilePosY = floorf((mY / mEnvironment.mTileSize));
	//printf( "%d %d\n", tilePosX, tilePosY);

	const TileData* tiledata = mEnvironment.GetTileDataAtPos(tilePosX,tilePosY);

	float speedMultiplier = 1.0f;
	if(tiledata != nullptr)
	{
		speedMultiplier = tiledata->mSpeedMultiplier;
	}
	//float speedMultiplier = tiledata != nullptr ? tiledata->mSpeedMultiplier : 1.0f;

	float x = mX + cos(mAngle) * ( mSpeed * speedMultiplier * deltaTime );
	float y = mY + sin(mAngle) * ( mSpeed * speedMultiplier * deltaTime );

	mX = x;
	mY = y;

}

void Car::Draw()
{
	Rectangle rec{ mX, mY, mWidth, mHeight};
	Vector2 origin{ mWidth / 1.3f, mHeight / 2 };

	DrawRectanglePro(rec, origin, mAngle * ( 180 / PI ), WHITE);

}
