#include "Environment.h"

Environment::Environment()
{
	mTileGrass.mColor = LIME;
	mTileGrass.mSpeedMultiplier = 0.5f;

	mTileRoad.mColor = DARKGRAY;
	mTileRoad.mSpeedMultiplier = 1.0f;
}

void Environment::Draw()
{
	for (int y = 0; y < mTilesY; y++)
	{
		for (int x = 0; x < mTilesX; x++)
		{
			const TileData* theTile = GetTileDataAtPos(x, y);
			DrawRectangle(x * mTileSize, y * mTileSize, mTileSize, mTileSize, theTile->mColor);
		}
	}
}

const TileData* Environment::GetTileDataAtPos( int x, int y ) const
{
	if(x >= mTilesX || x < 0 || y >= mTilesY || y < 0)
	{
		return nullptr;
	}

	switch ( (TilesType)mTiles[y][x] )
	{
		case TilesType::GRASS:
			return &mTileGrass;
		case TilesType::ROAD:
			return &mTileRoad;
	}

	return nullptr;
}
