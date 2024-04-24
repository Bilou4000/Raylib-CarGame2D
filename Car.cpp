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

	int tilePosX = floorf((mX / mEnvironment.mTileSize));
	int tilePosY = floorf((mY / mEnvironment.mTileSize));
	//printf( "%d %d\n", tilePosX, tilePosY);

	const TileData* tiledata = mEnvironment.GetTileDataAtPos(tilePosX,tilePosY);

	float speedMultiplier = 1.0f;


	bool hasCollided = false;
	//for (int offsetRow = -1; offsetRow <= 1; offsetRow++)
	//{
	//	for (int offsetColumn = -1; offsetColumn <= 1; offsetColumn++)
	//	{
	//		//check if car is on same pos as brick and check the 8 around it
	//		if (carRow + offsetRow < mEnvironment.mTilesX && carColumn + offsetColumn < mEnvironment.mTilesY
	//			&& carRow + offsetRow >= 0 && carColumn + offsetColumn >= 0)
	//		{
	//			//Brick& brick = bricks[ballRow + offsetRow][ballColumn + offsetColumn];

	//			//if brick is already destroyed, pass
	//			//if (brick.isDestroyed)
	//			//{
	//			//	continue;
	//			//}

	//			////if brick isn't destroy, destroy it
	//			//if (Collision(brick.brickRec, ball.ballRec))
	//			//{
	//			//	ball.BounceOnBrick();
	//			//	hasCollided = true;
	//			//	brick.isDestroyed = true;

	//			//	brickCount--;
	//			//	score += 10;

	//			//	if (scoreThreshold <= score && life < maxLife)
	//			//	{
	//			//		life += 1;
	//			//		scoreThreshold += bonusScore;
	//			//	}

	//			//	//check if every brick has been destroy
	//			//	if (brickCount <= 0)
	//			//	{
	//			//		if (endOfGame)
	//			//		{
	//			//			EndOfGame();
	//			//			return true;
	//			//		}

	//			//		startRowBricks += 3;
	//			//		Init();
	//		}

	//		break;
	//	}
	//}

	if(tiledata != nullptr)
	{
		speedMultiplier = tiledata->mSpeedMultiplier;

		if (tiledata->mIsObstacle)
		{
			int carRow = floorf(mY / mEnvironment.mTileSize);
			int carColumn = floorf(mX / mEnvironment.mTileSize);

		}
	}

	mCurrentSpeedMultiplier = Lerp( mCurrentSpeedMultiplier, speedMultiplier, deltaTime * 10.0f );
	//printf( "%f\n", mCurrentSpeedMultiplier );
	//float speedMultiplier = tiledata != nullptr ? tiledata->mSpeedMultiplier : 1.0f;

	float x = mX + cos(mAngle) * ( mSpeed * mCurrentSpeedMultiplier * deltaTime );
	float y = mY + sin(mAngle) * ( mSpeed * mCurrentSpeedMultiplier * deltaTime );

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

	DrawRectanglePro(rec, origin, mAngle * ( 180 / PI ), WHITE);

}
