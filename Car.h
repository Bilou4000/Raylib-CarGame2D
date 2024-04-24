#pragma once

#include "Environment.h"

class Car
{
public:
	Car(Environment& environment);

	void Update(float deltaTime);
	void Draw();

	float mX = 640;
	float mY = 360;
private:
	float mAngle = 0;

	float mWidth = 60;
	float mHeight = 30;

	float mVelocity = 200;
	float mSpeed = 0;
	float mAccelerationSpeed = 5.0f;
	float mDeccelerationSpeed = 3.0f;
	float mMaxSpeed = 400.0f;

	float mCurrentSpeedMultiplier = 0.0f;

	Environment& mEnvironment;
};

