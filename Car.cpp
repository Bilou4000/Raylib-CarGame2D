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

	int tilePosX = floorf((mX / mEnvironment.mTileSize));
	int tilePosY = floorf((mY / mEnvironment.mTileSize));
	//printf( "%d %d\n", tilePosX, tilePosY);

	const TileData* tiledata = mEnvironment.GetTileDataAtPos(tilePosX,tilePosY);

	float speedMultiplier = 1.0f;
	if(tiledata != nullptr)
	{
		speedMultiplier = tiledata->mSpeedMultiplier;
	}

	mCurrentSpeedMultiplier = Lerp( mCurrentSpeedMultiplier, speedMultiplier, deltaTime * 10.0f );
	//printf( "%f\n", mCurrentSpeedMultiplier );
	//float speedMultiplier = tiledata != nullptr ? tiledata->mSpeedMultiplier : 1.0f;

	float x = mX + cos(mAngle) * ( mSpeed * mCurrentSpeedMultiplier * deltaTime );
	float y = mY + sin(mAngle) * ( mSpeed * mCurrentSpeedMultiplier * deltaTime );

	mX = x;
	mY = y;

}

void Car::Draw()
{
	Rectangle rec{ mX, mY, mWidth, mHeight};
	Vector2 origin{ mWidth / 1.3f, mHeight / 2 };

	DrawRectanglePro(rec, origin, mAngle * ( 180 / PI ), WHITE);

}
