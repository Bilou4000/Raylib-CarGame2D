#pragma once

#include "TilesType.h"
#include "raylib.h"

class Tile
{
public:
	float mPosX = 10;
	float mPosY = 10;
	TilesType mType = GRASS;

private:
	Color mColor = LIME;
};

