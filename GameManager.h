#pragma once

#include "raylib.h"
#include "Car.h"
#include "Environment.h"

class GameManager
{
public:
	void Init();
	void Update(float deltaTime);
	void Draw();

	bool Collision(Rectangle a, Rectangle b);
	void EndOfGame();

	int GetScore();
	void ResetScore();
	float GetTimer();
	void ResetTimer();
	void SetScoreThreshold();

private:
	//Variable
	Environment environment {};
	Car car { environment };


	int bonusScore = 400;

	int score = 0;
	float timer = 0;
};

