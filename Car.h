#pragma once

#include "Environment.h"

class Car
{
public:
	Car(Environment& environment);

	void Update(float deltaTime);
	void Draw();

	Vector2 GetHitboxPos(float carPosX, float carPosY, int hitboxIndex);

	float mX = 640;
	float mY = 360;
private:
	const float mWidth = 60;
	const float mHeight = 30;
	const float mHitboxRadius = mHeight / 2;

	const float mVelocity = 200;
	const float mAccelerationSpeed = 5.0f;
	const float mDeccelerationSpeed = 3.0f;
	const float mMaxSpeed = 400.0f;

	float mAngle = 0;
	float mSpeed = 0;
	float mCurrentSpeedMultiplier = 0.0f;

	Environment& mEnvironment;
};

