#pragma once

#include "raylib.h"

enum class TilesType
{
	GRASS,
	ROAD,
	OBSTACLE,
	CHECKPOINT,
	FINISHLINE,

	MAX_COUNT,
};

struct TileData
{
	TilesType mTileType = TilesType::GRASS;
	Color mColor = LIME;
	float mSpeedMultiplier = 0.5f;
	bool mIsObstacle = false;
};

