#include "Tile.h"

Tile::Tile(TilesType type)
{
	mType = type;
}

Tile::Tile(float X, float Y, float size, TilesType type)
{
	mX = X;
	mY = Y;
	mSize = size;
	mType = type;
}

void Tile::Draw()
{
	DrawRectangle(mX, mY, mSize, mSize, mColor);

	//Tile* map[10][10];
	//for (int x = 0; x < 10; x++)
	//{
	//	for (int y = 0; y < 10; y++)
	//	{
	//		map[x][y] = new Tile(( x * mSize ), ( y * mSize ), mSize);
	//		DrawRectangle(mX, mY, mSize, mSize, mColor);
	//	}
	//}
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
