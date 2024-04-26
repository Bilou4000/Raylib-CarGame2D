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

	float GetTimer();
	void ResetTimer();

private:
	//Variable
	Environment environment {};
	Car car { environment };

	float mTimer = 0;
};

