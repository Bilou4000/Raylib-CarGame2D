#pragma once

#include "raylib.h"

enum class TilesType
{
	GRASS,
	ROAD,
	OBSTACLE,
};

struct TileData
{
	Color mColor = LIME;
	float mSpeedMultiplier = 0.5f;
	bool mIsObstacle = false;
};

