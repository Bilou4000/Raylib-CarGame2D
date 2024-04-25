#include "Environment.h"

Environment::Environment()
{
	TileData& tileGrass = mTilesData[(int)TilesType::GRASS];
	tileGrass.mColor = LIME;
	tileGrass.mSpeedMultiplier = 0.5f;

	TileData& tileRoad = mTilesData[(int) TilesType::ROAD];
	tileRoad.mColor = DARKGRAY;
	tileRoad.mSpeedMultiplier = 1.0f;

	TileData& tileObstacle = mTilesData[(int) TilesType::OBSTACLE];
	tileObstacle.mColor = DARKGREEN;
	tileObstacle.mIsObstacle = true;

	TileData& tileCheckpoint = mTilesData[(int) TilesType::CHECKPOINT];
	tileCheckpoint.mColor = GRAY;
	tileCheckpoint.mSpeedMultiplier = tileRoad.mSpeedMultiplier;

	TileData& tileFinishLine = mTilesData[(int) TilesType::FINISHLINE];
	tileFinishLine.mColor = WHITE;
	tileFinishLine.mSpeedMultiplier = tileRoad.mSpeedMultiplier;
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

	return &mTilesData[mTiles[y][x]];
}
