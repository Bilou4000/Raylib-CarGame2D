#pragma once

#include "Environment.h"

class Car
{
public:
	Car(Environment& environment);

	void Update(float deltaTime);
	void Draw();

private:
	float mX = 640;
	float mY = 360;
	float mAngle = 0;

	float mWidth = 80;
	float mHeight = 40;

	float mVelocity = 200;
	float mSpeed = 0;
	float mAccelerationSpeed = 5.0f;
	float mDeccelerationSpeed = 3.0f;
	float mMaxSpeed = 400.0f;

	float mCurrentSpeedMultiplier = 0.0f;

	Environment& mEnvironment;
};

