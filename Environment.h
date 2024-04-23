#pragma once

#include "Tile.h"

class Environment
{
public:
	Environment();

	void Draw();

	const TileData* GetTileDataAtPos(int x, int y) const; 

	const float mTileSize = 80.0f;

private:
	static const int mTilesX = 16;
	static const int mTilesY = 10;

	int mTiles[mTilesY][mTilesX]
	{
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	};

	TileData mTileGrass;
	TileData mTileRoad;
};