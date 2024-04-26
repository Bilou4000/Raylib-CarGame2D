#pragma once

#include "raylib.h"
#include "Car.h"
#include "Environment.h"

class GameManager
{
public:
	void Init();
	bool Update(float deltaTime);
	void Draw();

	bool StartRace();
	void DrawStartRace();

	float GetTimer();
	void ResetTimer();

private:
	Environment environment {};
	Car car { environment };

	const int mMaxCountdown = 3;
	const float mTimeOfCountdown = 1.5f;


	float mTimer = 0;
	int mCountdown = mMaxCountdown;
};

