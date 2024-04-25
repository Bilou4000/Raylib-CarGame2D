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

	for (int i = 0; i < (int) TilesType::MAX_COUNT; i++)
	{
		TileData& tileData = mTilesData[i];
		tileData.mTileType = (TilesType) i;
	}

	InitCheckpoints();
}

void Environment::InitCheckpoints()
{
	mAllCheckpoints.clear();

	const int checkpointTileID = (int) TilesType::CHECKPOINT;
	const int finishLineTileID = (int) TilesType::FINISHLINE;

	for (int y = 0; y < mTilesY; y++)
	{
		for (int x = 0; x < mTilesX; x++)
		{
			if (mTiles[y][x] == checkpointTileID || mTiles[y][x] == finishLineTileID)
			{
				if (y - 1 >= 0 && (mTiles[y - 1][x] == checkpointTileID || mTiles[y-1][x] == finishLineTileID))
				{ 
					Checkpoint* checkpoint = GetCheckpointAtPos(x, y - 1);
					checkpoint->mArea.height += mTileSize;
				}
				else if (x - 1 >= 0 && (mTiles[y][x - 1] == checkpointTileID || mTiles[y][x - 1] == finishLineTileID))
				{
					Checkpoint* checkpoint = GetCheckpointAtPos(x - 1, y);
					checkpoint->mArea.width += mTileSize;
				}
				else
				{
					Checkpoint newCheckpoint {};
					newCheckpoint.mArea = { x * mTileSize, y * mTileSize, mTileSize, mTileSize };

					if (mTiles[y][x] == finishLineTileID)
					{
						newCheckpoint.mIsFinishLine = true;
					}

					mAllCheckpoints.push_back(newCheckpoint);
				}
			}
		}
	}
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

	//Debug checkpoint
	for (Checkpoint& checkpoint : mAllCheckpoints)
	{
		DrawRectangleLinesEx(checkpoint.mArea, 2.0f, checkpoint.mIsPassed ? GREEN : BLUE);
	}
}

bool Environment::CanPassFinishLine()
{
	for (Checkpoint& checkpoint : mAllCheckpoints)
	{
		if (!checkpoint.mIsFinishLine && !checkpoint.mIsPassed)
		{
			return false;
		}
	}

	return true;
}

Checkpoint* Environment::GetCheckpointAtPos(int tileX, int tileY)
{
	if (tileX >= mTilesX || tileX < 0 || tileY >= mTilesY || tileY < 0)
	{
		return nullptr;
	}

	Vector2 pos { tileX * mTileSize, tileY * mTileSize };
	for (Checkpoint& checkpoint : mAllCheckpoints)
	{
		if (CheckCollisionPointRec(pos, checkpoint.mArea))
		{
			return &checkpoint;
		}
	}

	return nullptr;
}

const TileData* Environment::GetTileDataAtPos(int tileX, int tileY) const
{
	if(tileX >= mTilesX || tileX < 0 || tileY >= mTilesY || tileY < 0)
	{
		return nullptr;
	}

	return &mTilesData[mTiles[tileY][tileX]];
}
