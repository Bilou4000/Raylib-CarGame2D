#pragma once

class Car
{
public:
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
	float mMaxSpeed = 400;
};

