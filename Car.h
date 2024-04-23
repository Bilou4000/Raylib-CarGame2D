#pragma once

class Car
{
public:
	void Update();
	void Draw();

private:
	float mPosX = 10;
	float mPosY = 10;

	float mWidth = 10;
	float mHeight = 5;

	float mVelocitySpeed = 5;
};

