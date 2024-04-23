#pragma once

#include "raylib.h"

enum class TilesType
{
	GRASS,
	ROAD,
};

struct TileData
{
	Color mColor = LIME;
	float mSpeedMultiplier = 0.5f;
};

