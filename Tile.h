#pragma once

#include "TilesType.h"
#include "raylib.h"

class Tile
{
public:
	Tile(TilesType type);
	Tile(float X, float Y, float size, TilesType type);

	void Draw();

	void GetColor();
	void GetSpeed();

	float mX = 10;
	float mY = 10;
	float mSize = 20;
	TilesType mType = GRASS;

private:
	Color mColor = LIME;
	float mSpeedMultiplier = 0.5f;
};

