#include "Tile.h"

Tile::Tile(TilesType type)
{
	mType = type;
}

void Tile::GetColor()
{
	if (mType == GRASS)
	{
		mColor = LIME;
	}
	else if (mType == ROAD)
	{
		mColor = DARKGRAY;
	}
}

void Tile::GetSpeed()
{
	if (mType == GRASS)
	{
		mSpeedMultiplier = 0.5f;
	}
	else if (mType == ROAD)
	{
		mSpeedMultiplier = 1.0f;
	}
}
